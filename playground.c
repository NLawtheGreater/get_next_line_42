#include <stdio.h>
#include <string.h>
#include <limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int same_string(char *expected, char *actual)
{
	if (expected == NULL && actual == NULL)
		printf("%d\n", 1);
	if ((expected == NULL && actual != NULL) || (expected != NULL && actual == NULL))
	{
		printf("%s\n", "error");
	}
	if (strcmp(expected, actual) != 0)
	{
		printf("%s\n", "error");
	}
	else
		printf("good\n");
	return 1;
}

int	main()
{
	/*char *name = "text1.txt";
		int fd_1 = open(name, O_RDONLY);
		int fd_2 = open(name, O_RDONLY);
		
		printf ("%s", get_next_line(fd_1));
		 //same_string(tmp, "0123456789\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), "0123456789\n");
		printf ("%s", get_next_line(fd_1));
		 //same_string(get_next_line(fd_1), "012345678\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), "012345678\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), "90123456789\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), "0123456789\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), "xxxx\n");
		printf ("%s", get_next_line(fd_2));
		 //same_string(get_next_line(fd_2), NULL);
		printf ("%s", get_next_line(fd_1));
		 //same_string(get_next_line(fd_1), "90123456789\n");
		printf ("%s", get_next_line(fd_1));
		 //same_string(get_next_line(fd_1), "0123456789\n");
		printf ("%s", get_next_line(fd_1));
		 same_string(get_next_line(fd_1), "xxxx\n");
		printf ("%s", get_next_line(fd_1));
		 //same_string(get_next_line(fd_1), NULL);
	*/
		char *buff = malloc(BUFFER_SIZE);
		read(2, buff, BUFFER_SIZE);
		printf("%s", buff);
		/*int fd = open("./text1.txt", O_RDONLY);
		printf("%d\n",fd);
		   same_string(get_next_line(fd), "aaaaaaaaaa\n");
		   same_string(get_next_line(fd), "bbbbbbbbbb\n");
		close(fd);
		char *temp;
		do
		{
			temp = get_next_line(fd);
			free(temp);
		} while (temp != NULL);
			  //same_string(get_next_line(fd), NULL);
		*/ 
		/*int fd = open("./text1.txt", O_RDONLY);
		printf("%s", get_next_line(fd));	   
		printf("%s", get_next_line(fd));	   
		printf("%s", get_next_line(fd));	   
		printf("%s", get_next_line(fd));	   
		printf("%s", get_next_line(fd));
		close(fd);
		printf("%s", get_next_line(2));*/
		//printf("%s", get_next_line(1));
		//printf("%s", get_next_line(2));
		//printf("%s", get_next_line(3));
	/*	   same_string(get_next_line(fd), "aaaaaaaaaa\n");
		   same_string(get_next_line(fd), "bbbbbbbbbb\n");
		   same_string(get_next_line(fd), "cccccccccc\n");
		   same_string(get_next_line(fd), "dddddddddd\n");
		   same_string(get_next_line(fd), NULL);
	*/
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
