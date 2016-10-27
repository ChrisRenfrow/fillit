/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/27 14:56:23 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fillit.h"

#define PIECEBYTES 21

/*
** Converts the int array obtained from bitmath into an array of
** unsigned long longs where each index of the array represents
** a row of the piece.
*/

t_ull		*ft_btoull(int *bin)
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

/*
** Initalizes the piece struct.
*/

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
	piece.shift = 0;
	piece.mrow = 0;
	return (piece);
}

/*
** Initializes i, max_buf, cur_buf, and label for the process_input function.
*/

char	initializer(int *i, size_t *buf)
{
	*(i + 2) = 0;
	*buf = PIECEBYTES * 26;
	*(buf + 1) = 0;
	return ('A');
}

int		check_nl_ct(char *input)
{
	int i;
	
	i = 0;
	while (input[i])
	{
		if (i % 5 == 4 && input[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** ops[] = { vb, ret, i }
** buffs[] = { max_buf, cur_buf }
*/

t_piece		*process_input(t_puzz *legend, int fd)
{
	int		op[3];
	size_t	buffs[2];
	char	buffer[PIECEBYTES + 1];
	t_piece	*pieces;
	char	label;

	label = initializer(op, buffs);
	legend->pnbr = 0;
	if (!(pieces = (t_piece *)ft_memalloc(sizeof(t_piece) * (26 + 1))))
		return (NULL);
	while ("pokemon go is dead")
	{
		buffs[1] += PIECEBYTES;
		if (buffs[1] > buffs[0])
			return (freer((void *)pieces));
		if ((op[1] = read(fd, buffer, PIECEBYTES)) == -1)
			return (freer((void *)pieces));
		if (!check_nl_ct(buffer))
			return (freer((void *)pieces));
		if ((op[0] = is_valid_block(buffer)) >= 0)
			pieces[op[2]++] = make_piece(buffer, label++);
		if (op[0] < 0 || op[1] == 0)
			return (freer((void *)pieces));
		legend->pnbr++;
		if (op[1] == 20)
			return (pieces);
	}
}
