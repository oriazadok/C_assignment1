#include <stdio.h>
#include "NumClass.h"

int main() {
    int a,b;
    scanf("%d%d", &a, &b);

    // Armstrong numbers
    printf("The Armstrong numbers are: ");
    for(int i=a; i<=b; i++) {

        int temp = isArmstrong(i);
        if(temp == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");

    // palindroms numbers
    printf("The Palindromes are: ");
    for(int i=a; i<=b; i++) {
        int temp = isPalindrome(i);
        if(temp == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");

    // prime numbers
    printf("The Prime numbers are: ");
    for(int i=a; i<=b; i++) {
        int temp = isPrime(i);
        if(temp == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");

    //strong numbers
    printf("The Strong numbers are: ");
    for(int i=a; i<=b; i++) {
        int temp = isStrong(i);
        if(temp == TRUE){
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}