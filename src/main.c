/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:16:18 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/26 14:20:11 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*pieces;
	t_puzz	legend;

	if (argc != 2)
		ft_putendl("usage: ./fillit [file-name]");
	else
	{
		if (!(pieces = process_input(argv[1], &legend)))
		{
			ft_putendl("error");
			return (-1);
		}
		legend.sq_size = ft_sqrt(4 * legend.pnbr);
		initializer(pieces, &legend);
		ft_memdel((void *)legend.map);
		ft_memdel((void *)&pieces);
	}
	return (0);
}
