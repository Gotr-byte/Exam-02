/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:30:07 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/17 15:14:54 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:
#include <stdio.h>
#include <stdlib.h>
char    **ft_split(char *str)
{
	char	**adr_arr;
	int		i;
	int		i2;
	int		i3;

	adr_arr = (char**)malloc(1000 * sizeof(char*));

	i = 0;
	i2 = 0;
	
	while(str[i]<=32)
	{
		i++;
	}

	while(str[i] != '\0')
	{
		i3 = 0;
		if(str[i] > 32)
		{
			adr_arr[i2] = (char*)malloc(1000 * sizeof(char));
			while(str[i] > 32)
			{
				adr_arr[i2][i3] = str[i];
				i++;
				i3++;
			}
			adr_arr[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	adr_arr[i2] = 0;
	return(adr_arr);
}

int main (void)
{
	char **adr_arr;

	char	*str = "   this is  a test ";
	adr_arr = ft_split(str);
	printf("%s %s %s %s %s", adr_arr[0], adr_arr[1], adr_arr[2], adr_arr[3], adr_arr[4]);
}