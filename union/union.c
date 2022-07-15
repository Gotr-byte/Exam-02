/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:34:46 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/15 10:38:25 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.
// The display will be in the order characters appear in the command line, and
// will be followed by a \n.
// If the number of arguments is not 2, the program displays \n.
// Example:
// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

void check_former_1(char *av, char current, int pos)
{
	while(pos >= 0)
	{
		pos--;
		if (current == av[pos])
			return ;
	}
	write(1, &current, 1);
}

int check_former_2(char *av2, char current2, int pos)
{
	while(pos >= 0)
	{
		pos--;
		if (current2 == av2[pos])
			return (0);
	}
	return(1);
}

int main (int ac, char **av)
{
	if(ac == 3)
	{
		int	 	i;
		int 	j;

		i = 1;
		j = 0;
		write(1, &av[1][0], 1);
		while (av[1][i] != '\0')
			{
				check_former_1(&av[1][0], av[1][i], i);
				i++;
			}
		check_former_1(&av[1][0], av[2][j], i);
		j++;
		while (av[2][j] != '\0')
			{
				if (check_former_2(&av[2][0], av[2][j], j))
					check_former_1(&av[1][0], av[2][j], i);
				j++;
			}
	}
	write(1, "\0",1);
}