/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 23:27:10 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/18 23:14:14 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_piece *process_input(char *filename);

int main(int argc, char *argv[])
{
	(void)argc;

	t_piece *ptr = process_input(argv[1]);
	while (ptr->label)
	{
		ft_putchar(ptr->label);
		ft_putchar('\n');
		ptr++;
	}
	return (0);
}
