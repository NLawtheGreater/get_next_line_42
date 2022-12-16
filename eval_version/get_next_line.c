/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:17:28 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/02 17:17:33 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	static char	*linked;
	int			lcheck;

	if (!linked)
	{
		linked = malloc(sizeof(char) * (2));
		if (!linked)
			return (NULL);
		*linked = 0 ;
	}
	lcheck = -1;
	linked = readtext(linked, &lcheck, fd);
	if (!linked)
		return (NULL);
	line = fill_line(linked, lcheck);
	if (line)
		del_done(linked, lcheck);
	return (line);
}
