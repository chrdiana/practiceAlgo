#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//Alternate solution, reverse the string (or half the string) and if it is same.


bool isPalindrome(char* s) {

    if (!s)
        return true;
    int len = strlen(s);
    if (!len)
        return true;
    
     int i = 0, j = len-1;

     while (j > i) {
         // between 48 and 57 or between 65 and 97
         if ((s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'z')){
             i++;
             continue;
         }
         if ((s[j] < 'A' || s[j] > 'z') && (s[j] < '0' || s[j] > '9')) {
            j--;
            continue;
        }
        printf("comparing %c and %c\n", s[i], s[j]);
        if (toupper(s[i]) != toupper(s[j])){
            printf("returning false\n");
            return false;
        }
        i++;
        j--;
    }
    return true;
    
}

int check_palindromes (char *str) {
    int len = strlen(str);
    int i = 0, j = len-1;

    while (j > i) {
        if (str[i] < '0' || str[i] > 'z') {
            i++;
            continue;
        }
        if (str[j] < '0' || str[j] > 'z') {
            j--;
            continue;
        }
       printf("comparing %c and %c\n", str[i], str[j]); 
        if (toupper(str[i]) != toupper(str[j]))
            return 1; //failure
        i++;
        j--;
    }
    return 0; //success
}

int check_palindromes_recur(char *str, int start, int end) {
    
    int ret = 0;

    while(str[start] < '0' || str[start] > 'z') {
        start++;
    }
    while ((str[end] < '0' || str[end] > 'z') && (start < end))
        end--;  

    if (start == end) {
        printf("%d == %d, returning 0\n", start, end);
        return 0; //success
    }
    printf("Calling with %d:%c, %d:%c\n", start, str[start], end, str[end]); 

    if (toupper(str[start]) != toupper(str[end])) {
        printf("%c != %c, return 1\n", toupper(str[start]), toupper(str[end]));
        return 1; //failure
    }

    if (end > start) {
        printf("calling recur with %d, %d\n", start+1, end-1);
        ret = check_palindromes_recur(str, start+1, end-1);
    }
    printf("Returing %d\n", ret);
    return ret;
}

int main (int argc, char *argv[]) {

    char str[] = "aa";
    char str1[] = ".,";
    char str2[] = "A man, a plan, a canal: Panama";
//    char str2[] = "race a car";
    int result = 1;
    printf("Input string: %s\n", str2);
    bool res;

    res = isPalindrome(str);
    if (result) {
        printf("%s is a Palindrome\n", str);
    } else {
        printf("%s is NOT a Palindrome\n", str);
    }
    res = isPalindrome(str1);
    if (result) {
        printf("%s is a Palindrome\n", str1);
    } else {
        printf("%s is NOT a Palindrome\n", str1);
    }
    res = isPalindrome(str2);
    if (res) {
        printf("%s is a Palindrome\n", str2);
    } else {
        printf("%s is NOT a Palindrome\n", str2);
    }
    result = check_palindromes(str2);
    if (!result) {
        printf("%s is a Palindrome\n", str2);
    } else {
        printf("%s is NOT a Palindrome\n", str2);
    }


 /*   printf("Recursive method\n");
    result = check_palindromes_recur(str, 0, strlen(str)-1);
    if (!result) {
        printf("%s is a Palindrome\n", str);
    } else {
        printf("%s is NOT a Palindrome\n", str);
    }*/

    return 0;
}
