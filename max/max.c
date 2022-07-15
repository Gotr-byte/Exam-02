/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:15:48 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/14 20:28:34 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : max
// Expected files   : max.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	max;
	unsigned int i;

	i = 0;
	if (tab == NULL)
		return (0);
	max = tab[0];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}

	return(max);
}

int main (void)
{
	int	tab[5];

	// tab[0] = 11;
	// tab[1] = 1;
	// tab[2] = 11;
	// tab[3] = 17;
	// tab[4] = 12;

	printf("max: %d", max (tab, 5));

}
