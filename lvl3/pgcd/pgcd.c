/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:41:15 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 12:06:40 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e 
// 1$
// $> ./pgcd | cat -e
// $

#include <stdlib.h>
#include <stdio.h>

void pgcd (int  a, int b)
{
	int gcd;
	int i;

	i = 1;
	gcd = 1;
	while (i < a && i < b)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
		i++;
	}
	printf("gcd: %d", gcd);
}


int main(int ac, char **av)
{
	if (ac == 3)
	{
		pgcd(atoi(av[1]), atoi(av[2]));
	}
	printf("\n");
}