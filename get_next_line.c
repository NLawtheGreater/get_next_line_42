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
	char		*linked;
	int			check;
	int			lcheck;
	int			i;

	buff = (char *) malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	*buff = 0;
	lcheck = -1;
	while (lcheck < 0)
	{
		check = read (fd, buff, BUFFER_SIZE);
		if (check == -1)
		{
			free(buff);
			return (NULL);
		}
		else
		{
			linked = storebuff(linked, buff);
			if (!linked)
				return (NULL);
			if (linked < BUFFER_SIZE && linked)
			{
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
			else if (check == 0)
			{
				free(buff);
				return (NULL);
			}
		}
			else
				lcheck = line_check(linked);
		}
	}
	line = fill_line(linked, lcheck);
	if (line)
		del_done(linked, lcheck);
	free(buff);
	return (line);
}