/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:26:03 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/16 19:59:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:
#include <limits.h>
int digs(int nbr)
{
	int len;

	nbr = nbr;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return(len);
}

void append

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;
	int		nbr;

	if (nbr == 0)
	{
		result = (char*)malloc(2*sizeof(char));
		if(!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (nbr < 0)
	{
		result = (char*)malloc(digs(nbr) * sizeof(char) + 2 * sizeof(char));
		if(!result)
			return (NULL);
		result[0] = '-'
		nbr = nbr * (-1);
	}

	while(len--)
	{
		result[len] = nbr % 10;
		nbr = nbr / 10
	}
}