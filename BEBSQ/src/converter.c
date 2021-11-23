#include "map.h"
#include <stdlib.h>

int	g_j;
int	g_k;
int	**g_data;

int	**ft_map_converter(char *grid, t_map_params *map)
{
	g_j = -1;
	g_k = 0;
	g_data = (int **)malloc(sizeof(*g_data) * map->lines);
	g_data[++g_j] = (int *)malloc(sizeof(**g_data) * map->columns);
	if ((!g_data) || !(g_data[g_j]))
		return (0);
	while (*grid != '\0')
	{
		if (*grid == '\n')
		{
			g_data[++g_j] = (int *)malloc(sizeof(**g_data) * map->columns);
			if ((g_k != map->columns - 1) || !(g_data[g_j]))
				return (0);
			g_k = 0;
		}
		if (*grid == map->empty)
			g_data[g_j][g_k++] = -1;
		if (*grid++ == map->obstacles)
			g_data[g_j][g_k++] = 0;
	}
	if (g_j != map->lines - 1)
		return (0);
	else
		return (g_data);
	return (0);
}
