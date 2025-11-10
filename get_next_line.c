# include "get_next_line.h"

static char* pointer;


char *get_next_line(int fd)
{
    char *ptr = malloc((BUFFER_SIZE +1) * sizeof(char));
    char *dup;
    char *final;
    size_t length = 0 ;
    size_t l = 0 ;

    char *p = NULL;
    if(!ptr)
        return NULL;
    read(fd,ptr,BUFFER_SIZE);
    ptr[BUFFER_SIZE + 1] = '\0';
    while(!ft_strchr(ptr,'\n')){
            dup = ft_strdup(ptr);
            if(!pointer)
                pointer = dup;
            else{
                final = ft_strjoin(final,dup);
                pointer = final;
            }
        ft_bzero(ptr,BUFFER_SIZE+1);
        read(fd,ptr,BUFFER_SIZE);
    }
    if((p = ft_strchr(ptr,'\n'))){
            char *temp;
            length = p -ptr;
            l = ft_strlen(ptr);
            temp = pointer;
            pointer = ptr + length +1;
            ft_bzero(ptr+length,l-length);
            final = ft_strjoin(temp,ptr);
    }
    
    return (final);
}
