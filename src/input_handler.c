/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/18 15:26:27 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

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

t_piece	*make_piece(char *input, int label)
{
	(void)input;
	t_piece *piece = (t_piece *)malloc(sizeof(t_piece));
	piece->label = label;
	piece->placed = 0;
	return (piece);
}

t_piece *process_input(char *filename)
{
	int 	fd;
	int		ret;
	int		in_ct;
	size_t	max_buf;
	size_t	cur_buf;
	//char 	**input;
	t_piece *pieces = NULL;

	ret = 1;
	in_ct = 0;
	max_buf = 126;
	cur_buf = 0;
	char *buffer = ft_memalloc(max_buf);
	fd = open_file(filename);
	if (fd == 0)
		return (NULL);
	while (ret)
	{
		cur_buf += 21;
		if (max_buf <= cur_buf)
		{
			ft_putstr("Reallocating...\n");
			buffer = (char *)ft_realloc(buffer, &max_buf);	
		}
		ret = read(fd, buffer, 21);	
		if (ret == -1)
		{
			ft_putstr("Read error occured.\n");
			return (NULL);
		}
		ft_putstr(buffer);
	}
	//pieces = (t_piece *)ft_memset(pieces, 0, ct_pieces(buffer) + 1);
	
	return (pieces);
}
