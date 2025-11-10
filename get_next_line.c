#include "get_next_line.h"

static char *rest;

int check_newline(char *str)
{
    size_t i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '\0')
        {
            return i;
        }
        i++;
    }
    return 0;
}

char *return_string(int fd, char *str)
{
    char *strjoin;
    ssize_t value;

    while (!check_newline(str))
    {
        if (rest)
        {
            strjoin = ft_strjoin(rest, str);
            free(rest);
            rest = strjoin;
        }
        else
        {
            rest = ft_strdup(str);
        }
        ft_bzero(str, BUFFER_SIZE);
        read(fd, str, BUFFER_SIZE);
        value = read(fd, str, BUFFER_SIZE);
        if (value <= 0)
        {
            free(str);
            return NULL;
        }
    }

    return strjoin;
}

char *get_next_line(int fd)
{
    char *buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    char *result;
    if (!buffer)
        return NULL;
    result = return_string(fd, buffer);
    return result;
}
