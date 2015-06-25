/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:08:21 by gtandeo           #+#    #+#             */
/*   Updated: 2015/06/01 12:59:31 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define BUFF_SIZE2 10000

typedef struct		s_aff
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	char			**map;
	int				bpp;
	int				s_line;
	int				endian;
	int				w;
	int				h;
	int				x;
	int				mapx;
	int				mapy;
	int				touche;
	int				wall_type;
	int				etapex;
	int				etapey;
	int				drawstart;
	int				drawend;
	int				color;
	int				hauteurmur;
	double			rotationx;
	double			translationy;
	double			posx;
	double			posy;
	double			movespeed;
	double			rotspeed;
	double			dirx;
	double			diry;
	double			olddirx;
	double			planex;
	double			planey;
	double			oldplanex;
	double			oldplaney;
	double			distmurx;
	double			distmury;
	double			dist2murx;
	double			dist2mury;
	double			wall_dist;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
}					t_aff;

int					keyboard(int keycode, t_aff *e);
int					expose_hook(t_aff *e);
void				env_init(t_aff *e);
void				player_init(t_aff *e);
void				ray_calc_init(t_aff *e);
void				struct_init(t_aff *e);
void				colors(t_aff *e);
void				ray_calc(t_aff *e);
void				ft_ray(t_aff *e);
void				draw_line(t_aff *e);
void				wall_detection(t_aff *e);
void				you_shall_not_past(t_aff *e);
void				draw(t_aff *e);
void				translate(int keycode, t_aff *e);
void				rotate(int keycode, t_aff *e);

#endif
