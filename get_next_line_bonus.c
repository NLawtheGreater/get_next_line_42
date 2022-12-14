/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:06:05 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/03 16:06:13 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

/*1.Create pointer 
**2.
**3.Loop reading 1 byte to pointer (where 
	read length < BUFFER_SIZE)
**3.1 Check return of read()
**4.Return NULL if -1 otherwise return pointer*/

char	*storebuff(char *linked, char *buff, int store)
{
	int	i;
	int	j;

	if (store == 0)
		return (linked);
	*(buff + store) = '\0';
	j = ft_strlen (buff);
	i = ft_strlen (linked);
	linked = ft_realloc (linked, sizeof(char) * (i + j + 1));
	j = 0;
	while (j < store)
	{
		*(linked + i) = *(buff + j);
		i++;
		j++;
	}
	*(linked + i) = '\0';
	return (linked);
}

char	*fill_line(char *linked, int lcheck)
{
	char	*line;

	if (lcheck < 0)
		return (NULL);
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

void	del_done(char *linked, int lcheck)
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*linked[10000];
	char		*new;
	int			lcheck;

	if (fd != 0 && !(fd >= 1 && fd <= 39))
		return (NULL);
	lcheck = -1;
	if (!linked[fd])
	{
		new = malloc(sizeof(char) * (2));
		if (!new)
			return (NULL);
		*new = 0;
		linked[fd] = new;
	}
	linked[fd] = readtext(linked[fd], &lcheck, fd);
	if (!linked[fd])
		return (linked[fd]);
	line = fill_line(linked[fd], lcheck);
	if (line)
		del_done(linked[fd], lcheck);
	return (line);
}
