/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Write a function that splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains the address
** of a string (representing a word).
** The last cell must be null to terminate the array.
*/

#include <stdlib.h>

static int is_separator_char(char c)
{
    return (c <= 32 || c >= 127);
}

static void in_word_handler(int *in_word, int *count)
{
    if (!*in_word) {
        *in_word = 1;
        *count += 1;
    }
}

static int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_separator_char(str[i]))
            in_word = 0;
        else
            in_word_handler(&in_word, &count);
    }
    return count;
}

static void word_array_main_part(int *word_start, int *len, int *i, char *str)
{
    *word_start = *i;
    for (; str[*i] != 0 && !is_separator_char(str[*i]); *i += 1);
    *len = *i - *word_start;
}

char **my_str_to_word_array(char *str)
{
    int words_nb = count_words(str);
    int word_start = 0;
    int len = 0;
    char **result = malloc((words_nb + 1) * sizeof(char *));
    int i = 0;
    int j = 0;

    for (;str[i] != 0; j++) {
        for (; is_separator_char(str[i]); i++);
        if (str[i] == 0)
            break;
        word_array_main_part(&word_start, &len, &i, str);
        result[j] = malloc(len + 1);
        for (int k = 0; k < len; k++)
            result[j][k] = str[word_start + k];
        result[j][len] = 0;
    }
    result[j] = NULL;
    return result;
}
