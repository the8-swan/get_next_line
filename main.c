# include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt",O_RDONLY);
    char *ptr = get_next_line(fd);
    while(ptr){
       printf("%s \n",ptr);
     ptr = get_next_line(fd);
    }
    return 0;
}
