
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*storebuff(char *linked, char *buff, int store);
char	*fill_line(char *linked, int lcheck);
int		line_check(char const *linked);
void	del_done(char *linked, int lcheck);
char	*get_next_line(int fd);
char	*readtext(char *linked, int *lcheck, int fd);
void	*destroy(char *buff, char *linked);
size_t	ft_strlen(char const *str);
void	*ft_realloc(void *ptr, size_t size);
#endif
