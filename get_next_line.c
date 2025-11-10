#include "get_next_line.h"

static char *pointer;
static char *rest;

char *get_next_line(int fd)
{
    char *ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
    char *dup;
    char *final;
    size_t length = 0;
    size_t l = 0;

    char *p = NULL;
    if (!ptr)
        return NULL;
    read(fd, ptr, BUFFER_SIZE);
    ptr[BUFFER_SIZE] = '\0';
    while (ft_strchr(ptr, '\n') == NULL)
    {
        dup = ft_strdup(ptr);
        if (!pointer && rest)
        {
            pointer = rest;
            final = ft_strjoin(pointer, dup);
            pointer = final;
        }
        else if (!pointer)
            pointer = dup;
        else
        {
            final = ft_strjoin(pointer, dup);
            pointer = final;
        }
        ft_bzero(ptr, BUFFER_SIZE);
        read(fd, ptr, BUFFER_SIZE);
    }
    if ((p = ft_strchr(ptr, '\n')))
    {
        char *temp;
        length = p - ptr;
        l = ft_strlen(ptr) - length;
        temp = pointer;
        rest = ptr + (l);
        pointer = NULL;
        ft_bzero(ptr + length, l);
        final = ft_strjoin(temp, ptr);
    }
    return (final);
}
