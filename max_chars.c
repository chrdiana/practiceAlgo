#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TABLE_SIZE 52

int hash(char key) {

    int hash;
    hash = key % TABLE_SIZE; 
    return hash;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Invalid args\n");
        return -1;
    }

    char str[1024] = {'\0'};
    int i = 0;
    int hash_idx;
    char keys[TABLE_SIZE] = {'\0'};
    int values[TABLE_SIZE] = {0};
    int max = 0;
    char max_char = '\0';
    
    strncpy(str, argv[1], 1024);
    printf("Input str: %s\n", str);

    // generate hashmap O(N)
    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'z') {
            continue;
        }
        hash_idx = hash(str[i]);   
        //printf("str: %c, hash: %d\n", str[i], hash_idx);

        if (keys[hash_idx] == '\0') {
            keys[hash_idx] = str[i];
            values[hash_idx] = 1;
        } else if (keys[hash_idx] == str[i]){
            values[hash_idx]++;
        } else {
            //collision
            printf("Collision, not expected to be here, key: %c, strc: %c\n", keys[hash_idx], str[i]);
        }

        i++;
    }
    //get Max value, O(N), can do a max heap and get it in O(logN), but overall it is O(N)
    i = 0;
    while (i < TABLE_SIZE) {
        if (max < values[i]) {
            max = values[i];
            max_char = keys[i];
        }
        i++;
    }
    printf("Max char: %c, count: %d\n", max_char, max);
    return 0;
}
