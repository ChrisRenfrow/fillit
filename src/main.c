/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:16:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/27 14:47:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

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
** frees the pointer and returns NULL.
*/

void	*freer(void *ptr)
{
	free(ptr);
	return (NULL);
}

/*
** Opens the input file, and starts the process for creating the pieces.
*/

t_piece	*read_pieces(char *filename, t_puzz *legend)
{
	t_piece	*pieces;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || !(pieces = process_input(legend, fd)))
		return (NULL);
	if (close(fd) == -1)
		return (freer(pieces));
	return (pieces);
}

/*
** flag == 1: Check to see if the globals were malloced or not.
** flag == 0: Print error and return 1.
*/

int		init_protect(void **ptr, size_t size, int flag)
{
	int i;

	i = 0;
	if (flag == 1)
	{
		while (i < (int)size)
			if (!ptr[i++])
				return (0);
	}
	else
		ft_putendl("error");
	return (1);
}

int		main(int argc, char **argv)
{
	t_piece	*pieces;
	t_puzz	legend;
	int		i;

	if (argc != 2)
		ft_putendl("usage: ./fillit [file-name]");
	else
	{
		init_blockdefine();
		if (!(init_protect((void **)g_blockdefine, 19, 1)))
		{
			i = 0;
			while (i < 19)
				free(g_blockdefine[i++]);
			return (init_protect((void **)g_blockdefine, 19, 0));
		}
		if (!(pieces = read_pieces(argv[1], &legend)))
			return (init_protect((void **)g_blockdefine, 19, 0));
		legend.sq_size = ft_sqrt(4 * legend.pnbr);
		solve_puzzle(pieces, &legend);
		ft_memdel((void *)legend.map);
		ft_memdel((void *)&pieces);
	}
	return (0);
}
