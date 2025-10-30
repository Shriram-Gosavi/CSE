#include <stdio.h> 
#define MAX 10 
 int n; 
int G[MAX][MAX]; int color[MAX]; int m; 
 
int isSafe(int v, int c) {     for (int i = 0; i < n; i++) {         if (G[v][i] && color[i] == c)             return 0; 
    } 
    return 1; 
} 
 
int graphColoring(int v) {     if (v == n) {         printf("\nColor assignment: ");         for (int i = 0; i < n; i++)             printf("%d ", color[i]);         return 1; 
    } 
    for (int c = 1; c <= m; c++) {         if (isSafe(v, c)) {             color[v] = c;             if (graphColoring(v + 1))                 return 1;             color[v] = 0; 
        } 
    } 
    return 0; 
} 
 
int main() { 
    printf("Enter number of vertices: ");     scanf("%d", &n);     printf("Enter adjacency matrix:\n");     for (int i = 0; i < n; i++)         for (int j = 0; j < n; j++)             scanf("%d", &G[i][j]);     printf("Enter number of available frequencies (colors): ");     scanf("%d", &m); 
    for (int i = 0; i < n; i++)         color[i] = 0;     if (!graphColoring(0))         printf("\nNo solution exists with %d colors.\n", m);     else         printf("\nSuccessfully colored the graph using %d colors.\n", m);     return 0; 
} 
