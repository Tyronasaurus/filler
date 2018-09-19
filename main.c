/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 12:00:54 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/07/04 12:00:56 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <stdio.h>

int		ft_strstr_int(const char *str, const char *word)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	if (word[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		j = i;
		c = 0;
		while (str[j] == word[c])
		{
			j++;
			c++;
			if (word[c] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

t_filler	set_player_type(t_filler data, char num)
{
	if (num == '1')
	{
		data.t_player = 'O';
		data.e_piece = 'X';
	}
	else
	{
		data.t_player = 'X';
		data.e_piece = 'O';
	}
	return (data);
}

char		*fill_player(char *player, char *line, int i)
{
	int		k;
	char	c;

	k = 0;
	c = line[i];
	while (c != ']')
	{
		c = line[i];
		player[k] = c;
		i++;
		k++;
	}
	return (player);
}

t_filler	get_player(t_filler data, char *line)
{
	char	c;
	char	num;
	char	*player;
	int		i;

	i = 0;
	c = line[i];
	num = c;
	player = (char *)malloc(ft_strlen(line) * sizeof(char *));
	while (c != '\n' && c != 'P' && i < (int)ft_strlen(line))
	{
		c = line[i];
		if (c == '1' || c == '2')
			num = c;
		if (c == '[')
		{
			player = fill_player(player, line, i);
			if (ft_strstr_int(player, "tyron.filler"))
				data = set_player_type(data, num);
		}
		i++;
	}

	return (data);
}

int		main (void)
{
	static t_filler	data;
	int				fd;
	char			*line;

	fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_strstr(line, "./filler_vm"))
			data = get_player(data, line);
		else if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			printf("GOT MAP\n");
			data = malloc_map(data);
			printf("MALLOC'D MAP\n");
			data = setup_map(data, line);
			data = fill_map(data, line);
			printf("FILLED MAP\n");
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			printf("SETUP PIECE\n");
			data = malloc_piece(data);
			data = fill_piece(data, line, fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}
