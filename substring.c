/* Implement strstr: Returns pointer to the first occurrence of str2 in str1 or returns NULL if str2 does not exist in str1. */

#include <stdio.h>
#include <string.h>


char * my_strstr(char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    //if (strlen(str2) == 0)
    //    return NULL;

    int i = 0, j= 0;
    int start = -1;

    while (i >= 0) {
        if (str1[i] == '\0'){
            return NULL;
        } 
        if (str1[i] == str2[j]) {
            if (start == -1)
                start = i;
            i++;
            j++;
        } else {
            if (start != -1){
                j = 0;
                i = start + 1;
            } else {
                i++;
            }
            start = -1;
        }
        if (str2[j] == '\0')
            break;
    }
    if (start != -1)
        return str1+start;
    else
        return NULL;
}

int main () {
    char str[] = "aaa";

    char *s = my_strstr(str, "");

    printf("String returned: %s\n", s);
}