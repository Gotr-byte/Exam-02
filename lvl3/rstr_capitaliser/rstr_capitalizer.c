/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:29:53 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 16:23:17 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rstr_capitalizer
// Expected files   : rstr_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or more strings and, for each argument, puts 
// the last character of each word (if it's a letter) in uppercase and the rest
// in lowercase, then displays the result followed by a \n.

// A word is a section of string delimited by spaces/tabs or the start/end of the
// string. If a word has a single letter, it must be capitalized.

// If there are no parameters, display \n.

// Examples:

// $> ./rstr_capitalizer | cat -e
// $
// $> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
// premieR petiT tesT$
// $> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
// deuxiemE tesT uN peU moinS  facilE$
//    attentioN c'esT paS duR quanD memE$
// alleR uN dernieR 0123456789pouR lA routE    E $
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
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			in_word = 1;
		if (in_word == 1 && str[i + 1] <= 32)
		{
			c = to_upperscore (str[i]);
			in_word = 0;
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