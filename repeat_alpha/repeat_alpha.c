/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:05:44 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 13:24:29 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

#include <unistd.h>

int	main (int argc, char **argv)
{
	int i;
	int a;

	i = 0;

	a = 'a';

	if (argc == 2)
	{
		while (argv[1][i])
			{
				if ((argv[1][i] >= 'a') && (argv[1][i] <= 'z'))
				{	
					a = 'a';
					while(a <= argv[1][i])
						{
							write (1, &argv[1][i], 1);
							a++;
						}
				}
				else if ((argv[1][i] >= 'A') && (argv[1][i] <= 'Z'))
				{	
					a = 'A';
					while(a <= argv[1][i])
						{
							write (1, &argv[1][i], 1);
							a++;
						}
				}
				else
					write (1, &argv[1][i], 1);
				i++;
			}
	}
	write (1, "\n", 1);
}
