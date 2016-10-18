/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmapvisual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:29:42 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/12 23:29:05 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>

/*
** Used to visulaize how the bit map operators work with each other.
** Establish the square size 
*/

int	g_sq_size = 0;
int	g_shift;		//g_shift is the offset each piece has in the puzzle
int	g_eb_max;		//max number empty blocks.

int	ft_sqrt(int nbr)
{
	int	result;

	result = 1;
	while ((result * result) < nbr)
		result++;
	return (result);
}


t_ull	*eb_calculator(t_piece *pieces, t_ull *map, int pnbr)
{
	int	eb_nbr;
	int	pu;

	pu = 0;
	eb_nbr = 0;
	g_eb_max = (g_sq_size * g_sq_size) - (4 * pnbr);
	map = (t_ull *)ft_memalloc(sizeof(t_ull) * g_sq_size);
	map = fit_pieces(pieces, map, eb_nbr, pnbr); 
	while (pu < pnbr)
	{
		printf("inside eb");
		if (pieces[pu].placed == 0)
			break;
		if (++pu == pnbr)
			return (map);
	}
	ft_memdel((void *)&map);
	g_sq_size++;
	map = eb_calculator(pieces, map, pnbr);
	return (map);
}

t_ull	*map_maker(t_piece *pieces, int pnbr)
{
	t_ull	*map;

	g_sq_size = ft_sqrt(4 * pnbr);
	g_shift = 0;
	map = NULL;
	map = eb_calculator(pieces, map, pnbr);
	return (map);
}

static void	print_row(t_ull row, int columns)
{
	ft_putstr(ft_strrev(ft_bitstoa(row, columns)));
}

int			main(void)
{
	t_piece	square;
	t_piece	vz;
	t_piece	hi;
	t_piece	*array;
	t_ull	*map;
	int		piece_nbr;
	int		map_size;

	vz.r1 = 3;
	vz.r2 = 6;
	vz.r3 = 0;
	vz.r4 = 0;
	vz.placed = 0;
	vz.label = 'A';

	square.r1 = 24;
	square.r2 = 24;
	square.r3 = 0;
	square.r4 = 0;
	hi.placed = 0;
	square.label = 'B';

	hi.r1 = 30;
	hi.r2 = 0;
	hi.r3 = 0;
	hi.r4 = 0;
	hi.placed = 0;
	hi.label = 'C';

	array = (t_piece *)ft_memalloc(sizeof(t_piece) * 3);
	array[0] = hi;
	array[1] = vz;
	array[2] = hi;

	piece_nbr = 3;
	map_size = ft_sqrt(4 * piece_nbr);
	map = map_maker(array, piece_nbr);

	printf("2 to the 31th:%llu 2 to the 6th:%llu 2 to the 0:%llu\n",ft_power(2, 31),ft_power(2, 6),ft_power(2, 8));
	ft_putstr("array[0].row1 binary:");
	print_row(array[0].r1, map_size);
	ft_putchar('\n');
	ft_putstr("array[0].row2 binary:");
	print_row(array[0].r2, map_size);
	ft_putchar('\n');
	ft_putstr("array[0].row3 binary:");
	print_row(array[0].r3, map_size);
	ft_putchar('\n');
	ft_putstr("array[0].row4 binary:");
	print_row(array[0].r4, map_size);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("row1 binary:");
	print_row(array[1].r1, map_size);
	ft_putchar('\n');
	ft_putstr("row2 binary:");
	print_row(array[1].r2, map_size);
	ft_putchar('\n');
	ft_putstr("row3 binary:");
	print_row(array[1].r3, map_size);
	ft_putchar('\n');
	ft_putstr("row4 binary:");
	print_row(array[1].r4, map_size);
	ft_putchar('\n');
	ft_putchar('\n');
	if ((0 == (array[0].r1 & array[1].r1)) && (0 == (array[0].r2 & array[1].r2)) 
			&& (0 == (array[0].r3 & array[1].r3)) && (0 == (array[0].r4 & array[1].r4)))
	{
		*map = array[0].r1 ^ array[1].r1;
		*(map + 1) = array[0].r2 ^ array[1].r2;
		*(map + 2) = array[0].r3 ^ array[1].r3;
		*(map + 3) = array[0].r4 ^ array[1].r4;
	}
	piece_nbr = 0;
	while (piece_nbr++ < map_size)
	{
		ft_putstr("reuslt:");
		print_row(*map++, map_size);
		ft_putchar('\n');
	}

/*
** Think about calling the XOR operation within a function call. Possibly have
** 4 functions going at once, one for each row.
*/
}
