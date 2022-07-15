/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:29:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 21:49:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:
#include <stdio.h>

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int result;

	result = 0;
	i = 0;
	neg = 1;
	while (str[i] <= 32)
		i++;
	if(str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if(str[i] == '+')
	{
		i++;
	} 
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * neg) ;
}

int main ()
{
	char *str;

	str = "     -111";
	printf("%d", ft_atoi(str));

}