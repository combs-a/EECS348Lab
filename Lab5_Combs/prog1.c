#include <stdio.h>

float average(float arr[], int start, int end) {
    float sum = 0;

    for(int i = start; i < end; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    // Array of 12 doubles and an array of strings for each month.
    float input[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char months[12][10] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int width = 10;


    // Print monthly sales table.
    printf("Monthly sales report for 2022:\n\nMonth     \tSales\n");
   
    for (int i = 0; i < 12; i++) {
        printf("%-*s\t%.2f\n", width, months[i], input[i]);
    }

    // Find total average.
    float avg = average(input, 0, 12);

    printf("\nSales summary: \n\nMinimum sales: %.2f\nMaximum sales: %.2f\nAverage Sales: %.2f\n", input[0], input[11], avg);

    printf("\nSix-Month Moving Average Report:\n\n");

    printf("\nSales Report (Highest to Lowest):\n\n");
    
    return 0;
}
