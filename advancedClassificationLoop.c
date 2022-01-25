#include <math.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int numberLength(int n);

int isArmstrong(int num) {
    int n = num;
    
    int len = numberLength(num);
    // printf("len = %d\n", len);
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
    for(int i=0; i<(len / 2); i++) {
        len = numberLength(num);
        int left = num / (int)pow(10, (len - 1 - i));
        int right = num % (int)(10 * pow(10, i));
        // printf("left = %d, right = %d", left, right);
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