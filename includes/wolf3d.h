/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:33:55 by ysushkov          #+#    #+#             */
/*   Updated: 2018/08/06 11:02:42 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libft.h"
# include <math.h>
# ifdef __APPLE__
#  include "../minilibx_macos/mlx.h"
# elif __linux__
#  include "../minilibx/mlx.h"
# endif
# include <fcntl.h>
# include <sys/types.h>
# include <time.h>
# define WIDTH 640
# define HEIGHT 480
# define TH 64
# define TW 64

typedef struct		s_tex
{
	int				id;
	void			*im[6];
	char			*data[6];
	int				by[6];
	int				s[6];
}					t_tex;

typedef struct		s_key
{
	double			olddirx;
	double			oldplanex;
}					t_key;

typedef struct		s_wolf
{
	int				**arr;
	void			*mlx;
	int				end;
	int				color;
	void			*win;
	void			*img;
	char			*addr;
	int				x;
	int				y;
	int				by;
	int				s;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			camerax;
	double			cameray;
	int				drawstart;
	int				drawend;
	int				side;
	int				mapx;
	int				mapy;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				lineheight;
	double			wallx;
	int				d;
	int				texx;
	int				texy;
	int				r;
	int				g;
	int				b;
	double			floorxwall;
	double			floorywall;
	double			currentdist;
	double			currentfloorx;
	double			currentfloory;
	int				floortexx;
	int				floortexy;
	double			weight;
	int				oldmx;
	int				oldmy;
	int				wh;
	int				ww;
	int				sw;
	t_tex			t;
	t_key			k;
}					t_wolf;

typedef struct		s_crmap
{
	int				i;
	int				j;
	int				fd;
	char			*b;
}					t_crmap;

typedef struct		s_rot
{
	double			oldx;
	double			oldplanex;
}					t_rot;

typedef struct		s_val
{
	int				fd;
	int				i;
	int				a;
	char			*buf;
}					t_val;

void				ft_images(t_wolf *w, int x, int y, int c);
void				draw_walls1(t_wolf *w, int x);
void				draw_walls(t_wolf *w, int x);
void				draw_floor(t_wolf *w, int x, int c);
void				calc_step(t_wolf *w);
void				calc_dda(t_wolf *w);
void				calc_drawline(t_wolf *w);
void				calc_floor(t_wolf *w);
int					finalescaper(int key, t_wolf *w);
int					exit_x(t_wolf *par);
int					exit_y(void *par);
int					rotate(int x, int y, t_wolf *w);
int					deal_key(int key, t_wolf *w);
void				load_tex(t_wolf *w);
void				build(t_wolf *w);
void				process(t_wolf *w);
void				fresh(int **arr, int n);
int					**create_map(int **arr, char *s, int a, int n);
void				structures(t_wolf *w, char *s, int a, int i);
int					validation(char *s);
void				ft_usage(int n);
void				ft_error(int n);

#endif
