#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(char character, int count)
{
    if (character != 0)
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
}

void compress()
{
    int count = 1;
    char prevChar, currentChar;
    getchar();
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
            output(prevChar, count);
            count = 1;
        }
        prevChar = currentChar;
    }
    output(prevChar, count);
}

#define MAX_LINE_LENGTH 100

void printBetween(int startIndex, int endIndex, char *input)
{
    for (int i = startIndex; i < endIndex; i++)
    {
        printf("%c", input[i]);
    }
}

void expand()
{
    char input[MAX_LINE_LENGTH];
    fgets(input, MAX_LINE_LENGTH, stdin);
    while (fgets(input, MAX_LINE_LENGTH, stdin))
    {
        int lastEncoded = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            int index = i - 1;
            if (input[i] == '*' && (input[index] >= '0' && input[index] <= '9'))
            {
                int number = input[index] - '0';
                if (index != 0 && (input[index - 1] >= '1' && input[index - 1] <= '9'))
                {
                    index--;
                    number += (input[index] - '0') * 10;
                }
                index--;
                if (input[index] == input[index - 1] && input[index - 1] == input[index - 2])
                {
                    printBetween(lastEncoded, index - 2, input);
                    for (int z = 0; z < number; z++)
                    {
                        printf("%c", input[index]);
                    }
                    lastEncoded = i + 1;
                }
            }
            if (i == strlen(input) - 1)
            {
                
                printBetween(lastEncoded, strlen(input) - 1, input);
            }
        }
        printf("\n");
    }
}

int main()
{
    char option;
    scanf("%c", &option);
    if (option == 'C')
    {
        compress();
        printf("\n");
    }
    else if (option == 'E')
    {
        expand();
    }
    return 0;
}