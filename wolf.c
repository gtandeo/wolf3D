/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 11:08:07 by gtandeo           #+#    #+#             */
/*   Updated: 2014/05/11 02:22:46 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			expose_hook(t_aff *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		e->drawstart = 0;
		e->drawend = e->h / 2;
		e->color = 0x5EB6DD;
		draw(e);
		e->drawstart = e->h / 2;
		e->drawend = e->h;
		e->color = 0x663E10;
		draw(e);
		e->x++;
	}
	ft_ray(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void		ft_initray(t_aff *e)
{
	e->camerax = 2 * (double)e->x / (double)e->w - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camerax;
	e->raydiry = e->diry + e->planey * e->camerax;
}

void		ft_ray(t_aff *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		ft_initray(e);
		ray_calc(e);
		wall_detection(e);
		you_shall_not_past(e);
		draw_line(e);
		colors(e);
		e->x++;
	}
}

char		**ft_parse(char *str)
{
	int		fd;
	int		ret;
	char	*buff;
	char	**map;

	fd = open(str, O_RDONLY);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE2 + 1);
	ret = read(fd, buff, BUFF_SIZE2);
	buff[ret] = '\0';
	map = ft_strsplit(buff, '\n');
	return (map);
}

int			main(int ac, char **av)
{
	t_aff		*e;

	if (ac != 2 || open(av[1], O_RDONLY) == -1)
	{
		ft_putstr("Please enter a valid map\n");
		exit(0);
	}
	e = (t_aff *)malloc(sizeof(t_aff));
	struct_init(e);
	e->map = ft_parse(av[1]);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 3, keyboard, e);
	mlx_loop(e->mlx);
	return (0);
}
