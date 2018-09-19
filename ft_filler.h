/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 12:00:36 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/07/04 12:00:40 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define	FT_FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_filler
{
	char	t_player;
	int		map_y;
	int		map_x;
	int		piece_y;
	int		piece_x;
	char	**map;
	char	**piece;
	char	e_piece;
	int		e_x;
	int		e_y;	
}				t_filler;

t_filler	malloc_map(t_filler data);
t_filler	malloc_piece(t_filler data);
t_filler	setup_map(t_filler data, char *line);
t_filler	setup_piece(t_filler data, char *line);
t_filler	fill_map(t_filler data, char *line);
t_filler	fill_piece(t_filler data, char *line, int fd);
int			udlr(t_filler data, int x, int y);

#endif
