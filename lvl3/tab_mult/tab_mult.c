/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:39:18 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 17:57:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $

#include <unistd.h>

void ft_putchar(int c)
{
	write (1, &c, 1);
}

void ft_putnbr (unsigned int n)
{
	if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	else
		ft_putchar(n + '0');
}

int atoi (char *arr)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (arr[i] != '\0')
	{
		result = result * 10 + (arr[i] - '0');
		i++;
	}
	return (result);
}

void print_table (char *arr)
{
	int n;

	n = 1;

	while (n <= 9)
	{
		ft_putnbr(n);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		ft_putnbr(atoi(arr));
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		ft_putnbr(atoi(arr) * n);
		ft_putchar('\n');
		n++;
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		print_table(av[1]);
	}
	ft_putchar('\n');
}