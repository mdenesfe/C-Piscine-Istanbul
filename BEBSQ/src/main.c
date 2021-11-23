#include "map.h"
#include "tools.h"
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

int		g_i;
int		g_fd;

void	ft_map_display(int **map, t_map_params *params)
{
	int		j;
	int		k;
	char	*str;

	g_i = -1;
	(str = malloc(sizeof(*str) * params->columns));
	if (!str)
		return ;
	while (++g_i < params->lines)
	{
		k = 0;
		j = -1;
		while (++j < params->columns - 1)
		{
			if (map[g_i][j] == -1)
				str[k++] = params->fill;
			else if (map[g_i][j] == 0)
				str[k++] = params->obstacles;
			else
				str[k++] = params->empty;
		}
		str[k++] = '\n';
		str[k] = '\0';
		ft_putstr(str);
	}
}

int	main(int ac, char **av)
{
	int				i;
	int				**map;
	char			*grid;
	t_map_params	params;

	i = 0;
	while (i < ac || (ac == 1 && i == 0))
	{
		i++;
		g_fd = open(av[i], O_RDONLY);
		if (ac-- == 1)
			g_fd = 0;
		else if (g_fd == -1)
			ft_map_error();
		if (g_fd != -1)
		{
			grid = ft_read_file(g_fd, &params);
			map = ft_map_converter(grid, &params);
			if ((grid) && (map))
				ft_map_display(ft_square_calc(map, params), &params);
			else
				ft_map_error();
		}
	}
	return (0);
}
