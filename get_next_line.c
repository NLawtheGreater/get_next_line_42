#include "get_next_line.h"

/*1.Create pointer 
**2.
**3.Loop reading 1 byte to pointer (where 
	read length < BUFFER_SIZE)
**3.1 Check return of read()
**4.Return NULL if -1 otherwise return pointer*/

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*linked;
	int			check;
	int			lcheck;

	buff = (char *) malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lcheck = -1;
	if (!linked)
	{
		linked = malloc (sizeof(char) * (2));
		if (!linked)
			return (NULL);
		*linked = '\0';
	}
	while (lcheck < 0)
	{
		*buff = '\0';
		check = read (fd, buff, BUFFER_SIZE);
		
		if (check == -1)
		{
			free(buff);
			if (linked)
				free(linked);
			return (NULL);
		}
		else
		{
			if (check != 0)
			*(buff + check) = '\0';
			if (check < BUFFER_SIZE && *linked != '\0')
			{
				//printf("%s", buff);
				linked = storebuff(linked, buff, check);
				//printf("%s", linked);
				lcheck = line_check(linked);
				if (lcheck == -1)
					lcheck = ft_strlen(linked) - 1;
				line = fill_line(linked, lcheck);
				if (line)
					del_done(linked, lcheck);
				free(buff);
				return (line);
			}
	/*if (check < BUFFER_SIZE)
		large (buff, linked, check);*/
			else if (check == 0 && *linked == '\0')
			{
				free(buff);
				if (linked)
					free(linked);
				return (NULL);
			}
			else
			{
				linked = storebuff(linked, buff, BUFFER_SIZE);
				if (!linked)
					{
						free (buff);
						return (NULL);
					}
				lcheck = line_check(linked);
			}
		}
	}
	line = fill_line(linked, lcheck);
	if (line)
		del_done(linked, lcheck);
	free(buff);
	return (line);
}