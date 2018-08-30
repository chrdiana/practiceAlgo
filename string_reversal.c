#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* my_malloc(size_t len) {
    void *ptr = malloc(len);
    printf("malloced %p for len %zu\n", ptr, len);
    return ptr;
}

void my_free(void *ptr) {
    printf("Freeing %p\n", ptr);
    free(ptr);
}

char* recursive_reverse(char *str) {

    char *sub_sol;
    char *sol = NULL;
    printf("Calling recursive on %s\n", str); 
    if (strcmp(str, "") == 0) {
        return sol;
    } 
    sol = my_malloc(sizeof(char*)*strlen(str));
    sub_sol = recursive_reverse(str+1);
    if (sub_sol) {
        strcpy(sol, sub_sol);
        my_free(sub_sol);
    }
    strncat(sol, str, 1);
    printf("returning %s\n", sol);
    return sol;    
} 

int main () {

    char inputStr[] = "teset";
    int i = 0,j = 0;
    char tmp;
    
    j = strlen(inputStr); //O(N)
    j--; //last char '\0'
    printf("Length of input string: %d\n", j);
    
    //O(N/2)
    while (j > i) {
        tmp = inputStr[i];
        inputStr[i] = inputStr[j];
        inputStr[j] = tmp;
        i++;
        j--;
    }
    
    printf("Reversed string: %s\n",inputStr);

    char str[] = "teset";
    printf("trying recursive solution on %s\n", str);
    
    char *rev = recursive_reverse(str);
    printf("Reversed with recursion: %s\n", rev);
    my_free(rev);
    return 0;
}
