/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:55:03 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/17 15:21:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in 
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the 
// begin/end of the string.

// If the number of parameters is different from 1, the program will display 
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional" 
// spaces (meaning that there won't be additionnal spaces at the beginning or at 
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
// l'indifference de celui precede mepris du temps le$
// $> ./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "il contempla le mont" | cat -e
// mont le contempla il$
// $> ./rev_wstr | cat -e
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
		while (i2--)
		{
			ft_putstr(adr_arr[i2]);
			if (i2 > 0)
				ft_putchar (' ');
		}
	}
	ft_putchar ('\n');
}