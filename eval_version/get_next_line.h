/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:17:17 by niclaw            #+#    #+#             */
/*   Updated: 2022/11/02 17:17:24 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# else
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 40
#  endif
# endif

char	*storebuff(char *linked, char *buff, int store);
char	*fill_line(char *linked, int lcheck);
int		line_check(char const *linked);
void	del_done(char *linked, int lcheck);
char	*get_next_line(int fd);
char	*readtext(char *linked, int *lcheck, int fd);
void	*dump(char *buff, char *linked);
size_t	ft_strlen(char const *str);
void	*ft_realloc(void *ptr, size_t size);
#endif
