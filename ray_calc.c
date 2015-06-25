/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:07:23 by gtandeo           #+#    #+#             */
/*   Updated: 2015/06/01 12:56:15 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ray_calc(t_aff *e)
{
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->dist2murx = sqrt(1 + pow(e->raydiry, 2) / pow(e->raydirx, 2));
	e->dist2mury = sqrt(1 + pow(e->raydirx, 2) / pow(e->raydiry, 2));
	e->touche = 0;
}

void		draw_line(t_aff *e)
{
	if (e->wall_type == 0 || e->wall_type == 2)
		e->wall_dist = fabs((e->mapx - e->rayposx +
			(1 - e->etapex) / 2) / e->raydirx);
	else
		e->wall_dist = fabs((e->mapy - e->rayposy +
			(1 - e->etapey) / 2) / e->raydiry);
	e->hauteurmur = abs((int)(e->h / e->wall_dist));
	e->drawstart = -(e->hauteurmur) / 2 + e->h / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = e->hauteurmur / 2 + e->h / 2;
	if (e->drawend >= e->h)
		e->drawend = e->h - 1;
}
