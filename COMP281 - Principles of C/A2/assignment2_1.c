#include <stdio.h>

void compress(){
    char* line;
    while (scanf("%s",line) != EOF)
    {
        printf("%s",line);
    }
}

void expand(){

}

int main()
{
    char type; 
    scanf("%c",type);
    if(type == 'C'){
        printf("%s","Compress");
        compress();
    }else if(type == 'E'){
        //printf()
        expand();
    }
    return 0;
}
