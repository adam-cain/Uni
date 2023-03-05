#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(char character, int count)
{
    if (count >= 3)
    {
        printf("%c%c%c%d*", character, character, character, count);
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("%c", character);
        }
    }
}

void compress()
{
    int count = 1;
    char prevChar, currentChar;
    int startFlag = 0;
    while ((currentChar = getchar()) != EOF)
    {
        if (currentChar == '\n')
        {
            output(prevChar, count);
            count = 1;
        }
        else if (prevChar == currentChar)
        {
            count++;
        }
        else
        {
            if (startFlag == 1)
            {
                output(prevChar, count);
            }
            else
            {
                startFlag = 1;
            }
            count = 1;
        }
        prevChar = currentChar;
    }
    output(prevChar, count);
}

#define MAX_LINE_LENGTH 1000

void expand()
{
    char input[MAX_LINE_LENGTH];

    while (fgets(input, MAX_LINE_LENGTH, stdin))
    {
        int lastEncoded = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            if (input[i] == '*' && input[i-1] >= '0' && input[i-1] <= '9')
            {
                int numberIndex = i - 1;
                int decimalPlace = 1;
                int number = 0;
                do
                {
                    number += (input[numberIndex]-'0') * decimalPlace;
                    decimalPlace *= 10;
                    numberIndex--;
                } while (input[numberIndex] >= '0' && input[numberIndex] <= '9');
                //printf("(%c*%i)",input[numberIndex],number);
                for (int j = lastEncoded; j < numberIndex-2; j++)
                {
                    printf("%c",input[j]);
                }
                for (int z = 0; z < number; z++)
                {
                    printf("%c",input[numberIndex]);
                }
                lastEncoded = i + 1;
            }
            if(i == strlen(input)-1){
                for (int j = lastEncoded; j < strlen(input)-1; j++)
                {
                    printf("%c",input[j]);
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    char option;
    scanf("%c\n", &option);
    if (option == 'C')
    {
        compress();
    }
    else if (option == 'E')
    {
        expand();
    }
    return 0;
}