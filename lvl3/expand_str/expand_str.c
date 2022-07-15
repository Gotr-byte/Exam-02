/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:09:31 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 16:28:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : expand_str
// Expected files   : expand_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it with exactly three spaces
// between each word, with no spaces or tabs either at the beginning or the end,
// followed by a newline.

// A word is a section of string delimited either by spaces/tabs, or by the
// start/end of the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
// vous   voyez   c'est   facile   d'afficher   la   meme   chose$
// $> ./expand_str " seulement          la c'est      plus dur " | cat -e
// seulement   la   c'est   plus   dur$
// $> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./expand_str "" | cat -e
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
		int k;

		i = space_head(&av[1][0]);
		j = space_tail(&av[1][0]);
		k = 0;

		while (i <= j)
		{

			if(av[1][i] > 32)
				write(1, &av[1][i], 1);
			if(av[1][i] <= 32)
			{
				write(1, "   ", 3);
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