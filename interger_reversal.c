#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <float.h>
/*
 * 12345
 * 12345, 12345%10 = 5, 5
 * 1234, 1234%10 = 4, 54
 * 123, 123%10 = 3, 543 
 */


int reverse(int input) {

    int tmp;
    long result = 0;;
    while (abs(input) > 0) {
        tmp = input%10;
        result = result*10 + tmp;
        input = input/10;
    }
    return (result>INT_MAX || result<INT_MIN)? 0: (int)result;
}

double myPow(double x, int n) {
    double ans = 1;
    unsigned long long p;
    if (n<0){
        p = -n;
        x = 1/x;
    }else p = n;
    if (p & 1) ans *= x;
    p >>= 1;  
    while (p) {
       x *= x; 
       printf("p:%llu, x:%f\n", p,x);
       if (p & 1){
             ans *= x;
             printf("p:%llu ans:%f\n", p, ans);
        }
       p >>= 1;  
       printf("p:%llu\n", p);
    }    
    return ans;
}

/*double myPow(double x, int n) {
    // -100 < x < 100
    // n is 32bit signed
    
    double res = 0;
    unsigned int i = 0;
    unsigned int un = abs(n);
    if (n == 0){
        return 1;
    }
    if (x == 1)
        return 1;
    if (x == -1){
        if (n%2 == 0)
            return 1;
        else
            return -1;
    } 
    if (n < 0) {
        x = 1/x;
    }
    res = x;
    for (i = 1; i<un; i++) {
        printf("i:%u, un:%u, res:%f\n", i, un, res);
        if (isinf(res) || res == 0)
            return res;
        res *=x;
    }
    return res;
}
*/
int main() {

    int input = -1563847412;

    printf("Reversed interger: %d\n", reverse(input));
    double res;
//    double res = pow(-1, INT_MAX);
    res = myPow(3, 10);
    printf("result: %f\n", res);
    int i = 6;
    printf("i: %d\n", i);
    printf("++i: %d\n", ++i);
    printf("i: %d\n", i);
    i = 6;
    printf("i: %d\n", i);
    printf("i++: %d\n", i++);
    printf("i: %d\n", i);
    return 0;
}
