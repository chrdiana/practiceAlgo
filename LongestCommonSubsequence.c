/*
 * Longest common subsequence
 * 
 * Recursion: lcs(s1, s2, m, n)
 * 1. last char of s1 and s2 matches, thus is part of the subsequence:
 *    lcs(s1, s2, m, n): 1 + lcs(s1, s2, m-1, n-1)
 * 2. last char does not match, this is not part of the subsequence:
 *    lcs(s1, s2, m, n): MAX( lcs(s1, s2, m, n-1) , lcs(s1, s2, m-1, n) )
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a>b)? a : b)

/*
Recursive solution:
*/
int lcs_recursive(char *s1, char *s2, int m, int n) {

    if (m == 0 || n == 0) {
        return 0;
    }
    int res;
    if (s1[m-1] == s2[n-1]) {
        res = 1 + lcs_recursive(s1, s2, m-1, n-1);
        printf("res: %d\n", res);
        return res;
    } else {
        res = MAX(lcs_recursive(s1, s2, m, n-1), lcs_recursive(s1, s2, m, n-1));
        printf("res: %d\n", res);
        return res;
    }
}

/*
DP solution:
*/
int lcs_dp(char *s1, char *s2, int m, int n) {
    int i, j;
    int **dp = calloc(m+1, sizeof(int*));
    for (i = 0; i<m+1; i++) {
        dp[i] = calloc(n+1, sizeof(int));
    }
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = MAX(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {

    char s1[] = "AAA";
    char s2[] = "AABBAA";

    //int lcs = lcs_recursive(s1, s2, strlen(s1), strlen(s2));
    //printf("Length of LCSR of %s and %s is %d\n", s1, s2, lcs);

    int lcs = lcs_dp(s1, s2, strlen(s1), strlen(s2));

    printf("Length of LCSDP of %s and %s is %d\n", s1, s2, lcs);
}