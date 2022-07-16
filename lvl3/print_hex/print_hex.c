/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:08:18 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 12:28:54 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>
void ft_putchar (int c)
{
	write (1, &c, 1);
}

void ft_putnbr_hex(int nb)
{
	char *hexnb = "0123456789abcdef";
	if (nb > 16)
	{
		ft_putnbr_hex(nb/16);
		ft_putnbr_hex(nb%16);
	}
	else 
		write(1, &hexnb[nb], 1);
}

int ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while(str[i] != '\0')
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	return (result);
}
int	main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_putnbr_hex(ft_atoi(av[1]));
	}
	write(1, "\n",1);
	return (0);
}