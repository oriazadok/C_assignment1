#include "NumClass.h"
#include <math.h>
#include <stdio.h>

int numberLength(int n);
int isArmstrong_2(int num, int len);


int isArmstrong(int num) {
    int len = numberLength(num);
    int sum = isArmstrong_2(num, len);

    if(num == sum) {
        return TRUE;
    }
    return FALSE;
}

int isArmstrong_2(int num, int len) {
    if(num % 10 == 0) {
        return pow(num, len);
    }

    return pow(num, len) + isArmstrong_2(num / 10, len);
}

int isPalindrome(int num) {
    int len = numberLength(num);
    for(int i=0; i<(len / 2); i++) {
        int left = num % (int)pow(10, (len - 1 - i));
        int right = num % (int)pow(10, i);
        if(left != right) {
            return FALSE;
        }
    }
    return TRUE;
}

int numberLength(int n) {

    int counter = 0;

    while(n > 0) {
        counter++;
        n /= 10;
    }
    return counter;
}