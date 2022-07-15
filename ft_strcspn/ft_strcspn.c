/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:23:36 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/13 09:54:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------
// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

#include <string.h>
#include <stdio.h>
#include <unistd.h>

int ft_check_reject(char froms,char *reject)
{
	int n;

	n = 0;
	while(reject[n] != '\0')
	{
		if (reject[n] == froms)
			return (1);
		n++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	char	*set;

	set = (char *)reject;
	i = 0;
	while (ft_check_reject(s[i], set) != 0)
		i++;
	return(i);
}


int main(void)
{
	char *str1;
	char *str2;

	str1 = "sWildHogs";
	str2 = "ildHWs";

	printf("strspn: %lu", strspn(str1, str2));	
	printf("ft_strspn: %lu", ft_strcspn(str1, str2));	
}