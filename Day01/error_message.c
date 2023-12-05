/*
** ADVENT OF CODE, 2023
** DAY 01
** File description:
** error_message for each cases
*/

#include <unistd.h>

int error_message_int(char *error_message)
{
    write(2, error_message, 1);
    return (84);
}

char *error_message_char(char *error_message)
{
    write(2, error_message, 1);
    return (NULL);
}

char **error_message_char_array(char *error_message)
{
    write(2, error_message, 1);
    return (NULL);
}