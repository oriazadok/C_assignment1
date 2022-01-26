#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int numberLength(int n);

int isArmstrong(int num) {
    int n = num;
    int len = numberLength(num);
    int sum = 0;
    while (n > 0) {
        sum += pow(n % 10, len);
        n /= 10;
    }

    if(num == sum) {
        return TRUE;
    }

    return FALSE;
}

int isPalindrome(int num) {
    
    int len = numberLength(num);
    int n = num;
    int sum = 0;
    for(int i=0; i<len; i++) {
        sum *= 10;
        sum += n % 10;
        n /= 10;
    }

    if(num == sum) {
        return TRUE;
    }
    return FALSE;
}

int numberLength(int n) {

    if (n == 0) {
        return 1;
    }
    int counter = 0;

    while(n > 0) {
        counter++;
        n /= 10;
    }
    return counter;
}