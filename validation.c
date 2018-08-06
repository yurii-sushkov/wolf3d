/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:56:13 by ysushkov          #+#    #+#             */
/*   Updated: 2018/08/06 10:46:29 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		**create_map(int **arr, char *s, int a, int n)
{
	t_crmap m;

	m.i = 0;
	m.fd = open(s, O_RDONLY);
	while (get_next_line(m.fd, &m.b) == 1 && m.i < n)
	{
		m.j = -1;
		while (m.j++ < a - 1)
		{
			if (m.i == n - 1 && (m.b[m.j] == '0' || m.b[m.j] > '6'))
			{
				fresh(arr, n);
				ft_strdel(&m.b);
				return (NULL);
			}
			arr[m.i][m.j] = m.b[m.j] - 48;
		}
		ft_strdel(&m.b);
		m.i++;
	}
	return (arr);
}

void	fresh(int **arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	structures(t_wolf *w, char *s, int a, int i)
{
	int		y;

	if (a > 100 || i > 100)
		ft_error(3);
	w->wh = HEIGHT;
	w->ww = WIDTH;
	w->by = 4;
	w->s = 256;
	w->arr = (int **)malloc(sizeof(int *) * i);
	y = 0;
	while (y < i)
	{
		w->arr[y] = (int *)malloc(sizeof(int) * a);
		y++;
	}
	w->arr = create_map(w->arr, s, a, i);
	if (w->arr == NULL || w->arr[1][1] != 0)
		ft_error(1);
	w->x = a;
	w->y = i;
	process(w);
}

int		check_str(char *s, int q)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(s);
	while (s[i] != 0)
	{
		if ((q == 0 && (s[i] == '0' || s[i] > '6')) ||
			((q > 0 && (i == 0 || i == n - 1) && (s[i] == '0' || s[i] > '6')))
			|| ((q > 0 && (i > 0 && i < n) && (s[i] < '0' || s[i] > '6'))))
		{
			ft_error(1);
			return (0);
		}
		i++;
	}
	return (n);
}

int		validation(char *s)
{
	t_val	z;
	t_wolf	w;

	z.i = 0;
	z.fd = open(s, O_RDONLY);
	z.a = 0;
	if (z.fd < 0)
		ft_usage(1);
	while (get_next_line(z.fd, &z.buf) == 1)
	{
		if (z.i == 0)
			z.a = check_str(z.buf, z.i);
		else if (z.i > 0 && check_str(z.buf, z.i) != z.a)
			ft_error(1);
		ft_strdel(&z.buf);
		z.i++;
	}
	if (z.i == 0 || z.a == 0 || z.i == 1 || z.a == 1)
		ft_error(1);
	if (close(z.fd) == -1)
		ft_error(2);
	structures(&w, s, z.a, z.i);
	return (0);
}
