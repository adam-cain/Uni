#include <stdio.h>

#define BUFFER_SIZE;

void output(char character, int count){
    
    printf("%c%c%c%d*", character, character, character, count);
}

void compress()
{
    int c, count = 0;
    const char EOL = '\n';
    char prevChar;
    while ((c = getchar()) != EOF)
    {
        printf("%c",c);
        // if(c = EOL){
        //     if(count >= 3){
        //         printRepeats(prevChar,count);
        //     }else{
        //         printf("%c",prevChar);
        //     }
        //     count = 0;
        // }else if(prevChar == c){
        //     count++;
        // }
        // else{

        // }
    }
}

void expand()
{
}

int main()
{
    int c = getchar();
    if (c == 'C') {
        compress();
    } else if (c == 'E') {
        decompress();
    }
    return 0;
}