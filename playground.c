#include <stdio.h>
#include <string.h>
#include <limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main()
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	///char		*buff;
	
	fd1 = open("./text1.txt", O_RDONLY);
	fd2 = open("./text2.txt", O_RDONLY);
	fd3 = open("./text3.txt", O_RDONLY);
	
	/*line = (char *) malloc(BUFFER_SIZE + 1);
	int	i;
	for (i = 1; i <= 4; i++)
	{
	read (fd, line, BUFFER_SIZE);
	printf("%s", line);
	}
	printf("\n");*/
	do {
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	} while (line);
	
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
//0x5645a5e5c004

/*int	main()
{
	int *ptr;
	int	b;

	b = 1;
	ptr = &b;
	printf("%p\n", ptr);
}*/
//23 = 0x7fffa61879bc
