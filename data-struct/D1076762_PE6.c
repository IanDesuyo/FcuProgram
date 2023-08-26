#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義賣家資料結構
typedef struct sellerdata {
    char id[100];  // 賣家ID
    int price;     // 商品價格
} SellerData;

// 定義商品資料結構
typedef struct bstnode {
    char name[100];              // 商品名稱
    struct sellerdata* sellers;  // 賣家資料
    int sellerCount;             // 賣家數量
    struct bstnode* left;        // 左子節點
    struct bstnode* right;       // 右子節點
} BSTNode;

typedef struct state {
    int insert;
    int search;
    int search_fail;
    int buy;
    int buy_fail;
    int node_num;
    int height;
} State;

BSTNode* createNode() {
    BSTNode* root = malloc(sizeof(BSTNode));
    root->sellers = NULL;
    root->sellerCount = 0;
    root->left = NULL;
    root->right = NULL;

    return root;
}

BSTNode* searchNode(BSTNode* node, char* name) {
    if (node == NULL) {
        return NULL;
    }

    if (strcmp(node->name, name) == 0) {
        return node;
    } else if (strcmp(node->name, name) > 0) {
        return searchNode(node->left, name);
    } else {
        return searchNode(node->right, name);
    }
}

void minHeapify(SellerData* arr, int size, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if (left < size && arr[left].price < arr[smallest].price) {
        smallest = left;
    }

    if (right < size && arr[right].price < arr[smallest].price) {
        smallest = right;
    }

    if (smallest != index) {
        SellerData temp = arr[index];
        arr[index] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, size, smallest);
    }
}

void insertSeller(BSTNode* node, char* sellerId, int price) {
    SellerData* seller = malloc(sizeof(SellerData));
    strcpy(seller->id, sellerId);
    seller->price = price;

    node->sellerCount++;
    node->sellers = realloc(node->sellers, sizeof(SellerData) * node->sellerCount);
    node->sellers[node->sellerCount - 1] = *seller;

    for (int i = node->sellerCount / 2 - 1; i >= 0; i--) {
        minHeapify(node->sellers, node->sellerCount, i);
    }
}

SellerData* popSeller(BSTNode* node) {
    if (node->sellerCount == 0) {
        return NULL;
    }

    SellerData* seller = malloc(sizeof(SellerData));
    *seller = node->sellers[0];

    node->sellerCount--;
    node->sellers[0] = node->sellers[node->sellerCount];
    minHeapify(node->sellers, node->sellerCount, 0);

    return seller;
}

void insertNode(BSTNode* root, BSTNode* node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (strcmp(root->name, node->name) > 0) {
        if (root->left == NULL) {
            root->left = node;
        } else {
            insertNode(root->left, node);
        }
    } else {
        if (root->right == NULL) {
            root->right = node;
        } else {
            insertNode(root->right, node);
        }
    }
}

BSTNode* removeNode(BSTNode* root, BSTNode* node) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(root->name, node->name) > 0) {
        root->left = removeNode(root->left, node);
    } else if (strcmp(root->name, node->name) < 0) {
        root->right = removeNode(root->right, node);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            strcpy(root->name, temp->name);
            root->right = removeNode(root->right, temp);
        }
    }

    return root;
}

void sortNode(BSTNode* node, FILE* f) {
    if (node == NULL) {
        return;
    }

    sortNode(node->left, f);
    fprintf(f, "%s\n", node->name);
    sortNode(node->right, f);
}

int height(BSTNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return left > right ? left + 1 : right + 1;
}

int main() {
    char temp[512];

    printf("Enter the filename: ");
    scanf("%s", temp);

    FILE* f = fopen(temp, "r");

    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char* token;

    State state = {0};
    BSTNode* root = NULL;

    FILE* fsearch = fopen("SearchTable.txt", "w+");
    FILE* fbuy = fopen("BuyTable.txt", "w+");
    FILE* fsort = fopen("SortTable.txt", "w+");
    FILE* flog = fopen("LogTable.txt", "w+");

    while (!feof(f)) {
        fgets(temp, 512, f);
        // remove newline
        if (temp[strlen(temp) - 1] == '\n') {
            temp[strlen(temp) - 1] = '\0';
        }
        token = strtok(temp, " ");
        printf("%s\n", token);

        if (!strcmp(token, "insert")) {
            state.insert++;
            char* name = strtok(NULL, " ");
            char* sellerId = strtok(NULL, " ");
            int price = atoi(strtok(NULL, " "));

            if (root == NULL) {
                root = createNode();
                strcpy(root->name, name);
                state.node_num++;
            }

            BSTNode* node = searchNode(root, name);

            if (node == NULL) {
                node = createNode();
                strcpy(node->name, name);
                insertNode(root, node);
                state.node_num++;
            }

            insertSeller(node, sellerId, price);
            printf("Insert %s %s %d\n", node->name, sellerId, price);
            printf("%s count: %d, low: %d\n", node->name, node->sellerCount, node->sellers[0].price);
            for (int i = 0; i < node->sellerCount; i++) {
                printf("%d ", node->sellers[i].price);
            }
            printf("\n");
        }

        else if (!strcmp(token, "search")) {
            state.search++;
            char* name = strtok(NULL, " ");
            BSTNode* node = searchNode(root, name);

            if (node == NULL) {
                printf("Search %s, count: 0\n", name);
                fprintf(fsearch, "%s Not found\n", name);
                state.search_fail++;
            } else {
                printf("Search %s, count: %d\n", node->name, node->sellerCount);
                fprintf(fsearch, "%s\n", node->name);
                for (int i = 0; i < node->sellerCount; i++) {
                    fprintf(fsearch, "%s %d\n", node->sellers[i].id, node->sellers[i].price);
                }
            }

            fprintf(fsearch, "----------------------------\n");
        }

        else if (!strcmp(token, "buy")) {
            state.buy++;
            char* name = strtok(NULL, " ");
            BSTNode* node = searchNode(root, name);

            if (node == NULL) {
                printf("Buy %s, count: 0\n", name);
                fprintf(fbuy, "%s Not found\n", name);
                state.buy_fail++;
            } else {
                SellerData* seller = popSeller(node);

                printf("Buy %s, count: %d, low: %d\n", node->name, node->sellerCount, node->sellers[0].price);
                fprintf(fbuy, "%s %s %d\n", node->name, seller->id, seller->price);

                if (node->sellerCount == 0) {
                    removeNode(root, node);
                    state.node_num--;
                }
            }
        }

        else if (!strcmp(token, "sort")) {
            sortNode(root, fsort);
            fprintf(fsort, "----------------------------\n");
        }

        else if (!strcmp(token, "report")) {
            state.height = height(root);
            fprintf(flog, "insert %d\n", state.insert);
            fprintf(flog, "search %d %d\n", state.search, state.search_fail);
            fprintf(flog, "buy %d %d\n", state.buy, state.buy_fail);
            fprintf(flog, "node_num %d\n", state.node_num);
            fprintf(flog, "height %d\n", state.height);
            fprintf(flog, "----------------------------\n");
        }
    }

    return 0;
}