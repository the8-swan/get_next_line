#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		slen;
	char		*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	if (len > slen - start)
		len = slen - start;
	ptr = malloc((len +1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

int ft_checknewline(char* str){
    int i;

    i = 0;
    while(str[i]){
        if(str[i] == '\n')
            return i+1;
        i++;
    }
    return -1;
}
char    *ft_leftc(char *line){
    int n ;
    char    *left = NULL;
    if(( n = ft_checknewline(line)) == -1){
        return NULL;
    }
     left = ft_substr(line,n,ft_strlen(line) - n);
     if(!left)
         return NULL;
     ft_bzero(line+n, ft_strlen(line) - n);

    return left;
}

char    *ft_returned_ligne(char *buffer, char *left, int fd)
{
    ssize_t r;
    char    *line;
    while( ft_checknewline(buffer) < 0){
        r = read(fd,buffer,BUFFER_SIZE);
        if(r <= 0){
            free(left);
            return NULL;
        }
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
    if(!line){
        free(buffer);
        return NULL;
    }
    left = ft_leftc(line);
    return line;

}

