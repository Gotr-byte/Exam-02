/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:52:28 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 12:43:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2);

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';

	return (s2); 
}

int	main (void)
{
	char *src = "ah";
	char dsr[2];
	char dsr1[2];

	// dsr = (char*)malloc((strlen(src) + 1) * sizeof(char));
	// dsr1 = (char*)malloc((strlen(src) + 1) * sizeof(char));

	ft_strcpy(src, dsr);
	strcpy(src, dsr);
	printf("ft_strcpy(%s): %s",src, dsr);
	printf("strcpy(%s): %s",src, dsr1);
	free(dsr);
	free(dsr1);
}
