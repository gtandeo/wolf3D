/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:07:07 by gtandeo           #+#    #+#             */
/*   Updated: 2014/09/17 10:34:45 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw(t_aff *e)
{
	int		in;

	while (e->drawstart < e->drawend)
	{
		in = ((e->s_line * e->drawstart) + ((e->bpp >> 3) * e->x));
		e->str[in] = e->color & 0xFF;
		e->str[in + 1] = (e->color & 0xFF00) >> 8;
		e->str[in + 2] = (e->color & 0xFF0000) >> 16;
		e->drawstart++;
	}
}

void		colors(t_aff *e)
{
	if (e->map[e->mapy][e->mapx] == '1')
		e->color = 0xFF0000;
	else if (e->map[e->mapy][e->mapx] == '2')
		e->color = 0xFF0000;
	else if (e->map[e->mapy][e->mapx] == '3')
		e->color = 0xDB900E;
	else if (e->map[e->mapy][e->mapx] == '4')
		e->color = 0xFF0000;
	else if (e->map[e->mapy][e->mapx] == '5')
		e->color = 0xFF0000;
	else
		e->color = 0xFF0000;
	if (e->wall_type == 1)
		e->color /= 2;
	else if (e->wall_type == 2)
		e->color /= 4;
	else if (e->wall_type == 3)
		e->color /= 6;
	draw(e);
}
