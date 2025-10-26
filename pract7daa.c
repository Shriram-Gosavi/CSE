#include <stdio.h> 
#include <limits.h> 
 
int sumFreq(int freq[], int i, int j) {     int sum = 0;     for (int k = i; k <= j; k++)         sum += freq[k];     return sum; 
} 
 
int optimalSearchTree(int keys[], int freq[], int n) {     int dp[n][n];     for (int i = 0; i < n; i++)         dp[i][i] = freq[i];     for (int L = 2; L <= n; L++) {         for (int i = 0; i <= n - L; i++) {             int j = i + L - 1;             dp[i][j] = INT_MAX;             int totalFreq = sumFreq(freq, i, j);             for (int r = i; r <= j; r++) {                 int leftCost = (r > i) ? dp[i][r - 1] : 0;                 int rightCost = (r < j) ? dp[r + 1][j] : 0;                 int currentCost = leftCost + rightCost + totalFreq;                 if (currentCost < dp[i][j])                     dp[i][j] = currentCost; 
            } 
        } 
    } 
    return dp[0][n - 1]; 
} 
 
int main() { 
    int keys[] = {10, 12, 20};     int freq[] = {34, 8, 50};     int n = sizeof(keys) / sizeof(keys[0]);     printf("Cost of Optimal BST is: %d\n", optimalSearchTree(keys, freq, n));     return 0; 
} 
