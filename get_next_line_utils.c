/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:17:38 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/02 17:17:43 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*readtext(char *linked, int *lcheck, int fd)
{
	char	*buff;
	int		check;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (*lcheck < 0)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
			return (dump (buff, linked));
		else
		{
			linked = storebuff(linked, buff, check);
			*lcheck = line_check(linked);
			if (check < BUFFER_SIZE && *linked != '\0' && *lcheck == -1)
				*lcheck = ft_strlen(linked) - 1;
			if (check == 0 && *linked == '\0')
				return (dump (buff, linked));
		}
	}
	free (buff);
	return (linked);
}

/*char	*storage(char *linked, char *buff, int *check, int *lcheck)
{
	char	*line;	

	if (*check < BUFFER_SIZE && *linked != '\0')
	{
		linked = storebuff(linked, buff, *check);
		*lcheck = line_check(linked);
		if (*lcheck == -1)
			*lcheck = ft_strlen(linked) - 1;
		line = fill_line(linked, *lcheck);
		if (line)
			del_done(linked, *lcheck);
		free(buff);
		return (line);
	}
	else if (*check == 0 && *linked == '\0')
		return (dump (buff, linked));
	else
	{
		linked = storebuff(linked, buff, BUFFER_SIZE);
		if (!linked)
		{
			free (buff);
			return (NULL);
		}
		*lcheck = line_check(linked);
	}
}*/

void	*dump(char *buff, char *linked)
{
	free(buff);
	if (linked)
		free(linked);
	return (NULL);
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
	if (*(char *) ptr == '\0')
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
