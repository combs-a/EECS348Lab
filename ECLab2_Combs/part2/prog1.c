#include <stdio.h>

float sum(float arr[], int start, int end) {
    float sum = 0;
    
    for(int i = start; i < end; i++) {
        sum += arr[i];
    }

    return sum;
}

int findMin(float arr[]) {
    int min = 0;
    
    for (int i = 0; i < 12; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    
    return min;
}

int findMax(float arr[]) {
    int max = 0;
    
    for (int i = 0; i < 12; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    
    return max;
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
    float avg = sum(input, 0, 12)/12;
    int min = findMin(input);
    int max = findMax(input);
    
    // Print minimum/maximum/average
    printf("\nSales summary: \n\nMinimum sales: %.2f\t(%s)\nMaximum sales: %.2f\t(%s)\nAverage Sales: %.2f\n", input[min], months[min], input[max], months[max], avg);
    
    // 6-month moving average
    printf("\nSix-Month Moving Average Report:\n\n");
    
    for (int i = 0; i <= 6; i++) {
        float avg2 = sum(input, i, i+6)/6;
        int width = 10;
        
        printf("%-*s - %10s\t%.2f\n", width, months[i], months[i+5], avg2);
    }
    
    // Highest to lowest
    printf("\nSales Report (Highest to Lowest):\n\n%10s\tSales\n", "Month");
    int rem;
    for (int i = 0; i < 12; i++) {
        rem = findMax(input);
        printf("%-*s\t%.2f\n", width, months[rem], input[rem]);
        input[rem] = 0;
    }
    
    return 0;
}
