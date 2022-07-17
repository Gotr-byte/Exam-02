/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:23:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/17 16:52:06 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring | cat -e
// $
// $>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define WD_NUM 1000
#define WD_LEN 1000

void ft_putchar (int c)
{
	write (1, &c, 1);
}

void ft_putstr (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
}

int	main (int ac, char **av)
{
	if (ac == 2)
	{
		char	**adr_arr;
		int		i;
		int		i2;
		int		i3;
		int		k;

		adr_arr = (char**)malloc(WD_NUM * sizeof(char*));
		i = 0;
		i2 = 0;

		while (av[1][i] != '\0')
		{
			i3 = 0;
			if (av[1][i] > 32)
			{
				adr_arr[i2] = (char*)malloc(WD_LEN * sizeof(char));
				while (av[1][i] > 32)
				{
					adr_arr[i2][i3] = av[1][i];
					i3++;
					i++;
				} 
				adr_arr[i2][i3] = '\0';
				i2++;
			}
			else
				i++;
		}
		adr_arr[i2] = 0; 
		k = 1;
		while (k < i2)
		{
			ft_putstr(adr_arr[k]);
			if (k != i2)
				ft_putchar (' ');
			k++;
		}
		ft_putstr(adr_arr[0]);
	}
	ft_putchar ('\n');
}