/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:17:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 13:28:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_limit	*add_set_limits(t_fl *fl)
{
	t_limit	*out;

	_NOTIS_N(out = malloc(sizeof(t_limit)));
	if (fl->mnum == 1)
		*out = (t_limit){0.5, -2.0, 1.25, -1.25};
	else
		*out = (t_limit){2.25, -2.25, 2, -2};
	fl->reset_limits = *out;
	return (out);
}

static t_map	*add_init_map(t_fl *fl)
{
	t_map	*out;
	int		x;
	int		y;
	int		i;

	_NOTIS_N(out = malloc(sizeof(t_map) * (WIN_MATRIX + 1)));
	x = 0;
	y = 0;
	i = 0;
	while (y < WIN_Y)
	{
		if (x == WIN_X && !(x = 0))
			++y;
		out[i].x = x++;
		out[i++].y = y;
	}
	i = -1;
	while (++i < WIN_MATRIX)
	{
		out[i].rc = out[i].x *
			((fl->limit->rmax - fl->limit->rmin) / WIN_Y) + fl->limit->rmin;
		out[i].ic = out[i].y *
			((fl->limit->imax - fl->limit->imin) / WIN_Y) + fl->limit->imin;
	}
	return (out);
}

bool			fl_init_fractol(t_fl *fl)
{
	int	bpp;
	int	sl;
	int	end;

	*fl = (t_fl){NULL, fl->mode, fl->mnum, NULL, NULL, {0, 0, 0, 0},
		IRGB_WHITE, DEPTH_DEF, 0, 0};
	_NOTIS_F(fl->mlx = malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, fl->mode));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (uint*)mlx_get_data_addr(IPTR, &bpp, &sl, &end));
	_NOTIS_F(fl->limit = add_set_limits(fl));
	_NOTIS_F(fl->map = add_init_map(fl));
	return (true);
}
