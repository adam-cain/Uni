#include <stdio.h>

int main() {
    int a, b, n, remainder, quotient;
    scanf("%d %d %d", &a, &b, &n);

    // perform integer division to get the quotient and remainder
    quotient = a / b;
    remainder = a % b;

    // iterate n times, calculating the next decimal digit each time
    for (int i = 0; i < n; i++){
        // multiply remainder by 10 to get the next decimal place
        remainder *= 10;

        // calculate the next digit by integer division
        int digit = remainder / b;

        // update remainder to be the new remainder
        remainder %= b;

        // print the nth digit after the decimal point and exit the loop
        if (i == n - 1){
            printf("%d\n", digit);
            break;
        }
    }
    // printf("Press ENTER key to Continue\n");  
    // getchar(); 
    return 0;
}