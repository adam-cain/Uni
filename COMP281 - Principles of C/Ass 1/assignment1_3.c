#include <stdio.h>

#define MAX_DIGITS 99

int stringLength(char *str){
    int i = 0;
    for (i; str[i] != '\0'; ++i);
    return i;
}

int charToInt(char c) {
    return c - '0';
}

int intToChar(int i){
    return i + '0';
}

char* incrementArr(char* arr, int index, int increment){
    int result = charToInt(arr[index]) + increment;
    arr[index] = intToChar(result % 10);
    if(result/10 > 0){
        if(index == 0){ 
            for (int k = stringLength(arr); k >= 0; k--){      
                arr[k]=arr[k-1];
            }
            arr[0] = intToChar(result/10);
            return arr;
        }
        else{
            return incrementArr(arr,index-1,1);
        }
    }
    else{
        return arr;
    }
}

char* SumArr(char* i, char* j){
    int j_len = stringLength(j);
    int diff = stringLength(i) - j_len;
    for (int x = j_len-1; x >= 0 ; x--)
    {
        i = incrementArr(i,x+diff,charToInt(j[x]));
    }
    return i;
}

int main() {
    char a[MAX_DIGITS], b[MAX_DIGITS];

    // Read input
    scanf("%s", a);
    scanf("%s", b);

    if (stringLength(a) < stringLength(b)){
        printf("%s",SumArr(b,a));
    }else{
        printf("%s",SumArr(a,b));
    }
    return 0;
}