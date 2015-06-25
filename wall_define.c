/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:07:52 by gtandeo           #+#    #+#             */
/*   Updated: 2014/09/17 10:31:22 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		wall_detection(t_aff *e)
{
	e->touche = 0;
	if (e->raydirx < 0)
	{
		e->etapex = -1;
		e->distmurx = (e->rayposx - e->mapx) * e->dist2murx;
	}
	else
	{
		e->etapex = 1;
		e->distmurx = (e->mapx + 1.0 - e->rayposx) * e->dist2murx;
	}
	if (e->raydiry < 0)
	{
		e->etapey = -1;
		e->distmury = (e->rayposy - e->mapy) * e->dist2mury;
	}
	else
	{
		e->etapey = 1;
		e->distmury = (e->mapy + 1.0 - e->rayposy) * e->dist2mury;
	}
}

void		you_shall_not_past(t_aff *e)
{
	e->wall_type = 0;
	while (e->touche == 0)
	{
		if (e->distmurx < e->distmury)
		{
			e->distmurx += e->dist2murx;
			e->mapx += e->etapex;
			if (e->etapex < 0)
				e->wall_type = 0;
			else
				e->wall_type = 2;
		}
		else
		{
			e->distmury += e->dist2mury;
			e->mapy += e->etapey;
			if (e->etapey < 0)
				e->wall_type = 1;
			else
				e->wall_type = 3;
		}
		if (e->map[e->mapx][e->mapy] != '0')
			e->touche = 1;
	}
}
