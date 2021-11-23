#ifndef FT_H
# define FT_H
# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"
# define DICT_FILE_E  "numbers.dict"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_total(char *str);
int		check_arg(char *str);
char	**parse_dictionary(void);
void	ft_print(char *str, char **tab);
char	*ft_split(char *tab);
int		zero_check(char *str);

#endif
