/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:36:51 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 16:57:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int result;
	int n;

	n = 1;
	i = 0;
	result = 0;

	if (str[0] == '-')
	{
		n = -1;
	}
	while (str[i] != '\0')
	{
		result = result * str_base;
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result + str[i] - 48;
		}
		if (str[i] >= 'a' && str[i]<= 'f')
			result = result + str[i] - 87;
		if (str[i] >= 'A' && str[i] <= 'F')
			result = result + str[i] -55;
		i++;
	}
	return (result * n);
}

int main()
{
	printf("hexval: %d", ft_atoi_base("1a", 16));
}