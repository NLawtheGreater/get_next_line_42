#include "get_next_line.h"

/*char	*large(char *buff, char *linked, int check, int multi)
{
	int	i;

	if (!linked)
	{
		linked = malloc(check + 1);
		i = 0;
		while (*(buff + i))
		{
			*(linked + i) = *(buff + i);
			i++;
		}
	}
	else
	{
		linked = ft_realloc()

	}
}
*/
char *storebuff(char *linked, char *buff, int store)
{
	int	i;
	int j;

	if (*buff == '\0')
		return (linked);
	j = ft_strlen (buff);
	
	i = ft_strlen (linked);
	linked = ft_realloc (linked, sizeof(char) * (i + j + 1));
	j = 0;
	while (j < store && *(buff + j) != '\0')
	{
		*(linked + i) = *(buff + j);
		i++;
		j++;
	}
	*(linked + i) = '\0';
	return (linked);
}

size_t	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int	line_check(char const *linked)
{
	int	i;

	i = 0;
	while (*(linked + i) != '\0')
	{
		if (*(linked + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *fill_line(char *linked, int lcheck)
{
	char	*line;

	line = (char *) malloc (sizeof(char) * (lcheck + 2));
	if (!line)
		return (NULL);
	*(line + lcheck + 1) = '\0'; 
	while (lcheck >= 0)
	{
		*(line + lcheck) = *(linked + lcheck);
		lcheck--;
	}
	return (line);
}

void del_done(char *linked, int lcheck)
{
	int	i;
	int	j;

	i = ft_strlen (linked);
	if (i > (lcheck + 1))
	{
		j = 0;
		while (*(linked + lcheck + 1 + j) != '\0')
		{
			*(linked + j) = *(linked + lcheck + 1 + j);
			j++;
		}
		*(linked + j) = '\0';
	}
	else if (i == (lcheck + 1))
		*linked = '\0';
}

static void	*ft_memcpy_x(void *dst, const void *src)
{
	size_t	ind;

	ind = 0;
	while (*(char *)(src + ind) != '\0')
	{
		*(char *)(dst + ind) = *(char *)(src + ind);
		ind++;
	}
	*(char *)(dst + ind) = '\0';
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr_new;

	if (*(char *) ptr  == '\0')
	{
		free (ptr);
		return (malloc(size));
	}
	ptr_new = malloc(size);
	if (!ptr_new)
		return (NULL);
	ft_memcpy_x(ptr_new, ptr);
	free(ptr);
	return (ptr_new);
}