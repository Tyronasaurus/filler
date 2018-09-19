/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 10:22:33 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/30 11:02:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <stdio.h>

t_filler	malloc_map(t_filler data)
{
	int y;

	y = 0;
	data.map = (char **)malloc(sizeof(char *) * data.map_y + 1);
	while (y < data.map_y)
	{
		data.map[y] = (char *)malloc(sizeof(char) * data.map_x + 1);
		y++;
	}
	return (data);
}

t_filler	fill_map(t_filler data, char *line)
{
	int				x;
	static int		y = 0;
	char			*nline;
	printf("ENTERS FILL MAP\n");
	x = 0;
	nline = (char *)malloc(sizeof(char *) * data.map_x + 1);
	while (ft_isdigit(line[x]) || line[x] == ' ')
		x++;
	nline = ft_strsub(line, x, data.map_x);
	printf("%s\n", nline);
	ft_strcpy(data.map[y], nline);
	y++;
	data = setup_piece(data, line);
	return (data);
}

t_filler	x_size(t_filler data, char *line, int i)
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
	data.map_x = atoi(x);
	return (data);
}

t_filler	y_size(t_filler data, char *line, int i)
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
	data.map_y = atoi(y);
	i++;
	data = x_size(data, line, i);
	return (data);
}

t_filler	setup_map(t_filler data, char *line)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	data = y_size(data, line, i);
	return (data);
}
