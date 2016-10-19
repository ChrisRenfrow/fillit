/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/19 13:06:40 by crenfrow         ###   ########.fr       */
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
	// Need to do math to make bit-map version of the piece
	// through the passed input.
	(void)input;

	t_piece *piece = (t_piece *)malloc(sizeof(t_piece));
	piece->placed = 0;
	piece->order = -1; // -1 if not determined
	piece->label = label;
		// Assign values to r[4] and a[4]
	return (piece);
}

t_piece *process_input(char *filename)
{
	int 	fd;
	int		ret;
	int 	i;
	size_t	max_buf;
	size_t	cur_buf;
	t_piece **pieces = (t_piece **)ft_memalloc(sizeof(t_piece *) * (26 + 1));
	char 	label;

	ret = 1;
	i = 0;
	max_buf = 21 * 26;
	cur_buf = 0;
	label = 'A';
	char *buffer = ft_memalloc(max_buf);
	fd = open_file(filename);
	if (fd == 0)
		return (NULL);
	while (ret)
	{
		cur_buf += 21;
		if (cur_buf > max_buf)
		{
			ft_putstr("Fuck you and all your pieces.\n");
			free(buffer);
			free(pieces);
			return (NULL);
		}
		ret = read(fd, buffer, 21);
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
	}	
	return (*pieces);
}
