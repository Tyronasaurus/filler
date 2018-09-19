/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 12:01:06 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/07/04 12:01:07 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

t_filler	malloc_piece(t_filler data)
{
	int y;

	y = 0;
	data.piece = (char **)malloc(sizeof(char *) * data.piece_y + 1);
	while (y < data.piece_y)
	{
		data.piece[y] = (char *)malloc(sizeof(char) * data.piece_x + 1);
		y++;
	}
	return (data);
}


t_filler	fill_piece(t_filler data, char *line, int fd)
{
	int		y;

	y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		ft_strcpy(data.piece[y], line);
		y++;
	}
	return (data);
}

t_filler	x_piece_size(t_filler data, char *line, int i)
{
	int		num;
	char	*x;

	num = 0;
	x = (char *)malloc(sizeof(char));
	while (line[i] != ' ')
	{
		x[num] = line[i];
		num++;
		i++;
	}
	x[num] = '\0';
	data.piece_x = atoi(x);
	return (data);
}

t_filler	y_piece_size(t_filler data, char *line, int i)
{
	int		num;
	char	*y;

	num = 0;
	y = (char *)malloc(sizeof(char));
	while (line[i] != ' ')
	{
		y[num] = line[i];
		num++;
		i++;
	}
	y[num] = '\0';
	data.piece_y = atoi(y);
	i++;
	data = x_piece_size(data, line, i);
	return (data);
}

t_filler	setup_piece(t_filler data, char *line)
{
	int		i;
	
	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	data = y_piece_size(data, line, i);
	return (data);
}
