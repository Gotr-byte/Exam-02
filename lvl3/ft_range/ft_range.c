/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:54:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 18:17:45 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <unistd.h>
#include <stdlib.h>

int ft_abs(int val)
{
	if (val < 0)
	{
		val = val * (-1);
	}
	return (val);
}


// int     *ft_range(int start, int end)
void	ft_range(int start, int end)
{
	int *arr;
	int i;

	i = 0;
	arr = (int*)malloc((ft_abs(end - start) + 1) * sizeof(int));

	if (end >= start)
	{
		while (i <= (ft_abs(end - start) + 1))
		{
			arr[i] = start + i;
			write (1, &arr[i], 1);
			i++;
		}
	}
	else if (end <= start)
	{
		while (i <= (ft_abs(end - start) + 1))
		{
			arr[i] = start - i;
			write (1, &arr[i], 1);
			i++;
		}
	}
	// return (arr);
}

int main(void)
{
	ft_range(1, 3);
}