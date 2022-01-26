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
    
    if(num / 10 == 0) {
        return pow(num, len);
    }
    return pow(num % 10, len) + isArmstrong_2(num / 10, len);
}

int isPalindrome(int num) {
    int len = numberLength(num);
    if(len == 1) {
        return TRUE;
    }
    int left = num / (int)pow(10, (len - 1));
    int right = num % 10;

    if (left == right) {
        num %= left * (int)pow(10, (len - 1));
        num /= 10;
        return isPalindrome(num);
    }
    return FALSE;;
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