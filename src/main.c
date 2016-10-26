/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:16:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/25 18:41:20 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*pieces;
	t_puzz	legend;

	if (argc != 2)
		ft_putendl("usage: ./fillit file");
	else
	{
		if(!(pieces = process_input(argv[1], &legend)))
		{
			ft_putendl("error");
			return (-1);
		}
		map_maker(pieces, &legend);
	}
	return (0);
}
