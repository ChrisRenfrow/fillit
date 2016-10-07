/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_squareprototype.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 10:07:16 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/06 11:27:39 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prototype for calculating the minimum square possible and number of empty
** blocks that will result based on the number of tetriminos.
*/

int	ft_sqrt(int nbr)
{
	int	result;

	result = 1;
	while ((result * result) < nbr)
		result++;
	return (result);
}


int	square_calc(int tetr)
{
	int	sq;
	int	eb;

	sq = ft_sqrt(4 * tetr);
	eb = (sq * sq) - (4 * tetr);
	ft_putstr("Minimial square size:");
	ft_putnbr(sq);
	ft_putchar('\n');
	ft_putstr("Number of empty blockse:");
	ft_putnbr(eb);
	ft_putchar('\n');
	return (sq);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		square_calc(ft_atoi(argv[1]));
	return (0);
}
