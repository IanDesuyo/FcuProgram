#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TELLERS 10
#define MAX_QUEUE_SIZE 10

typedef struct customer {
    char id[20];            // 客戶 id
    int arrived_at;         // 客戶到達銀行時間
    int service_start;      // 客戶開始服務時間
    int service_time_need;  // 客戶完成業務要花多少時間
    struct customer *next;  // 下一個客戶
} Customer;

typedef struct teller {
    int status;            // status, 0: close, 1:只剩下一位客戶，即將close, 2: open
    Customer *front;       // front pointer，指向第一個element 的index
    Customer *rear;        // rear pointer，指向最後一個element 的下一個index
    int should_change_at;  // 該 teller 應該要在什麼時間點改變statue
    int count;             // queue 中在排隊的人數
} Teller;

int main() {
    FILE *f = fopen("001.tst", "r");
    FILE *fres = fopen("001.res", "w+");

    // initialize tellers
    int teller_count;
    fscanf(f, "%d\n", &teller_count);

    Teller tellers[MAX_TELLERS];

    for (int i = 0; i < MAX_TELLERS; i++) {
        tellers[i].status = (i < teller_count) ? 2 : 0;
        tellers[i].front = NULL;
        tellers[i].rear = NULL;
        tellers[i].count = 0;
        tellers[i].should_change_at = -1;
    }

    printf("CURRENT TELLERS: %d\n", teller_count);

    // temporary variables
    int GLOBAL_CLOCK = 0;
    int target_time = -1;
    // char payload[300];
    char name[100];
    int target_teller = -1;
    int min_teller_count;
    int min_teller_index;
    int is_end = 0;
    int should_read = 1;

    while (1) {
        printf("TICK %d\n", GLOBAL_CLOCK);
        // reset variables
        min_teller_count = 0x7fffffff;
        min_teller_index = 0;
        is_end = 1;

        if (should_read) {
            fscanf(f, "%s %d %d", name, &target_time, &target_teller);
            printf("READ %s %d %d\n", name, target_time, target_teller);
            is_end = 0;

            should_read = 0;
        }

        if (target_time == GLOBAL_CLOCK) {
            should_read = 1;

            if (name[0] == '#') {
                tellers[target_teller].should_change_at = target_time;
                printf("Teller %d should close at %d\n", target_teller, target_time);
            } else if (name[0] == '@') {
                tellers[target_teller].should_change_at = target_time;
                printf("Teller %d should open at %d\n", target_teller, target_time);
            } else {
                // create customer
                Customer *customer = malloc(sizeof(Customer));
                strcpy(customer->id, name);
                customer->service_time_need = target_teller;
                customer->arrived_at = target_time;
                customer->next = NULL;
                customer->service_start = -1;

                // find min teller count and enqueue
                for (int i = 0; i < MAX_TELLERS; i++) {
                    if (tellers[i].status == 2 && tellers[i].count < min_teller_count) {
                        min_teller_count = tellers[i].count;
                        min_teller_index = i;
                    }
                }

                // enqueue to min teller count
                if (tellers[min_teller_index].count == 0) {
                    tellers[min_teller_index].front = customer;
                    tellers[min_teller_index].rear = customer;
                    tellers[min_teller_index].count++;
                } else {
                    tellers[min_teller_index].rear->next = customer;
                    tellers[min_teller_index].rear = customer;
                    tellers[min_teller_index].count++;
                }

                printf("ENQUEUE %s to teller %d, current count %d\n", customer->id, min_teller_index, tellers[min_teller_index].count);
            }
        }

        // TICK
        for (int i = 0; i < MAX_TELLERS; i++) {
            // check if should change status
            if (tellers[i].should_change_at == GLOBAL_CLOCK) {
                if (tellers[i].status == 2) {
                    tellers[i].status = 1;
                    tellers[i].should_change_at = -1;
                    printf("TELLER %d will close after done\n", i);
                } else {
                    tellers[i].status = 2;
                    tellers[i].should_change_at = -1;
                    printf("OPEN TELLER %d\n", i);
                }
            }

            if (tellers[i].status == 1 && tellers[i].count > 1) {
                // ignore first customer
                Customer *customer = tellers[i].front->next;
                Customer *prev = tellers[i].front;

                tellers[i].front->next = NULL;

                while (customer != NULL) {
                    min_teller_count = 0x7fffffff;

                    for (int j = 0; j < MAX_TELLERS; j++) {
                        if (tellers[j].status == 2 && tellers[j].count < min_teller_count) {
                            min_teller_count = tellers[j].count;
                            min_teller_index = j;
                        }
                    }

                    tellers[min_teller_index].rear->next = customer;
                    tellers[min_teller_index].rear = customer;
                    tellers[min_teller_index].count++;
                    printf("MOVE %s from teller %d to teller %d\n", customer->id, i, min_teller_index);

                    prev = customer;
                    customer = customer->next;
                    prev->next = NULL;
                    tellers[i].count--;
                }
            }

            // update customer status
            if (tellers[i].status != 0 && tellers[i].count > 0 && tellers[i].front->arrived_at <= GLOBAL_CLOCK) {
                if (tellers[i].front->service_start == -1) {
                    tellers[i].front->service_start = GLOBAL_CLOCK;
                    printf("START %s at %d\n", tellers[i].front->id, tellers[i].front->service_start);
                } else {
                    tellers[i].front->service_time_need--;
                    printf("TICK %s at %d, need %d\n", tellers[i].front->id, GLOBAL_CLOCK, tellers[i].front->service_time_need);
                }

                if (tellers[i].front->service_time_need == 0) {
                    printf("DEQUEUE %s from teller %d at %d\n", tellers[i].front->id, i, GLOBAL_CLOCK);
                    fprintf(fres, "%s %d %d\n", tellers[i].front->id, GLOBAL_CLOCK, i);
                    tellers[i].front = tellers[i].front->next;
                    tellers[i].count--;

                    if (tellers[i].count == 0) {
                        tellers[i].rear = NULL;
                    }

                    if (tellers[i].status == 1) {
                        tellers[i].status = 0;
                        printf("CLOSE TELLER %d\n", i);
                    }

                    // fix
                    if (tellers[i].count > 0 && tellers[i].status != 0) {
                        tellers[i].front->service_start = GLOBAL_CLOCK;
                        printf("START %s at %d\n", tellers[i].front->id, tellers[i].front->service_start);
                    }
                }
            }

            if (tellers[i].count > 0) {
                is_end = 0;
            }
        }

        if (is_end && !(target_time > GLOBAL_CLOCK)) {
            break;
        }

        for (int i = 0; i < MAX_TELLERS; i++) {
            printf("%d ", tellers[i].count);
        }
        printf("\n");

        GLOBAL_CLOCK++;
    }

    return 0;
}