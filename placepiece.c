/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:53:00 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/07/06 08:53:02 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

t_filler	placepiece(t_filler data, int x, int y)
{
	if (udlr == 0)
	{
		if (data.piece_y < data.map_y - y)
			if (data.piece_x < (data.map_x - x))
				//PLACE THAT SHIT
	}
	if (uldr == 1)
	{
		if (data.piece_y < data.map_y - y)
			if (data.piece_x < x)
				//PLACE THAT SHIT
	}
	if (uldr == 2)
	{
		if (data.piece_y < y)
			if (data.piece_x < (data.map_x - x))
				//PLACE THAT SHIT
	}
	if (uldr == 3)
	{
		if (data.piece_y < y)
			if (data.piece_x < x)
				//PLACE THAT SHIT
	}
}

int		udlr(t_filler data, int x, int y)
{
	if (y < data.e_y && x < data.e_x)
		return (0);//move down and right
	if (y < data.e_y && x > data.e_x)
		return (1);//move down and left
	if (y > data.e_y && x < data.e_x)
		return (2);//move up and right
	if (y > data.e_y && x > data.e_x)
		return (3);//move up and left
}