# include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd1 = open("file.txt", O_RDONLY);
	//int fd2 = open("eyo.txt", O_RDONLY);

	char *line1;
	//char *line2;
	// line1 = get_next_line(fd1);
	// printf("%s",line1);
	// line2 = get_next_line(fd2);
	// printf("%s",line2);
	 line1 = get_next_line(fd1);
	// printf("%s",line1);
	// line2 = get_next_line(fd2);
	// printf("%s",line2);
	
	// free(line1);
	// free(line2);
	// while((line1 = get_next_line(fd1)) != NULL)
	// {
		printf("%s",line1);
		 line1 = get_next_line(fd1);
		 printf("%s",line1);
	// 	free(line1);
	// }
}