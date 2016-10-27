/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/26 20:01:19 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define PIECEBYTES 21

int		open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File missing or invalid.\n");
		return (0);
	}
	else
		return (fd);
}

/*
** Shift_piece shifts the pieces to the top left of their grid.
*/

t_ull	*shift_piece(t_ull *tmpull)
{
	int	swap;
	int	i;

	swap = 1;
	while (swap--)
	{
		i = -1;
		while (++i < 3)
			if (tmpull[i] == 0 && tmpull[i + 1] != 0)
			{
				tmpull[i] = tmpull[i + 1];
				tmpull[i + 1] = 0;
				swap = 1;
			}
	}
	while ("mom jokes exist")
	{
		i = -1;
		while (++i < 3)
			if (tmpull[i] % 2 != 0)
				return (tmpull);
		i = -1;
		while (++i < 4)
			tmpull[i] = tmpull[i] >> 1;
	}
}

/*
** Converts the int array obtained from bitmath into an array of
** unsigned long longs where each index of the array represents
** a row of the piece.
*/

t_ull	*ft_btoull(int *bin)
{
	t_ull	*ll;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ll = (t_ull*)ft_memalloc(sizeof(t_ull) * 4)))
		return (NULL);
	while (i < 20)
	{
		if (i % 5 == 4)
			j++;
		else
			ll[j] += bin[i] << ((i % 5) * bin[i]);
		i++;
	}
	return (ll);
}

/*
** Creates an array of of 1's and 0's from the input to represent
** the bitmap for each piece. Used in combination with ft_btoull to
** return a temp ull array that will be used to load the pieces bitmap.
*/

t_ull		*bitmath(char *input)
{
	int		*bin;
	t_ull	*tmpull;
	int		i;

	i = 0;
	if (!(bin = (int *)ft_memalloc(sizeof(int) * 20)))
		return (NULL);
	while (i < 20)
	{
		if (input[i] == '.')
			bin[i++] = 0;
		else if (input[i] == '#')
			bin[i++] = 1;
	}
	tmpull = ft_btoull(bin);
	ft_memdel((void *)&bin);
	if (!(tmpull))
		return (NULL);
	tmpull = shift_piece(tmpull);
	return (tmpull);
}

t_piece		make_piece(char *input, int label)
{
	int		i;
	t_piece	piece;
	t_ull	*tmpull;

	tmpull = bitmath(input);
	i = 0;
	while (i < 4)
	{
		piece.r[i] = tmpull[i];
		piece.a[i] = tmpull[i];
		i++;
	}
	ft_memdel((void *)&tmpull);
	piece.placed = 0;
	piece.label = label;
	return (piece);
}

void		*freer(void *ptr)
{
	free(ptr);
	return (NULL);
}

/*
** ops[] = { fd, ret, i }
** buffs[] = { max_buf, cur_buf }
*/

t_piece		*process_input(char *filename, t_puzz *legend)
{	
	int		op[3];
	size_t	buffs[2];
	char	buffer[PIECEBYTES + 1];
	t_piece	*pieces;
	char	label;

	op[2] = 0;
	buffs[0] = PIECEBYTES * 26;
	buffs[1] = 0;
	label = 'A';
	legend->pnbr = 0;
	if (!(pieces = (t_piece *)ft_memalloc(sizeof(t_piece) * (26 + 1))))
		return (NULL);
	if (!(op[0] = open_file(filename)))
		return (NULL);
	while ("pokemon go is dead")
	{
		buffs[1] += PIECEBYTES;
		if (buffs[1] > buffs[0])
			return (freer((void *)pieces));
		op[1] = read(op[0], buffer, PIECEBYTES);
		if (op[1] == -1 || op[1] == 0)
			return (NULL);
		if (is_valid_block(buffer) >= 0)
			pieces[op[2]++] = make_piece(buffer, label++);
		else
			return (NULL);
		legend->pnbr++;
		if (op[1] == 20)
			return (pieces);
	}
}
