/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:11:15 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/11 22:08:09 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

#define MAX_BUFFER 4096

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

// Checks to see if given input segment is a valid block by processing 
// and comparing the data to stored block items. If it is a valid block, 
// it will return the index which indicates it's appropriate block, else 
// it returns -1
int is_valid_block(char *input)
{
	int i;
	char *trimmed;

	if (input)
	{
		trimmed = ft_strchrrmv(trimmed, '\n');
		input = ft_strctrim(input, '.');
		while (i <= 19)
		{
			if (ft_strcmp(trimmed, g_blockdefine[i]))
				return (i);
		}
	}
	return (-1);
}

char **build_block(char *ref, char *input)
{
	char **block_array = NULL;
	//Build and add t_piece to array of pointers
	
	return (block_array);
}

int read_file(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File missing or invalid.\n");
		return (0);
	}
	else
	{
		
	}
	return (1);
}
