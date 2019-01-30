/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:51:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 14:06:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __APPLE__
#  include "macos_keys.h"
# endif

# ifdef __linux__
#  include "linux_keys.h"
# endif

# include "../libft/includes/libft.h"
# include "errno_msg.h"
#include<stdio.h>
# include <mlx.h>

# define WIN_X	1000
# define WIN_Y	1000
# define WIN_MATRIX	WIN_X * WIN_Y

# define IRGB_GRAY		3355443
# define IRGB_WHITE		16777215
# define IRGB_LIME		8388352
# define IRGB_CHERRY	15865942
# define IRGB_AQUA		7273983
# define IRGB_PINK		13704642
# define IRGB_ORANGE	16758835
# define IRGB_PURPLE	3356415

# define MANDELBROT	"Mandelbrot"
# define JULIA		"Julia"

# define DEPTH_INC	5
# define DEPTH_MIN	5
# define DEPTH_DEF	50
# define DEPTH_MAX	5000

enum	e_bool {false, true};

# define _BOOL typedef enum e_bool	bool
# define _UNIT typedef unsigned int	uint

_BOOL;
_UNIT;

# define _ISARGS(ac, av, ufunc){--ac;++av;if(ac != 1){ufunc();return(false);}}

# define _MSG(msg) ft_putstr(msg)
# define _MSGN(msg) ft_putendl(msg)
# define _NOTIS(msg, ex, ret) if (!(ex)) {_MSGN(msg); return(ret);}
# define _NOTIS_DO(msg, ex, ret, do) if (!(ex)) {_MSGN(msg);do;return(ret);}
# define _NOTIS_F(ex) if (!(ex)) return (false)
# define _NOTIS_N(ex) if (!(ex)) return (NULL)

# define MPTR	fl->mlx->mlx
# define WPTR	fl->mlx->win
# define IPTR	fl->mlx->img
# define SPTR	fl->mlx->screen

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
	pvoid	img;
	uint	*screen;
}				t_mlx;

typedef struct	s_limit
{
	double	rmax;
	double	rmin;
	double	imax;
	double	imin;
}				t_limit;

typedef	struct	s_map
{
	double	x;
	double	y;
	double	ic;
	double	iz;
	double	rc;
	double	rz;
	int		color;
}				t_map;

typedef struct	s_fl
{
	t_mlx	*mlx;
	string	mode;
	uint	mnum:4;
	t_map	*map;
	t_limit	*limit;
	t_limit	reset_limits;
	int		color;
	int		depth;
	double	jci;
	double	jcr;
}				t_fl;

typedef int (*fptr_fls)(t_fl*, int);

int				fl_mandelbrot(t_fl *fl, int j);
int				fl_julia(t_fl *fl, int j);

bool			fl_init_fractol(t_fl *fl);
void			fl_fill_screen(t_fl *fl);


int				fl_key_hooks(int key, t_fl *fl);

void			fl_free(t_fl *fl);

#endif
