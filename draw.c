/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:03:11 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/13 13:35:46 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	ft_images(t_wolf *w, int x, int y, int c)
{
	if (x >= 0 && y >= 0 && x < w->ww && y < w->wh)
		*(int *)(w->addr + ((x + y * w->ww) * 4)) = c;
}

int		texreader(t_wolf *w, int y, int t)
{
	int c;

	w->d = y * w->t.s[t] - w->wh * 128 + w->lineheight * 128;
	w->texy = ((w->d * TH) / w->lineheight) / w->t.s[t];
	w->b = w->t.data[t][w->t.s[t] * w->texy + w->texx * 4];
	w->g = w->t.data[t][(w->t.s[t] *
							w->texy + w->texx * 4) + 1];
	w->r = w->t.data[t][(w->t.s[t] *
							w->texy + w->texx * 4) + 2];
	c = w->r * 0x10000 + w->g * 0x100 + w->b;
	c = (c >> 1) & 8355711;
	return (c);
}

void	draw_walls(t_wolf *w, int x)
{
	int cc;
	int c;

	cc = w->drawstart;
	if (w->arr[w->mapx][w->mapy] != 0)
		w->t.id = w->arr[w->mapx][w->mapy] - 1;
	if (w->arr[w->mapx][w->mapy] > 6)
		w->t.id = 0;
	while (cc < w->drawend)
	{
		c = texreader(w, cc, w->t.id);
		if (w->side == 1)
			c = (c >> 1) & 8355711;
		ft_images(w, x, cc, c);
		cc++;
	}
}

void	draw_walls1(t_wolf *w, int x)
{
	int cc;
	int c;

	cc = w->drawstart;
	while (cc < w->drawend)
	{
		if (w->side == 0)
		{
			if (w->stepx < 0)
				c = texreader(w, cc, 0);
			else
				c = texreader(w, cc, 1);
		}
		else if (w->side == 1)
		{
			if (w->stepy < 0)
				c = texreader(w, cc, 4);
			else
				c = texreader(w, cc, 3);
			if (w->side == 1)
				c = (c >> 1) & 8355711;
		}
		ft_images(w, x, cc, c);
		cc++;
	}
}

void	draw_floor(t_wolf *w, int x, int c)
{
	int l;

	l = w->drawend + 1;
	while (l < w->wh)
	{
		w->currentdist = w->wh / (2.0 * l - w->wh);
		w->weight = w->currentdist / w->perpwalldist;
		w->currentfloorx = w->weight * w->floorxwall + (1.0 - w->weight)
			* w->posx;
		w->currentfloory = w->weight * w->floorywall + (1.0 - w->weight)
			* w->posy;
		w->floortexx = (int)(w->currentfloorx * TW) % TH;
		w->floortexy = (int)(w->currentfloory * TH) % TH;
		w->r = (w->t.data[2][w->t.s[2] * w->floortexy +
							w->floortexx * 4 + 2]) * 0x10000;
		w->g = (w->t.data[2][w->t.s[2] * w->floortexy +
							w->floortexx * 4 + 1]) * 0x100;
		w->b = (w->t.data[2][w->t.s[2] * w->floortexy + w->floortexx * 4]);
		c = w->r + w->g + w->b;
		c = (c >> 1) & 8355711;
		ft_images(w, x, w->wh - l, c);
		c = (c >> 1) & 8355711;
		ft_images(w, x, l, c);
		l++;
	}
}
