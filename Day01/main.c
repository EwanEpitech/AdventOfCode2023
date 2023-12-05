/*
** ADVENT OF CODE, 2023
** DAY 01
** File description:
** Answer to Day 01 of Advent of Code 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int error_message_int(char *error_message);
char *error_message_char(char *error_message);
char **error_message_char_array(char *error_message);
char **my_str_to_word_array(char *str);


char *read_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 25000);
    int ret = 0;

    if (fd == -1)
        return error_message_char("Error: File not found.\n");
    if (!buffer)
        return error_message_char("Error: Malloc failed.\n");
    ret = read(fd, buffer, 25000);
    if (ret == -1)
        return error_message_char("Error: Read failed.\n");
    buffer[ret] = '\0';
    close(fd);
    return (buffer);
}

int calculate_number(char *str)
{
    int first_one = 0;
    int second_one = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            first_one = str[i] - '0';
            break;
        }
    }
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            second_one = str[i] - '0';
    return (first_one * 10 + second_one);
}

int answer_day01_part1(char *input)
{
    char **map = my_str_to_word_array(input);
    int result = 0;

    for (int i = 0; map[i] != NULL; i++)
        result += calculate_number(map[i]);
    return (result);
}

int main()
{
    char *input = read_file("input");

    if (!input)
        return (error_message_int("Error: File not found.\n"));
    printf("Answer is: %d", answer_day01_part1(input));
    return (0);
}