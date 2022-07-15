/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:52:43 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 13:00:09 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int *a;
	int *b;
	int num1;
	int num2;

	num1 = 1;
	num2 = 2;

	a = &num1;
	b = &num2;
	printf ("num1: %d	num2: %d\n", num1, num2);
	ft_swap (a, b);
	printf ("num1: %d	num2: %d\n", num1, num2);
}