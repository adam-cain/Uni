#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

typedef struct
{
    char *word;
    int count;
} Word;

typedef struct
{
    Word *words;
    int size;
} WordList;

void addWord(WordList *list, char *word)
{
    // search for the word in the list
    for (int i = 0; i < list->size; i++)
    {
        if (strcmp(list->words[i].word, word) == 0)
        {
            // word already exists, increment count and return
            list->words[i].count++;
            return;
        }
    }

    // Allocate more memory for an extra word
    list->words = realloc(list->words, (list->size + 1) * sizeof(Word));

    // word doesn't exist, add it to the list
    list->words[list->size].word = strdup(word);
    list->words[list->size].count = 1;
    list->size++;
}

void printWords(const WordList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%s => %d", list->words[i].word, list->words[i].count);
        if (i != list->size - 1)
        {
            printf("\n");
        }
    }
}

int compareWords(const void *a, const void *b)
{
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return strcmp(wordA->word, wordB->word);
}

void sortWords(WordList *list)
{
    qsort(list->words, list->size, sizeof(Word), compareWords);
}

int main()
{
    WordList list = {NULL, 0};
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH] = "";
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] = line[i] + 32;
            }
            if (line[i] >= 'a' && line[i] <= 'z')
            {
                int len = strlen(word);
                *(word + len) = line[i];
                *(word + len + 1) = '\0';
            }
            else
            {
                if (strlen(word) != 0 && line[i] != '-' && line[i] != '\'')
                {
                    addWord(&list, word);
                    memset(word, 0, sizeof(word));
                }
            }
        }
    }
    sortWords(&list);
    printWords(&list);
    return 0;
}
