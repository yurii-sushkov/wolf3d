/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:56:28 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/11 19:44:48 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	calc_floor(t_wolf *w)
{
	if (w->side == 0 && w->raydirx > 0)
	{
		w->floorxwall = w->mapx;
		w->floorywall = w->mapy + w->wallx;
	}
	else if (w->side == 0 && w->raydirx < 0)
	{
		w->floorxwall = w->mapx + 1.0;
		w->floorywall = w->mapy + w->wallx;
	}
	else if (w->side == 1 && w->raydiry > 0)
	{
		w->floorxwall = w->mapx + w->wallx;
		w->floorywall = w->mapy;
	}
	else if (w->side == 1 && w->raydiry < 0)
	{
		w->floorxwall = w->mapx + w->wallx;
		w->floorywall = w->mapy + 1.0;
	}
	if (w->drawend < 0)
		w->drawend = w->wh;
}

void	calc_drawline(t_wolf *w)
{
	if (w->side == 0)
		w->perpwalldist = (w->mapx - w->posx + (1 - w->stepx) / 2) / w->raydirx;
	else
		w->perpwalldist = (w->mapy - w->posy + (1 - w->stepy) / 2) / w->raydiry;
	w->lineheight = (int)(w->wh / w->perpwalldist);
	w->drawstart = -w->lineheight / 2 + w->wh / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = w->lineheight / 2 + w->wh / 2;
	if (w->drawend >= w->wh)
		w->drawend = w->wh - 1;
	if (w->side == 0)
		w->wallx = w->posy + w->perpwalldist * w->raydiry;
	else
		w->wallx = w->posx + w->perpwalldist * w->raydirx;
	w->wallx -= floor(w->wallx);
	w->texx = (int)(w->wallx * (double)TW);
	if (w->side == 0 && w->raydirx > 0)
		w->texx = TW - w->texx - 1;
	if (w->side == 1 && w->raydiry < 0)
		w->texx = TW - w->texx - 1;
}

void	calc_dda(t_wolf *w)
{
	while (w->hit == 0)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			w->side = 1;
		}
		if (w->arr[w->mapx][w->mapy] > 0)
			w->hit = 1;
	}
}

void	calc_step(t_wolf *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->posx - w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = (w->mapx + 1.0 - w->posx) * w->deltadistx;
	}
	if (w->raydiry < 0)
	{
		w->stepy = -1;
		w->sidedisty = (w->posy - w->mapy) * w->deltadisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisty = (w->mapy + 1.0 - w->posy) * w->deltadisty;
	}
}
