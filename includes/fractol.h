/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:51:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 18:21:10 by tmaluh           ###   ########.fr       */
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
# include <math.h>
# include <mlx.h>

# define WIN_X	1000
# define WIN_Y	1000
# define WIN_MATRIX	WIN_X * WIN_Y

# define WIN_EXT	17
# define WIN_EXTM	(1L << 17)

# define MOUSE_MASK	0

# define MOUSE_SCROLLDOWN	4
# define MOUSE_SCROLLUP		5
# define MOUSE_MOVE			6

# define MLEFT_BUTTON	1
# define MSCROLL_DOWN	4
# define MSCROLL_UPS	5

# define IRGB_GRAY		0x0a0a0a
# define IRGB_WHITE		0xffffff
# define IRGB_LIME		0x53ff30
# define IRGB_CHERRY	0xff245B
# define IRGB_AQUA		0x47d1ff
# define IRGB_PINK		0xcc067f
# define IRGB_ORANGE	0xffbd0a
# define IRGB_PURPLE	0xed47ff

# define MANDELBROT		"Mandelbrot"
# define JULIA			"Julia"
# define BURNINGSHIP	"Burning Ship"
# define JULIAV2		"Julia v2"
# define JULIAV3		"Julia v3"

# define DEPTH_INC	5
# define DEPTH_MIN	0
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
	bool	is_julia;
}				t_fl;

bool			fl_init_fractol(t_fl *fl);

typedef int	(*t_fptr_fls)(t_fl*, int);

int				fl_mandelbrot(t_fl *fl, int j);
int				fl_julia(t_fl *fl, int j);
int				fl_burn_ship(t_fl *fl, int j);
int				fl_juliav2(t_fl *fl, int j);
int				fl_juliav3(t_fl *fl, int j);

void			fl_rendering(t_fl *fl);
void			fl_refresh_screen(t_fl *fl);

int				fl_khook_killwindow(t_fl *fl);
int				fl_key_hooks(int key, t_fl *fl);
int				fl_mouse_scrolls(int button, int x, int y, t_fl *fl);
int				fl_mouse_click(int button, int x, int y, t_fl *fl);
int				fl_mouse_julia(int x, int y, t_fl *fl);

void			fl_fill_ir(t_map *map, t_limit *limit);
double			fl_ci(t_limit *limit, double y);
double			fl_cr(t_limit *limit, double x);

void			fl_free(t_fl *fl);

#endif
