#ifndef MAP_H
# define MAP_H

typedef struct s_map_params
{
	int		lines;
	int		columns;
	int		size;
	char	empty;
	char	obstacles;
	char	fill;
}				t_map_params;

typedef struct s_map_loc
{
	int	x;
	int	y;
	int	point;
}				t_map_loc;

#endif
