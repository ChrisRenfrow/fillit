/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/25 14:55:09 by crenfrow         ###   ########.fr       */
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

t_ull *ft_btoull(int *bin)
{
	int i;
	int j;

	i = 18;
	j = 1;
	t_ull *ll = (t_ull*)malloc(sizeof(t_ull) * 4);
	while(i >= 0)
	{
		if (i % 5 == 4)
			j++;
		//else 
			ll[j] = (ll[j]<<1) + bin[i];	
		i--;
	}
	return (ll);
}

int *intobin(char *input)
{	
	int *bin;
	int i;
	int j;

	i = 0;
	j = 0;
	bin = (int *)malloc(sizeof(int) * 20);
	while(input[i])
	{	
		if (input[i] == '.')
			bin[j++] = 0;
		else if (input[i] == '#')
			bin[j++] = 1;
		i++;
	}
	return (bin);
}

t_ull *piece_shift(t_ull *row)
{
	int i;
	//int j;

	i = 0;
	while (i < 3)
	{
		if (row[i] == 0)
		{
			row[i] = row[i + 1];
			row[i + 1] = 0;
		}	
		i++;
	}/*
	while ("ur mom")
	{
		j = 0;
		while (j < 4)
		{
			if (row[j] % 2 != 0)
				return row;
			j++;	
		}
		i = 0;
		while (i < 4)
		{
			row[i] = row[i]>>1;
			i++;
		}
	}
	*/
	return (row);
}

t_piece	make_piece(char *input, int label)
{
	// Need to do math to make bit-map version of the piece 
	int *tmp = intobin(ft_strctrim(input, '.'));
	t_ull *tmpull = ft_btoull(tmp);
	tmpull = piece_shift(tmpull);
	int i = 4;
	int j = 0;
	puts("- Input -\n");
	while(j < 20)
	{
		if (j % 5 == 4)
		{
			//j++;
			ft_putchar('\n');
		}
		else
			ft_putchar(input[j]);
		j++;
	}
	puts("- Binary to ULL -\n");
	while (i)
	{
		printf("Row: %d Value: %llu\n", -(i - 4), tmpull[i]);
		i--;
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
			ft_putstr("Fuck you and all your mom.\n");
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
