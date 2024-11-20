#include <stdio.h>
#include <stdlib.h>
int tph, philname[20], status[20], howhung, hu[20], cho;
void one();
void two();
int main() {
    int i;
    printf("\n\nDINING PHILOSOPHER PROBLEM\n");
    printf("Enter the total number of philosophers: ");
    scanf("%d", &tph);
    for(i = 0; i < tph; i++) {
        philname[i] = i + 1;
        status[i] = 1;
    }
    printf("How many philosophers are hungry: ");
    scanf("%d", &howhung);
    if(howhung == tph) {
        printf("\nAll philosophers are hungry..\nDeadlock stage will occur");
        printf("\nExiting\n");
        return 0;
    } else {
        for(i = 0; i < howhung; i++) {
            printf("Enter philosopher %d's position: ", i + 1);
            scanf("%d", &hu[i]);s
            status[hu[i]] = 2;  // Set status to "hungry" (2)
        }
        do {
            printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
            scanf("%d", &cho);
            switch(cho) {
                case 1: one(); break;
                case 2: two(); break;
                case 3: exit(0); break;
                default: printf("\nInvalid option..");
            }
        } while(1);
    }

    return 0;
}
void one() {
    int pos = 0, x, i;
    printf("\nAllow one philosopher to eat at any time\n");
    for(i = 0; i < howhung; i++, pos++) {
        printf("\nP %d is granted permission to eat", philname[hu[pos]]);
        for(x = pos + 1; x < howhung; x++) {
            printf("\nP %d is waiting", philname[hu[x]]);
        }
        printf("\nP %d has finished eating", philname[hu[pos]]);
    }
}
void two() {
    int i, j, s = 0, t, r, x;
    printf("\nAllow two philosophers to eat at the same time\n");
    for(i = 0; i < howhung; i++) {
        for(j = i + 1; j < howhung; j++) {
            if(abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != tph - 1) {
                printf("\n\nCombination %d:\n", ++s);
                t = hu[i];
                r = hu[j];
                printf("P %d and P %d are granted permission to eat\n", philname[t], philname[r]);
                for(x = 0; x < howhung; x++) {
                    if(hu[x] != t && hu[x] != r) {
                        printf("P %d is waiting\n", philname[hu[x]]);
                    }
                }
            }
        }
    }
}
