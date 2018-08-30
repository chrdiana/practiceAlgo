#include <stdio.h>


int main () {
    
    int arr[] = {0,0,0,0,0,0,0,0}; //binary array

    int i = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = 0;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cnt++;
            printf("cnt: %d\n", cnt);
        } else {
            //encountered 0
            if (max < cnt) 
                max = cnt;
            cnt = 0;
        }
    }
    if (max < cnt) 
        max = cnt;
    printf("Max consecutive 1s: %d\n", max);

    return 0;
}

