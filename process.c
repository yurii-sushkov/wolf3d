/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:42:04 by ysushkov          #+#    #+#             */
/*   Updated: 2018/08/06 10:40:07 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	initializer(t_wolf *w, int x)
{
	w->camerax = 2 * x / (double)w->ww - 1;
	w->raydirx = w->dirx + w->planex * w->camerax;
	w->raydiry = w->diry + w->planey * w->camerax;
	w->mapx = (int)w->posx;
	w->mapy = (int)w->posy;
	w->deltadistx = fabs(1 / w->raydirx);
	w->deltadisty = fabs(1 / w->raydiry);
	w->hit = 0;
}

void	build(t_wolf *w)
{
	int x;
	int c;

	c = 0;
	x = -1;
	while (x++ < w->ww)
	{
		initializer(w, x);
		calc_step(w);
		calc_dda(w);
		calc_drawline(w);
		if (w->sw == 0)
			draw_walls(w, x);
		else if (w->sw == 1)
			draw_walls1(w, x);
		calc_floor(w);
		draw_floor(w, x, c);
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_loop(w->mlx);
}

void	process(t_wolf *w)
{
	w->end = 0;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->ww, w->wh, "Wolf3d");
	w->img = mlx_new_image(w->mlx, w->ww, w->wh);
	w->addr = mlx_get_data_addr(w->img, &w->by, &w->s, &w->end);
	mlx_hook(w->win, 2, 5, deal_key, w);
	mlx_hook(w->win, 17, 1L << 17, exit_x, w);
	mlx_hook(w->win, 6, 1L << 7, rotate, w);
	w->posx = 1.5;
	w->posy = 1.5;
	w->dirx = 1;
	w->diry = 0;
	w->planex = 0;
	w->planey = 0.66;
	w->time = clock() / CLOCKS_PER_SEC;
	w->oldmx = w->x / 2;
	w->oldmy = w->y / 2;
	w->sw = 0;
	load_tex(w);
	if (OS == 0)
		system("afplay audio/target.mp3 &");
	build(w);
}
