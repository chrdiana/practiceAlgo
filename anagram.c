#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_anagram(char s[], char t[]){
    int n1 = strlen(s);
    int n2 = strlen(t);
    if (n1 != n2) {
        return false;
    }
    if ((strcmp(s, "") == 0) && (strcmp(t, "") == 0))
        return true; //both strings are empty

    int hash[26] = {0};
    int i = 0, idx;
    for (i=0; i<n1; i++){
        idx = s[i]%26;
        hash[idx]++;
    }
    for (i=0; i<n1; i++){
        idx = t[i]%26;
        hash[idx]--;
    }
    
    for (i = 0; i<26; i++) {
        if (hash[i] > 0) 
            return false;
    }
    return true;
} 

int main() {

    char s1[] = "anagram";
    char s2[] = "nageram";
    printf("Are %s and %s anagram? %s\n", s1, s2, is_anagram(s1, s2)? "TRUE" : "FALSE"); 
    
    return 0;
}
