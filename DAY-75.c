/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray*/

#include <stdio.h>

int main() {
    int arr[100];      // Array to store elements
    int n;             // Number of elements
    int i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 0;   // To store maximum length
    int sum;

    // Outer loop to select starting point
    for(i = 0; i < n; i++) {
        sum = 0;

        // Inner loop to find subarray sum
        for(j = i; j < n; j++) {
            sum = sum + arr[j];

            // Check if sum becomes zero
            if(sum == 0) {
                int len = j - i + 1;

                // Update maximum length
                if(len > max_len) {
                    max_len = len;
                }
            }
        }
    }

    // Display result
    printf("Length of longest subarray with sum 0 is: %d", max_len);

    return 0;
}