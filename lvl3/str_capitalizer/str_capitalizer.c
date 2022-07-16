/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:26:45 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 16:37:18 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : str_capitalizer
// Expected files   : str_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or several strings and, for each argument,
// capitalizes the first character of each word (If it's a letter, obviously),
// puts the rest in lowercase, and displays the result on the standard output,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string. If a word only has one letter, it must be
// capitalized.

// If there are no arguments, the progam must display \n.

// Example:

// $> ./str_capitalizer | cat -e
// $
// $> ./str_capitalizer "Premier PETIT TesT" | cat -e
// Premier Petit Test$
// $> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
// Deuxieme Test Un Peu Moins  Facile$
//    Attention C'est Pas Dur Quand Meme$
// Aller Un Dernier 0123456789pour La Route    E $
// $>

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int to_underscore (int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return(c);
}

int to_upperscore (int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return(c);
}


void rstr_capitaliser(char *str)
{
	int	i;
	int c;
	int in_word;

	in_word = 0;
	i = 0;

	if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
	{
			c = to_upperscore (str[0]);
			ft_putchar(c);
			i++;
			in_word = 1;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			in_word = 1;
		if (in_word == 1 && str[i] <= 32)
			in_word = 0;
		if (in_word == 1 && str[i - 1] <= 32)
		{
				c = to_upperscore (str[i]);
		}
		else
			c = to_underscore(str[i]);
		ft_putchar(c);
		i++;
	}
}

int main (int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		rstr_capitaliser(av[i]);
		i++;
	}
	ft_putchar('\n');
}