/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:06:56 by gtandeo           #+#    #+#             */
/*   Updated: 2015/06/01 13:18:10 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			keyboard(int keycode, t_aff *e)
{
	translate(keycode, e);
	rotate(keycode, e);
	if (keycode == 53)
		exit(0);
	expose_hook(e);
	return (0);
}

void		translate(int keycode, t_aff *e)
{
	if (keycode == 126)
	{
		if (e->map[(int)(e->posx + e->dirx * e->movespeed)]
					[(int)(e->posy)] == '0')
			e->posx += e->dirx * e->movespeed;
		if (e->map[(int)(e->posx)]
					[(int)(e->posy + e->diry * e->movespeed)] == '0')
			e->posy += e->diry * e->movespeed;
	}
	if (keycode == 125)
	{
		if (e->map[(int)(e->posx - e->dirx * e->movespeed)]
					[(int)(e->posy)] == '0')
			e->posx -= e->dirx * e->movespeed;
		if (e->map[(int)(e->posx)]
					[(int)(e->posy - e->diry * e->movespeed)] == '0')
			e->posy -= e->diry * e->movespeed;
	}
}

void		rotate(int keycode, t_aff *e)
{
	double		olddirx;
	double		oldplanex;

	if (keycode == 124)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(-(e->rotspeed)) - e->diry * sin(-(e->rotspeed));
		e->diry = olddirx * sin(-(e->rotspeed)) + e->diry * cos(-(e->rotspeed));
		oldplanex = e->planex;
		e->planex = e->planex * cos(-(e->rotspeed)) -
					e->planey * sin(-(e->rotspeed));
		e->planey = oldplanex * sin(-(e->rotspeed)) +
					e->planey * cos(-(e->rotspeed));
	}
	if (keycode == 123)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
		e->diry = olddirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
		oldplanex = e->planex;
		e->planex = e->planex * cos(e->rotspeed) - e->planey * sin(e->rotspeed);
		e->planey = oldplanex * sin(e->rotspeed) + e->planey * cos(e->rotspeed);
	}
}
