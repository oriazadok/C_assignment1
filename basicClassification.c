#define TRUE 1
#define FALSE 0

int factorial(int n);

int isPrime(int num){
    if(num < 1) {
        return FALSE;
    }
    for(int i=2; i<num; i++) {
        if(num % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

int isStrong(int num) {
    int n = num;
    int sum = 0;
    while(n > 0) {
        int t = n % 10;
        sum += factorial(t);
        n /= 10; 
    }

    if(num == sum) {
        return TRUE;
    }

    return FALSE;
}

int factorial(int n) {
    int ans = 1;
    for(int i=2; i<=n; i++) {
        ans *= i;
    }
    return ans;
}