/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:51:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 11:35:03 by tmaluh           ###   ########.fr       */
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
# include <mlx.h>

# define WIN_X	1000
# define WIN_Y	1000

# define MANDELBROT	"Mandelbrot"
# define JULIA		"Julia"

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

typedef struct	s_fl
{
	t_mlx	*mlx;
	string	mode;
	uint	mnum:4;
}				t_fl;

int				fl_key_hooks(int key, t_fl *fl);

void			fl_free(t_fl *fl);

#endif
