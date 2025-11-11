#include "get_next_line.h"
#include <stdio.h>

int t_checknewline(char* str){
    int i;

    i = 0;
    while(str[i]){
        if(str[i] == '\n')
            return i;
        i++;

    }
    return -1;
}

char    *ft_returned_ligne(char *buffer, char *left, int fd)
{
    ssize_t r;
    int n;
    char    *line;
    while((n = t_checknewline(buffer)) < 0){
        r = read(fd,buffer,BUFFER_SIZE);
        if(r == -1){
            free(left);
            return NULL;
        }
        if(r == 0)
            break;
        if(!left)
            left = ft_strdup("");
        line = left;
        left = ft_strjoin(line,buffer);
        free(line);
    }
    return left;
}


char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    static char     *left;
    if(fd < 0 || BUFFER_SIZE <= 0 )
        return NULL;
    buffer =ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
    if(!buffer)
        return NULL;
    line = ft_returned_ligne(buffer,left,fd);
    printf("%s\n",line);
    return line;

}