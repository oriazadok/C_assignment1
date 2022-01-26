#include "NumClass.h"
#include <math.h>
#include <stdio.h>

int numberLength(int n);
int isArmstrong_2(int num, int len);
int isPalindrome_2(int n,int sum);


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
    int n = num;
    if(num / 10 == 0){
        return TRUE;
    }
    int sum = isPalindrome_2(n, 0);
    if (sum == num){
        return TRUE;
    }
    return FALSE;
}

int isPalindrome_2(int n,int sum){
    if(n <= 0) {
        return sum;
    }
    sum *= 10;
    sum += n % 10;
    n /= 10;
    return isPalindrome_2(n, sum);
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