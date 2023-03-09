#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 30
#define INITIAL_CAPACITY 100

typedef struct {
    char *word;
    int count;
} Word;

typedef struct {
    Word *words;
    int capacity;
    int size;
} WordList;

void addWord(WordList *list, const char *word) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->words = realloc(list->words, list->capacity * sizeof(Word));
    }
    list->words[list->size].word = strdup(word);
    list->words[list->size].count = 1;
    list->size++;
}

// void sortWords(WordList *list) {
//     qsort(list->words, list->size, sizeof(Word), compareWords);
// }

int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *) a;
    const Word *wordB = (const Word *) b;
    return strcmp(wordA->word, wordB->word);
}

void printWords(const WordList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s => %d\n", list->words[i].word, list->words[i].count);
    }
}

void freeWords(WordList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->words[i].word);
    }
    free(list->words);
}

int main() {
    WordList list = { NULL, INITIAL_CAPACITY, 0 };
    char line[MAX_LINE_LENGTH + 1];
    while (fgets(line, sizeof(line), stdin)) {
        char *word = strtok(line, " ,.\n");
        while (word != NULL) {
            char *cleanWord = malloc(MAX_WORD_LENGTH + 1);
            int len = strlen(word);
            int cleanLen = 0;
            for (int i = 0; i < len; i++) {
                if (isalpha(word[i])) {
                    cleanWord[cleanLen++] = tolower(word[i]);
                }
            }
            cleanWord[cleanLen] = '\0';
            addWord(&list, cleanWord);
            free(cleanWord);
            word = strtok(NULL, " ,.\n");
        }
    }
    //sortWords(&list);
    printWords(&list);
    freeWords(&list);
    return 0;
}
