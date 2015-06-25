/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:07:35 by gtandeo           #+#    #+#             */
/*   Updated: 2014/05/11 02:13:41 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		struct_init(t_aff *e)
{
	env_init(e);
	player_init(e);
	ray_calc_init(e);
}

void		env_init(t_aff *e)
{
	e->w = 1000;
	e->h = 700;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w, e->h, "Wolf3D");
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
}

void		player_init(t_aff *e)
{
	e->posx = 11.0001;
	e->posy = 19.0001;
}

void		ray_calc_init(t_aff *e)
{
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->movespeed = 0.2;
	e->rotspeed = 0.1;
}
