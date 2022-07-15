/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:51:13 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/12 20:09:19 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : do_op
// Expected files   : *.c, *.h
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 4)
	{
		int a;
		int b;
		int result;
		char op;

		a = atoi(argv[1]);
		b = atoi(argv[3]);
		op = argv[2][0];
		result = 0;
		if (op == '+')
		{
			result = a + b;
		}
		else if (op == '-')
		{
			result = a - b;
		}
		else if (op == '*')
		{
			result = a * b;
		}
		else if (op == '/')
		{
			result = a / b;
		}
		else if (op == '%')
		{
			result = a % b;
		}
		printf("%d", result);
	}
	write(1, "\0", 1);
}