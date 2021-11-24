#include <unistd.h> 
#include <stdio.h> 

void ft_putchar(char a) 
{ 
	write(1, &a, 1); 
} 

void ft_print_combn(int n) 
{
	int	combn[n];
	int	p;
	if (n <= 0 || n >= 10)
		return ;
	else
	{
		p = 0;
		while (p < n)
		{
			combn[p] = p;
			p++;
		}
		while (p > 0)
		{
			int maxdigit = 10;
			p = 0;
			while (p < n)
			{
				ft_putchar(combn[p] + '0');
				p++;
			}
			p = n;
			while (p--)
			{
				int digit = combn[p];
				if (digit < --maxdigit) 
				{ 
					do 
					{ 
						combn[p++] = ++digit; 
					} 
					while (p < n); 
					ft_putchar(','); 
					ft_putchar(' '); 
					break; 
				} 
			}
		}  
		ft_putchar('\n'); 
	} 
} 
