/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:06:42 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/03 16:06:47 by niclaw           ###   ########.fr       */
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
			return (destroy (buff, linked));
		else
		{
			linked = storebuff(linked, buff, check);
			*lcheck = line_check(linked);
			if (check < BUFFER_SIZE && *linked != '\0' && *lcheck == -1)
				*lcheck = ft_strlen(linked) - 1;
			if (check == 0 && *linked == '\0')
				return (destroy (buff, linked));
		}
	}
	free (buff);
	return (linked);
}

void	*destroy(char *buff, char *linked)
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
