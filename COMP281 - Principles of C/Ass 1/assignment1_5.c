#include <stdio.h>

int main() {
    int num;
    while (scanf("%d", &num) != EOF){
        // convert integer to character and print it
        printf("%c", (char) num);
    }
    // printf("Press ENTER key to Continue\n");  
    // getchar(); 
    return 0;
}