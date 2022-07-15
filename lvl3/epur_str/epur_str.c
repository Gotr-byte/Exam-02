/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:38:30 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 16:21:10 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.

// Example:

// $> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
// vous voyez c'est facile d'afficher la meme chose$
// $> ./epur_str " seulement          la c'est      plus dur " | cat -e
// seulement la c'est plus dur$
// $> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>

#include <unistd.h>

int space_head (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] <= 32)
		i++;
	return (i);
}

int space_tail (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0 && str[i] <= 32)
	{
		i--;
	}
	return (i);
}

int	main (int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		int j;
		int in_word;
		int space;

		space = 0;
		in_word = 0;

		i = space_head(&av[1][0]);
		j = space_tail(&av[1][0]);

		while (i <= j)
		{
			if(av[1][i] > 32)
				write(1, &av[1][i], 1);
			if(av[1][i] <= 32)
			{
				write(1, " ", 1);
				i++;
				while (av[1][i] <= 32)
					i++;
			}
			else
				i++;
		}
	}
	write (1, "\n", 1);
}