#include <stdio.h>

// Global variables.
int combos[1000][5]; // Stores any unique combinations. 1000 arbitrarily picked.
int amt_combos = 0; // Tracks amount of unique combinations so far.

int checkUniqueness(int com[]) {
    for (int i = 0; i < amt_combos; i++) {
        int duplicate = 1; // Assumes that the combo is a duplicate starting out, so that false flags are less likely.
        for (int j = 0; j < 5; j++) {
            if (combos[i][j] != com[j]) {
               duplicate = 0; // If it's not a duplicate of the current combo in the combos array, it sets to 0.
               break; // It still needs to be compared to the rest of the array, though.
            }
        }
        
        if (duplicate == 1) {
            return 0; // If the duplicate var is still 1 at the end of the loop, it's a duplicate. Return 0 (false).
        }
    }
    
    return 1; // If it makes it through the full array without duplicate = 1 being true, it's not a duplicate.
}

void printUniqueCombo(int com[]) {
    if (checkUniqueness(com) == 1) {
        for (int i = 0; i < 5; i++) {
            combos[amt_combos][i] = com[i]; // Add the unique combo to the array of unique combos.
        }
        printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", com[0], com[1], com[2], com[3], com[4]);
        amt_combos += 1;
    }
}

void findCombos(int num, int safe, int fg, int td, int td1, int td2) {
    if (num < 0){
        return;
    } else if (num == 0) {
        int combo[5] = {td2, td1, td, fg, safe}; // Create an array so that you can check the uniqueness.
        printUniqueCombo(combo);
        return;
    } else {
        findCombos(num - 8, safe, fg, td, td1, td2+1);
        findCombos(num - 7, safe, fg, td, td1+1, td2);
        findCombos(num - 6, safe, fg, td+1, td1, td2);
        findCombos(num - 3, safe, fg+1, td, td1, td2);
        findCombos(num - 2, safe+1, fg, td, td1, td2);
    }
}

int main()
{
    int input;
    
    while(1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &input);
        
        if (input <= 1) {
            break;
        }
        
        findCombos(input, 0, 0, 0, 0, 0);   
    }

    return 0;
}