/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:50:58 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/13 18:08:34 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"
#include <math.h>

void	forwardback(int key, t_wolf *w)
{
	static int i = 0;

	if (key == 13 || key == 126)
	{
		if (w->arr[(int)(w->posx + w->dirx * 0.2)][(int)w->posy] == 0)
			w->posx += w->dirx * 0.1;
		if (w->arr[(int)w->posx][(int)(w->posy + w->diry * 0.2)] == 0)
			w->posy += w->diry * 0.1;
	}
	else if (key == 1 || key == 125)
	{
		if (w->arr[(int)(w->posx - w->dirx * 0.2)][(int)w->posy] == 0)
			w->posx -= w->dirx * 0.1;
		if (w->arr[(int)w->posx][(int)(w->posy - w->diry * 0.2)] == 0)
			w->posy -= w->diry * 0.1;
	}
	i++;
	if (i % 10 == 0)
		system("afplay audio/step.wav &");
	if (i == 1000)
		i = 0;
}

void	leftright(int key, t_wolf *w)
{
	static int i = 0;

	if (key == 0)
	{
		if (w->arr[(int)(w->posx + w->dirx * cos(-1.5708) -
						w->diry * sin(-1.5708) * 0.1)][(int)w->posy] == 0)
			w->posx += (w->dirx * cos(-1.5708) - w->diry * sin(-1.5708)) * 0.05;
		if (w->arr[(int)w->posx][(int)(w->posy +
				w->dirx * sin(-1.5708) * 0.1 + w->diry * cos(-1.5708))] == 0)
			w->posy += (w->dirx * sin(-1.5708) + w->diry * cos(-1.5708)) * 0.05;
	}
	else if (key == 2)
	{
		if (w->arr[(int)(w->posx + w->dirx * cos(1.5708) -
						w->diry * sin(1.5708) * 0.1)][(int)w->posy] == 0)
			w->posx += (w->dirx * cos(1.5708) - w->diry * sin(1.5708)) * 0.05;
		if (w->arr[(int)w->posx][(int)(w->posy +
				w->dirx * sin(1.5708) * 0.1 + w->diry * cos(1.5708))] == 0)
			w->posy += (w->dirx * sin(1.5708) + w->diry * cos(1.5708)) * 0.05;
	}
	i++;
	if (i % 15 == 0)
		system("afplay audio/step.wav &");
	if (i == 1000)
		i = 0;
}

void	rotation(int key, t_wolf *w)
{
	if (key == 12 || key == 123)
	{
		w->k.olddirx = w->dirx;
		w->dirx = w->dirx * cos(-0.1) - w->diry * sin(-0.1);
		w->diry = w->k.olddirx * sin(-0.1) + w->diry * cos(-0.1);
		w->k.oldplanex = w->planex;
		w->planex = w->planex * cos(-0.1) - w->planey * sin(-0.1);
		w->planey = w->k.oldplanex * sin(-0.1) + w->planey * cos(-0.1);
	}
	else if (key == 14 || key == 124)
	{
		w->k.olddirx = w->dirx;
		w->dirx = w->dirx * cos(0.1) - w->diry * sin(0.1);
		w->diry = w->k.olddirx * sin(0.1) + w->diry * cos(0.1);
		w->k.oldplanex = w->planex;
		w->planex = w->planex * cos(0.1) - w->planey * sin(0.1);
		w->planey = w->k.oldplanex * sin(0.1) + w->planey * cos(0.1);
	}
}

int		finalescaper(int key, t_wolf *w)
{
	if (key == 53)
	{
		w = NULL;
		system("killall -9 afplay");
		key = 0;
		exit(1);
		return (0);
	}
	return (0);
}

int		deal_key(int key, t_wolf *w)
{
	if (key == 53)
	{
		mlx_destroy_image(w->mlx, w->img);
		system("killall -9 afplay");
		exit(1);
		return (0);
	}
	if (key == 13 || key == 126 || key == 1 || key == 125)
		forwardback(key, w);
	else if (key == 0 || key == 2)
		leftright(key, w);
	else if (key == 12 || key == 123 || key == 14 || key == 124)
		rotation(key, w);
	if (key == 36)
	{
		if (w->sw == 0)
			w->sw = 1;
		else
			w->sw = 0;
	}
	ft_memset(w->addr, 0, w->ww * w->wh * 4);
	build(w);
	return (0);
}
