#ifndef MAIN_H
# define MAIN_H

char	*ft_read_file(int fd, t_map_params *params);
int		**ft_map_converter(char *grid, t_map_params *params);
int		**ft_square_calc(int **map, t_map_params map_params);

#endif
