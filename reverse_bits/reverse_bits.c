/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:29:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/14 20:49:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100

// 11 / 2 1
// 5 / 2 1
// 2 / 2 0
// 1 / 2 1
// 0 / 2 0
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	// unsigned int i;
	unsigned int n;
	unsigned int octet_mod;
	unsigned char reverse;

	// i = 128;
	n = 8;

	while (n > 0)
	{
		octet_mod = octet % 2;
		reverse = 2 * reverse + octet_mod;
		if (octet_mod == 1)
			write (1, "1", 1);
		else if (octet_mod == 0)
			write (1, "0", 1);
		octet = octet / 2;
		n--;
	}
	write(1, "\0", 1);
	return (reverse);
}

int main(void)
{
	printf("reverse 7: %d",reverse_bits(7));
}