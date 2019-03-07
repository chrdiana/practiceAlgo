/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"  

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
PAHNAPLSIIGYIR
PAHNAPLSIIGYIR

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
PINALSIGYAHRPI
70: clffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpamwhtwfdrvvtwhfsgfzqruvemekesxggirju
4: PINALSIGYAHRPI
5: PHASIYIRPLIGAN
Explanation:

P     I    N        0       6         12           : i+4+(4-2)
A   L S  I G        1    5  7     11  13           : i+4        i+2     i+4      i+2
Y A   H R           2  4    8  10     14           : i+2        i+4     i+2      i+4
P     I             3       9         15           : i+4+(4-2)

if 5:    PHASIYIRPLIGAN
5: PHASIYIRPLIGAN
P     H        00 01 02 03 04        0         8              : i+5+(5-2)                        n+(n-2)
A   S I        10 11 12 13 14        1      7  9         15   : i+6         i+2      i+6        (n-1)+(n-1-2)
Y  I  R        20 21 22 23 24        2    6    10     14      : i+4         i+4      i+4        (n-2)+(n-2-2)
P L   I G      30 31 32 33 34 35     3  5      11  13         : i+2         i+6      i+2        (n-3)+(n-3-2)
A     N        40 41 42 43 44 45     4         12             : i+5+(5-2)                        n+(n-2)

P   A   H   N       0     4     8      12                 : i i+3+(3-2)                     n+(n-2)
A P L S I I G       1  3  5  7  9  11  13  15             : i i+2         i+2     i+2      (n-1)+(n-1-2)
Y   I   R           2     6     10     14                 : i i+3+(3-2)                     n+(n-2)

   0 1 2 3 4 5 6 7 8 9 10 11 12 13
   P A Y P A L I S H I  R  I  N  G
3: 0 4 8 12 1 3 5 7 9 11 13 15 2 6 10 12

4:


l=14, n=4, (4+(4-2)+4+(4-2)+2) 7 cols  4+(4-2)*x = 6*x = 14 ~ 3
l=14, n=3, (3+(3-2)+3+(3-2)+3+(3-2)+2) 7 cols
[5+(5-2)]*x >= 14


        int index = 2*numRows -2;
        int colWidth = numRows -1;
        
        int numCols = (len/index + 1) * colWidth;
        if (len < index) 
            numCols = colWidth + 1;

4: 
colwidth = n-1 : 3
chars = 4+(4-2) : 6
14/6 = 2
2+1 * 3 = 9



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
char* convert(char* s, int numRows) {
    if (!s)
        return NULL;
    if (numRows == 0)
        return NULL;
    int len = strlen(s);
    if (len == 0)
        return NULL;
    if (len == 1 || len <= numRows || numRows == 1)
        return s;

    int index = 2*numRows -2;
    int colWidth = numRows -1;
    int i, j, c;

    int numCols = (len/index + 1) * colWidth;
    if (len < index) 
        numCols = colWidth + 1;
    printf("columns: %d len: %d last: %c\n", numCols, len, s[len-1]);

    char **res = malloc(numRows*sizeof(char*));
  
    for (i = 0; i<numRows; i++){
        res[i] = calloc(numCols, sizeof(char));
        memset(res[i], '\0', numCols);
    }

    c = 0;
    j = 0;
    while (c<len){
        i = 0;
        while(i<numRows && c<len) {
            res[i][j] = s[c];
            printf("added %c at %d,%d\n", res[i][j], i,j);
            i++;
            c++;
        }
        i--;
        while (i >1 && j<numCols && c<len){
            i--;
            j++;
            res[i][j] = s[c];
            printf("added(w) %c at %d,%d\n", res[i][j], i,j);
            c++;    
        }
        j++;
    }
    char *result = calloc(len+1,sizeof(char));
    c = 0;
    for (i = 0; i<numRows; i++){
        for (j = 0; j<numCols; j++){
            if (res[i][j] != '\0'){
                //printf("[%d,%d] = %c\n",i,j,res[i][j]);
                result[c] = res[i][j];
                c++;
            }
        }
    }
   result[len] = '\0';
    return result;
}*/

char* convert(char *s, int numRows) {

    int len = strlen(s);
    if (!s || numRows == 0 || numRows == 1 || len == 0 || numRows > len) {
        return s;
    }

    int index = 0, step = 1,i;
    char **res;

    int idx = 2*numRows -2;
    int colWidth = numRows -1;
        
    int numCols = (len/idx + 1) * colWidth;
    if (len < idx) 
        numCols = colWidth + 1;

    res = malloc(numRows*sizeof(char*));
    for (i=0; i<numRows; i++)
        res[i] = calloc(numCols+1, sizeof(char));

    int *cidx = calloc(numRows,sizeof(int));
    

    i = 0;
    while(i < len) {
        //printf("index: %d, cidx[%d]: %d\n", index, index, cidx[index]);
        res[index][cidx[index]] = s[i];
        //printf("copied s[%d]: %c to res[%d][%d]: %c\n", i, s[i], index, cidx[index], res[index][cidx[index]]);
        cidx[index]++;
        
        if (index == 0) {
            step = 1;
        } else if (index == numRows - 1) {
            step = -1;
        }
        index +=step;
        i++;

    }
    for (i=0; i<numRows; i++){
        //printf("cidx[%d]: %d\n", i, cidx[i]);
        res[i][cidx[i]] = '\0';
    }
    
    char *result = calloc(len+1, sizeof(char));
    strcpy(result, res[0]);
    printf("RES[0]: %s\n", res[0]);
    for (i=1; i<numRows; i++){
        printf("RES[%d]: %s\n", i, res[i]);
        strcat(result, res[i]);
    }
    return result;

}

int main() {
   
    char s[] = "PAYPALISHIRING";
    char s1[] = "clffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpmhwdvthsfqueeexgrujigskmvrzgfwvrftwa";
    printf("70: %s\n", convert(s1, 70));
    printf("3: %s\n", convert(s, 3));
    printf("4: %s\n", convert(s, 4));
    printf("5: %s\n", convert(s, 5));
}