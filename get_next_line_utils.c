#include "get_next_line.h"

char	*large(char *buff, char *linked, int check, int multi)
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

char	*storebuff(char *linked, char *buff)
{
	int	i;
	int j;

	if (!buff)
		return (linked);
	j = ft_strlen (buff);
	if (!linked)
	{
		i = 0;
		linked = malloc (j + 1);
		if (!linked)
			return (NULL);
		*linked = 0;
	}
	else
	{
		i = ft_strlen (linked);
		linked = ft_realloc (linked, i + j + 1);
	}
	//*buff has '\0'*?
	while (*buff != '\0')
	{
		*(linked + i) = *buff;
		i++;
		buff++;
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

	line = malloc (lcheck + 2);
	if (!line)
		return (NULL);
	*line = 0; 
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
		linked = NULL;
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

	if (!ptr)
		return (malloc(size));
	ptr_new = malloc(size);
	if (!ptr_new)
		return (NULL);
	ft_memcpy(ptr_new, ptr);
	free(ptr);
	return (ptr_new);
}