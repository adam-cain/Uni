#include <stdio.h>

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
                printf("(%i-%i)",prevChar,currentChar);
                startFlag = 1;
            }
            count = 1;
        }
        prevChar = currentChar;
    }
    output(prevChar, count);
}

void expand()
{
}

int main()
{
    printf("HHHH");
    char* c;
    scanf("%s",c);
    printf("Test");
    if (c[0] == 'C')
    {
        printf("comp");
        compress();
    }
    else if (c[0] == 'E')
    {
        expand();
    }
    return 0;
}