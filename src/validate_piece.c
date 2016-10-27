/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 18:03:53 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/26 19:41:03 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*g_blockdefine[20];

void	init_blockdefine(void)
{
	g_blockdefine[0] = ft_strdup("####");
	g_blockdefine[1] = ft_strdup("#....#....#....#");
	g_blockdefine[2] = ft_strdup("#....###");
	g_blockdefine[3] = ft_strdup("##...#....#");
	g_blockdefine[4] = ft_strdup("###....#");
	g_blockdefine[5] = ft_strdup("#....#...##");
	g_blockdefine[6] = ft_strdup("#..###");
	g_blockdefine[7] = ft_strdup("#....#....##");
	g_blockdefine[8] = ft_strdup("##....#....#");
	g_blockdefine[9] = ft_strdup("##...##");
	g_blockdefine[10] = ft_strdup("##..##");
	g_blockdefine[11] = ft_strdup("#....##....#");
	g_blockdefine[12] = ft_strdup("###..#");
	g_blockdefine[13] = ft_strdup("#...###");
	g_blockdefine[14] = ft_strdup("#....##...#");
	g_blockdefine[15] = ft_strdup("###...#");
	g_blockdefine[16] = ft_strdup("#...##....#");
	g_blockdefine[17] = ft_strdup("##....##");
	g_blockdefine[18] = ft_strdup("#...##...#");
	g_blockdefine[19] = 0;
}

char	*ft_strchrrplc(char *str, int c_a, int c_b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c_a)
			str[i] = c_b;
		i++;
	}
	return (str);
}

int		is_piece(char *input)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (!ft_strcmp(input, g_blockdefine[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		ct_pieces(char *input)
{
	int nl;
	int ct;

	nl = 0;
	ct = 0;
	while (input++)
	{
		if (*input == '\n')
			nl++;
		if (nl == 5)
		{
			ct++;
			nl = 0;
		}
	}
	return (ct);
}

int		is_valid_block(char *input)
{
	int result;

	result = -1;
	init_blockdefine();
	if (input)
	{
		ft_strchrrplc(input, '\n', '.');
		input = ft_strctrim(input, '.');
		result = is_piece(input);
	}
	return (result);
}
