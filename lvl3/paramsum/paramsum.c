/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:01:41 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 09:16:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>
#include <unistd.h>
void ft_putchar (int c)
{
	write(1, &c, 1);
}

void ft_putnbr (int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

#include <unistd.h>

int main (int ac, char **av)
{
	(void)av;
	ac--;
	ft_putnbr(ac);
	ft_putchar('\n');
	return(0);
}