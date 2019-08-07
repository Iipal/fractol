/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:51:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 11:26:49 by tmaluh           ###   ########.fr       */
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

# include "libft.h"
# include "errno_msg.h"
# include <math.h>
# include <mlx.h>

# define WIN_X	800
# define WIN_Y	800
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

# define DEPTH_INC	5UL
# define DEPTH_MIN	0UL
# define DEPTH_DEF	50UL
# define DEPTH_MAX	5000UL

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int32_t	*screen;
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
	t_mlx		*mlx;
	char		*mode;
	t_map		*map;
	t_limit		*limit;
	t_limit		reset_limits;
	uint32_t	color;
	size_t		depth;
	double		jci;
	double		jcr;
	uint8_t		mnum;
	bool		is_julia;
}				t_fl;

bool			fl_init_fractol(t_fl *fl);

typedef size_t	(*t_fptr_fls)(t_fl*, size_t);

size_t			fl_mandelbrot(t_fl *fl, size_t j);
size_t			fl_julia(t_fl *fl, size_t j);
size_t			fl_burn_ship(t_fl *fl, size_t j);
size_t			fl_juliav2(t_fl *fl, size_t j);
size_t			fl_juliav3(t_fl *fl, size_t j);

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
