/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/25 16:24:07 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#include <stdio.h>

#define PIECEBYTES 21
/*
int ft_strctchr(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
*/
int open_file(char *filename)
{
	int fd;
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
	if(!(ll = (t_ull*)ft_memalloc(sizeof(t_ull) * 4)))
		return (NULL);
	while(i < 20)
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

t_ull	*bitmath(char *input)
{	
	int 	*bin;
	t_ull	*tmpull;
	int 	i;

	i = 0;
	if (!(bin = (int *)ft_memalloc(sizeof(int) * 20)))
			return (NULL);
	while(i < 20)
	{	
		if (input[i] == '.')
			bin[i++] = 0;
		else if (input[i] == '#')
			bin[i++] = 1;
	}
	if (!(tmpull = ft_btoull(bin)))
	{
		free(bin);
		return (NULL);
	}
	tmpull = shift_piece(tmpull);
	return (tmpull);
}

t_piece	make_piece(char *input, int label)
{
	// Need to do math to make bit-map version of the piece
	t_ull *tmpull = bitmath(input);
	int i = 0;
	int j = 0;
	puts("- Input -\n");
	//puts(input);
	while(j < 20)//
	{
		if (j % 5 == 4)//
		{
			//j++;
			ft_putchar('\n');//
		}
		else
			ft_putchar(input[j]);//
		j++;//
	}
	puts("- Binary to ULL -\n");
	while (i < 4)
	{
		printf("Row: %d Value: %llu\n", i + 1, tmpull[i]);
		i++;
	}	
	t_piece piece;
	piece.placed = 0;
	piece.order = -1; // -1 if undetermined
	piece.label = label;
	return (piece);
}

t_piece *process_input(char *filename)
{
	int 	fd;
	int		ret;
	int 	i;
	size_t	max_buf;
	size_t	cur_buf;
	t_piece *pieces = (t_piece *)ft_memalloc(sizeof(t_piece) * (26 + 1));
	char 	label;

	ret = 1;
	i = 0;
	max_buf = PIECEBYTES * 26;
	cur_buf = 0;
	label = 'A';
	char *buffer = ft_memalloc(PIECEBYTES + 1);
	fd = open_file(filename);
	if (fd == 0)
		return (NULL);
	while (ret)
	{
		cur_buf += PIECEBYTES;
		if (cur_buf > max_buf)
		{
			ft_putstr("Fuck you and all your pieces.\n");
			free(buffer);
			free(pieces);
			return (NULL);
		}
		ret = read(fd, buffer, PIECEBYTES);
		if (ret == -1)
		{
			ft_putstr("Read error occured.\n");
			return (NULL);
		}
		if (is_valid_block(buffer) >= 0)
		{
			pieces[i] = make_piece(buffer, label++);
			i++;
		}
		if (ret == 20)
			return (pieces);	
	}	
	return (pieces);
}
