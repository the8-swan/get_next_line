#include "get_next_line.h"
#include <stdio.h>

int check_newline(char *str)
{
    size_t i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '\\' && str[i+1] == 'n')
        {
            return i-1;
        }
        i++;
    }
    return -1;
}
char    *ft_leftstring(char *str, char **rest,int n)
{
    char *left = ft_substr(str ,0,n+1);
    char    *final = ft_strjoin(*rest,left);
    free(*rest);
    *rest = ft_substr(str ,n+1,(ft_strlen(str) - (n+1)));
    return (final);
}

char *return_string(int fd, char *str)
{
    char *strjoin;
    static char *rest;
    ssize_t value;
    int n;

    while ((n = check_newline(str))<0)
    {
        if (rest)
        {
            strjoin = ft_strjoin(rest, str);
            free(rest);
            rest = ft_strdup(strjoin);
            free(strjoin);

        }
        else
            rest = ft_strdup(str);
        ft_bzero(str, BUFFER_SIZE);
        value = read(fd, str, BUFFER_SIZE);
        str[BUFFER_SIZE] = '\0';
        if (value <= 0)
        {
            free(str);
            return NULL;
        }
    }
    return ft_leftstring(str,&rest,n);
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
