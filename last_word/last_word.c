/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:39:49 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/14 20:14:11 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int 	len;
		int		in_word;

		in_word = 0;
		len = 0;
		while (argv[1][len] != '\0')
		{
			len++;
		}
		len--;
		while (len >= 0)
		{
			if (argv[1][len] <= 32 && in_word == 0) 
				len--;
			else if (argv[1][len] <= 32 && in_word == 1)
			{
				len++;
				while(argv[1][len] != '\0')
				{
					write(1, &argv[1][len], 1);
					len++;
				}
				write(1, "\n", 1);
				return (0);
			}
			else if (argv[1][len])
				{
					in_word = 1;
					len--;
				}
		}
	}
	write(1, "\n", 1);
}