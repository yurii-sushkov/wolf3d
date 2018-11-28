/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:41:57 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/13 18:08:52 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		exit_y(void *par)
{
	par = NULL;
	if (OS == 0)
		system("killall -9 afplay");
	exit(1);
	return (0);
}

int		exit_x(t_wolf *par)
{
	if (OS == 0)
		system("killall -9 afplay");
	mlx_destroy_image(par->mlx, par->img);
	exit(1);
	return (0);
}

int		rotate(int x, int y, t_wolf *w)
{
	t_rot r;

	if (x < w->oldmx || x < 0)
	{
		w->oldmx = x;
		r.oldx = w->dirx;
		w->dirx = w->dirx * cos(-0.06) - w->diry * sin(-0.06);
		w->diry = r.oldx * sin(-0.06) + w->diry * cos(-0.06);
		r.oldplanex = w->planex;
		w->planex = w->planex * cos(-0.06) - w->planey * sin(-0.06);
		w->planey = r.oldplanex * sin(-0.06) + w->planey * cos(-0.06);
	}
	else if (x > w->oldmx || x > w->x)
	{
		w->oldmx = x;
		r.oldx = w->dirx;
		w->dirx = w->dirx * cos(0.06) - w->diry * sin(0.06);
		w->diry = r.oldx * sin(0.06) + w->diry * cos(0.06);
		r.oldplanex = w->planex;
		w->planex = w->planex * cos(0.06) - w->planey * sin(0.06);
		w->planey = r.oldplanex * sin(0.06) + w->planey * cos(0.06);
	}
	ft_memset(w->addr, 0, w->ww * w->wh * 4);
	build(w);
	return (0 * y);
}
