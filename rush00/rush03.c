#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	printvh(int v, int h, int x, int y)
{
	if ((v == 1 && h == y) || (v == 1 && h == 1))
	{
		ft_putchar('A');
	}
	else if ((v == x && h == y) || (v == x && h == 1))
	{
		ft_putchar('C');
	}
	else if (v == 1 || h == 1 || v == x || h == y)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int vert;
	int hori;

	vert = 1;
	hori = 1;
	while (hori <= y)
	{
		while (vert <= x)
		{
			printvh(vert, hori, x, y);
			vert++;
		}
		hori++;
		ft_putchar('\n');
		vert = 1;
	}
}
 
int main(void)
{
    rush(5, 3);
    rush(5, 1);
    rush(1, 1);
    rush(1, 5);
    rush(4, 4);
    return (0);
}


