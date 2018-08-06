/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:39:05 by ysushkov          #+#    #+#             */
/*   Updated: 2018/07/13 17:19:16 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	data_geter(t_wolf *w)
{
	w->t.data[0] = mlx_get_data_addr(w->t.im[0], &w->t.by[0], &w->t.s[0],
									&w->end);
	w->t.data[1] = mlx_get_data_addr(w->t.im[1], &w->t.by[1], &w->t.s[1],
									&w->end);
	w->t.data[2] = mlx_get_data_addr(w->t.im[2], &w->t.by[2], &w->t.s[2],
									&w->end);
	w->t.data[3] = mlx_get_data_addr(w->t.im[3], &w->t.by[3], &w->t.s[3],
									&w->end);
	w->t.data[4] = mlx_get_data_addr(w->t.im[4], &w->t.by[4], &w->t.s[4],
									&w->end);
	w->t.data[5] = mlx_get_data_addr(w->t.im[5], &w->t.by[5], &w->t.s[5],
									&w->end);
}

void	load_tex(t_wolf *w)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 64;
	x = 64;
	w->t.im[0] = mlx_xpm_file_to_image(w->mlx, "images/wood.xpm", &x, &y);
	w->t.im[1] = mlx_xpm_file_to_image(w->mlx, "images/redbrick.xpm", &x, &y);
	w->t.im[2] = mlx_xpm_file_to_image(w->mlx, "images/greystone.xpm", &x, &y);
	w->t.im[3] = mlx_xpm_file_to_image(w->mlx, "images/mossy.xpm", &x, &y);
	w->t.im[4] = mlx_xpm_file_to_image(w->mlx, "images/colorstone.xpm", &x, &y);
	w->t.im[5] = mlx_xpm_file_to_image(w->mlx, "images/eagle.xpm", &x, &y);
	while (i < 6)
	{
		if (w->t.im[i] == NULL)
			ft_error(4);
		w->t.by[i] = 5;
		w->t.s[i] = 1;
		i++;
	}
	data_geter(w);
}
