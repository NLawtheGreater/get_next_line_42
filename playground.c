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
	int		fd;

	line = malloc(500);
	fd = open("text.txt", O_RDONLY);
	fd = 0;
	/*printf("%ld\n", read(fd, line, 61));
	*/
	
	do {
		line = get_next_line(fd);
		if (line)
		{
		printf("%s", line);
		}
	}
	while (line);
	free (line);

	/*printf("1234567890123456789012345678901234567890");
	do {
		line = get_next_line(0);
		if (line)
		{
		printf("%s", line);
		}
	}
	while (line);*/
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
