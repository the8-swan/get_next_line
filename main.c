# include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd1 = open("file.txt", O_RDONLY);

	char *line1;
	int i = 1;

	while((line1 = get_next_line(fd1)) != NULL)
	{
		printf("%s\n",line1);
		free(line1);
		i++;
	}
}