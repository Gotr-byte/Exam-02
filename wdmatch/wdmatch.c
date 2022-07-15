/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:30:11 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 11:55:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------
// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.
// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.
// If the number of arguments is not 2, the program displays a \n.
// Examples:
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int count;
		int i;
		int j;
		int flag;

		i = 0;
		j = 0;
		flag = 0;
		count = 0;

		while (av[1][flag] != '\0')
			flag++;

		while (av[1][i] != '\0')
		{
			// check()
			// j = 0;
			while(av[2][j] != '\0')
			{
				if (av[1][i] == av[2][j])
				{
					count++;
					break;
				}
				j++;
			}
			i++;
		}

		if (count == flag)
		{
			i = 0;
			while (av[1][i] != '\0')
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n",1);
}