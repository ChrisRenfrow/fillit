/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:23:28 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/06 19:32:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Pseudo code: 22: if not exactly one argument activate function to print usage
** 25: Input validation function, tie it in with reading the pieces.
** 26: Send pieces and number of pieces into the puzzle solver.
*/

int	main(int argc, char **argv)
{
	t_piece	**pieces;
	char	**puzzle;
	int		piecenbr;

	if (argc == 2)	
	{
		pieces = ft_input_validator(argv[1], &piecenbr);
		puzzle = ft_fillit(pieces, piecenbr);	
		ft_print(puzzle);
	}
	else
		ft_fillit_usage;
	return (0);	
}
