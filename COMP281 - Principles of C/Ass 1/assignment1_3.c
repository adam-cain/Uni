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
    //printf("(%i)%i + %i = %i\n",arr[index],charToInt(arr[index]), increment, result);
    arr[index] = intToChar(result % 10);
    if(result/10 > 0){
        printf("Carry\n");
        if(index == 0){ 
            printf("Expand size - starting: %i\n",stringLength(arr));         
            for (int k = stringLength(arr)-1; k >= 0; k--){        
                arr[k]=arr[k-1];
            }
            arr[0] = intToChar(result/10);
            printf("Finished: %i",stringLength(arr));
        }
        else{
            return incrementArr(arr,index+1,result/10);
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
        printf("%c + %c\n", i[x+diff],j[x]);
        incrementArr(i,x+diff,charToInt(j[x]));
    }
}

int main() {
    char a[MAX_DIGITS], b[MAX_DIGITS], results[MAX_DIGITS];

    // Read input
    scanf("%s", a);
    scanf("%s", b);

    if (stringLength(a) < stringLength(b)){
        SumArr(b,a);
    }else{
        SumArr(a,b);
    }
    printf("%s",a);
    
    // printf("Press ENTER key to Continue\n");  
    // scanf("%s",a);
    return 0;
}
