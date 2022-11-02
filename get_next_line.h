
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_collect
{
	char				*ch;
	struct s_collect	*ptr;
}	t_collect;

char *get_next_line(int fd);
void *ft_realloc(void *ptr, size_t size);
char	*storebuff(char *linked, char *buff, int store);
size_t	ft_strlen(char const *str);
int	line_check(char const *linked);
char *fill_line(char *linked, int lcheck);
void del_done(char *linked, int lcheck);
#endif
