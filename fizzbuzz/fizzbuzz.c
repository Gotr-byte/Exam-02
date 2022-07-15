/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:19:46 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 11:42:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : fizzbuzz
// Expected files   : fizzbuzz.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that prints the numbers from 1 to 100, each separated by a
// newline.

// If the number is a multiple of 3, it prints 'fizz' instead.

// If the number is a multiple of 5, it prints 'buzz' instead.

// If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

// Example:

// $>./fizzbuzz
// 1
// 2
// fizz
// 4
// buzz
// fizz
// 7
// 8
// fizz
// buzz
// 11
// fizz
// 13
// 14
// fizzbuzz
// [...]
// 97
// 98
// fizz
// buzz
// $>

#include <unistd.h>

void	ft_write_number (int i)
{
	char	str[10] = "0123456789";

	if (i > 9)
		ft_write_number(i / 10);
	write (1, &str[i % 10], sizeof(char));
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
	if((i % 3) == 0)
		write (1, "fizz", 4 * sizeof(char));
	if((i % 5) == 0)
		write (1, "buzz", 4 * sizeof(char));
	if ((i % 3 != 0) && (i % 5 != 0))
		ft_write_number (i);

	
	i++;
	write (1, "\n", 1);
	}
	
}
