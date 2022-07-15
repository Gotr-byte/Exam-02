/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:54:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/13 10:19:55 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:
#include <string.h>
#include <printf.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int 	i;
	char	*dest;

	i = 0;
	while(src[i] == '\0')
		{
			i++;
		}

	dest = (char *)malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while(src[i] == '\0')
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';

	return (dest); 
}

int	main()
{
	// char	*to_dup;
	char	*to_dup_too;

	// to_dup = "bla";
	to_dup_too = "bla";
	// printf("ft_strdup: %s", ft_strdup(to_dup));
	// free(to_dup);
	printf("strdup: %s", strdup(to_dup_too));
	// free(to_dup_too);
}