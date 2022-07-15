/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:52:46 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 22:09:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);

int    ft_strcmp(char *s1, char *s2)
{
	// int		ret;
	int		i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
		{
			i++;
		}
	return(s1[i] - s2[i]);
}
#include <string.h>
#include <stdio.h>

int main ()
{
	char *plus;
	char *minus;

	plus = "aa";
	minus = "aa";
	
	printf("strcmp: %d\n", strcmp (plus, minus));
	printf("ft_strcmp: %d\n", ft_strcmp (plus, minus));
}

