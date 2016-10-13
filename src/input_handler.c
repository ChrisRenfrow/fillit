/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/12 23:54:48 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define MAX_BUFFER 4096
#define B(i) g_blockdefine[i]
#define C(x, y) ft_strcmp(x, y)
#define IS_PIECE(input, index)while(B(index)){if(C(input, B(index)){index++;})}
// ADD TO LIBRARY AT YOUR DISCRETION
// Counts instances of specific char in string and returns the int value of 
// occurences
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

// PLEASE ADD TO LIBRARY
// Removes char from string and returns new string
char	*ft_strchrrmv(char *str, char c)
{
	int newlen;
	int i;
	int j;
	newlen = ft_strlen(str) - ft_strctchr(str, c);
	char *new = (char *)malloc(sizeof(char) * (newlen + 1));

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[j++] = str[i++];
		i++;
	}
	return (new);
}

// PLEASE ADD TO LIBRARY
// Same as ft_strtrim but instead only trims a specific char
char	*ft_strctrim(char *str, char c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (*str == c)
		str++;
	while (str[i])
		i++;
	i--;
	while (str[i] == c && i >= 0)
		i--;
	res = ft_strsub(str, 0, i + 1);
	if (res)
		return (res);
	else
		return (NULL);
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
	t_piece *piece = (t_piece *)malloc(sizeof(t_piece));
	piece->label = label;
	piece->placed = 0;
	return (piece);
}

t_piece *process_input(char *filename)
{
	int 	fd;
	int		ret;
	char 	buffer[MAX_BUFFER + 1];
	t_piece *pieces = NULL;

	fd = open_file(filename);
	if (fd == 0)
		return (NULL);
	ret = read(fd, buffer, MAX_BUFFER);
	if (ret == -1)
	{
		ft_putstr("Read error occured.\n");
		return (NULL);
	}
	pieces = (t_piece *)ft_memset(pieces, 0, ct_pieces(buffer) + 1);
	

	return (pieces);
}
