// cp3_hw1_hint
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define HANDS 5

// card structure definition
struct card {
    const char *face;  // define pointer face
    const char *suit;  // define pointer suit
    int face_num;
    int suit_num;

};  // end struct card

typedef struct card Card;  // new type name for struct card

// prototypes
void fillDeck(Card *const wDeck, const char *wFace[],
              const char *wSuit[]);
void shuffle(Card *const wDeck);
void deal(const Card *const wDeck, Card *const hand);
void onePair(const Card *const hand, const char *wFace[]);       //對子
void twoPair(const Card *const hand, const char *wFace[]);       //雙對子
void threeOfKind(const Card *const hand, const char *wFace[]);   //三條
void fourOfKind(const Card *const hand, const char *wFace[]);    //四梅
void straightHand(const Card *const hand, const char *wFace[]);  //順子
void flushHand(const Card *const hand, const char *wSuit[]);     //同花

int main(void) {
    Card deck[CARDS];  // define array of Cards
    Card hand[HANDS];

    // initialize array of pointers
    const char *face[] = {"Ace", "Deuce", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten",
                          "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL));  // randomize

    fillDeck(deck, face, suit);  // load the deck with Cards
    shuffle(deck);               // put Cards in random order
    deal(deck, hand);            // deal all 52 Cards
    onePair(hand, face);
    twoPair(hand, face);
    threeOfKind(hand, face);
    fourOfKind(hand, face);
    straightHand(hand, face);
    flushHand(hand, suit);
}  // end main

// place strings into Card structures
void fillDeck(Card *const wDeck, const char *wFace[],
              const char *wSuit[]) {
    size_t i;  // counter

    // loop through wDeck
    for (i = 0; i < CARDS; ++i) {
        wDeck[i].face = wFace[i % FACES];
        wDeck[i].suit = wSuit[i / FACES];
        wDeck[i].face_num = i % FACES;
        wDeck[i].suit_num = i / FACES;
    }  // end for
}  // end function fillDeck

// shuffle cards
void shuffle(Card *const wDeck) {
    size_t i;   // counter
    size_t j;   // variable to hold random value between 0 - 51
    Card temp;  // define temporary structure for swapping Cards

    // loop through wDeck randomly swapping Cards
    for (i = 0; i < CARDS; ++i) {
        j = rand() % CARDS;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }  // end for
}  // end function shuffle

// deal cards
void deal(const Card *const wDeck, Card *const hand) {
    size_t i;  // counter

    // loop through wDeck
    for (i = 0; i < HANDS; ++i) {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
               (i + 1) % 5 ? "  " : "\n");
        hand[i] = wDeck[i];
    }  // end for
}  // end function deal

// determines if there are any pairs in the hand
void onePair(const Card *const hand, const char *wFace[]) {
    // counter that records how many cards of each rank are in the hand
    unsigned int counter[FACES] = {0};

    size_t r, p;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].face_num];
    }

    // print result if there is a pair
    for (p = 0; p < FACES; ++p)
        if (counter[p] == 2)
            printf("The hand contains a pair of %ss.\n", wFace[p]);
}  // end function pair

void twoPair(const Card *const hand, const char *wFace[]) {
    unsigned int counter[FACES] = {0};
    unsigned int pairs = 0;

    size_t r, p, c;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].face_num];
    }

    // count how many pairs u have
    for (p = 0; p < FACES; ++p)
        if (counter[p] == 2) pairs++;

    // print result if u have two pairs
    if (pairs == 2) {
        printf("The hand contains two pairs of ");
        for (p = 0, c = 0; p < FACES; ++p)
            if (counter[p] == 2) {
                if (c++) printf(" and ");
                printf("%ss", wFace[p]);
            }
        printf(".\n");
    }
}

void threeOfKind(const Card *const hand, const char *wFace[]) {
    unsigned int counter[FACES] = {0};

    size_t r, p;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].face_num];
    }

    for (p = 0; p < FACES; p++) {
        if (counter[p] == 3)
            printf("The hand contains a three of a kind of %ss.\n", wFace[p]);
    }
}

void fourOfKind(const Card *const hand, const char *wFace[]) {
    unsigned int counter[FACES] = {0};

    size_t r, p;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].face_num];
    }

    for (p = 0; p < FACES; p++) {
        if (counter[p] == 4)
            printf("The hand contains a four of a kind of %ss.\n", wFace[p]);
    }
}

void straightHand(const Card *const hand, const char *wFace[]) {
    unsigned int counter[FACES] = {0};

    size_t r, p, c;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].face_num];
    }

    for (p = 0, c = 0; p < FACES - 5; p++, c = 0) {
        for (int j = p; j < p + 5; j++) {
            if (counter[j] == 1) {
                c++;
            }
        }
        if (c == 5) {
            printf("The hand contains a straight.\n");
            break;
        }
    }
}

void flushHand(const Card *const hand, const char *wSuit[]) {
    unsigned int counter[4] = {0};

    size_t r, p;  // loop counters

    // record how many cards of each rank are in the hand
    for (r = 0; r < HANDS; ++r) {
        ++counter[hand[r].suit_num];
    }

    for (p = 0; p < 4; p++) {
        if (counter[p] == 5)
            printf("The hand contains a flush of %ss.\n", wSuit[p]);
    }
}