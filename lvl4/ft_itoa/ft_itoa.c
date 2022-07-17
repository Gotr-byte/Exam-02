/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:26:03 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/17 12:55:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:
#include <stdlib.h>
#include <stdio.h>

int digs(int nbr)
{
	int len;

	len = 0;
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

int pow_ten(int len)
{
	int ret;
	
	if (len == 0)
	{
		ret = 1;
	}
	ret = 1;
	while (len--)
	{
		ret = ret * 10;
	}
	return (ret);
}

char	*ft_itoa(int nbr)
{
	int		len;
	int		len2;
	char	*result;
	int		i;

	i = 0;
	while (nbr == -2147483648)
	{
		result = "-2147483648";
		return (result);
	}

	len = digs(nbr);
	len2 = digs(nbr);
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
		result[0] = '-';
		i++;
		nbr = nbr * (-1);
		len--;
	}
	else if (nbr > 0)
	{
		result = (char*)malloc(digs(nbr) * sizeof(char) + 1 * sizeof(char));
		if(!result)
			return(NULL);
	}

	while(len--)
	{
		result[i] = (nbr / (pow_ten(len))) + '0';
		nbr = nbr % (pow_ten(len));
		i++;
	}
	result[i] = '\0';
	return (result);
}

int main(void)
{
	printf( "ft_itoa %s", ft_itoa(-1112));
}