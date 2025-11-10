# include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
//     char buf[20000];
//   //  int offset = 0;
//     int fb = open("file.txt",O_RDONLY);
//     int n =0;

//     while((n = read(fb,buf,6))){
//         buf [7] = '\0';
//        printf("result -> %s\n",buf);
//     }
	
    // buf[offset] = '\0';
    // printf("offset -> %d\n",offset);
    // printf("buf-> %s\n",buf);
     int fd = open("file.txt",O_RDONLY);
     char *ptr = get_next_line(fd);
     while(ptr){
        printf("%s \n",ptr);
      ptr = get_next_line(fd);
     }
    // return 0;
}
