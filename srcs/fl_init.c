/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:17:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 17:44:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_limit	*add_set_limits(t_fl *fl)
{
	t_limit	*out;

	MEM(t_limit, out, 1UL, E_ALLOC);
	if (1 == fl->mnum)
		*out = (t_limit){0.5, -2.0, 1.25, -1.25};
	else
		*out = (t_limit){2.25, -2.25, 2, -2};
	fl->reset_limits = *out;
	return (out);
}

static t_map	*add_init_map(t_fl *fl)
{
	t_map	*out;
	size_t	x;
	size_t	y;
	size_t	i;

	MEM(t_map, out, WIN_MATRIX + 1, E_ALLOC);
	x = 0UL;
	y = 0UL;
	i = 0UL;
	while (WIN_Y > y)
	{
		if (WIN_X == x)
		{
			x = 0UL;
			++y;
		}
		out[i].x = x++;
		out[i++].y = y;
	}
	fl_fill_ir(out, fl->limit);
	return (out);
}

bool			fl_init_fractol(t_fl *fl)
{
	int	bpp;
	int	sl;
	int	end;

	*fl = (t_fl){NULL, fl->mode, NULL, NULL, {0.0, 0.0, 0.0, 0.0},
				IRGB_WHITE, 0.0, 0.0, DEPTH_DEF, fl->mnum, false};
	MEM(t_mlx, fl->mlx, 1UL, E_ALLOC);
	NO_F(fl->mlx->mlx = mlx_init());
	NO_F(fl->mlx->win = mlx_new_window(fl->mlx->mlx, WIN_X, WIN_Y, fl->mode));
	NO_F(fl->mlx->img = mlx_new_image(fl->mlx->mlx, WIN_X, WIN_Y));
	NO_F(fl->mlx->screen
		= (int32_t*)mlx_get_data_addr(fl->mlx->img, &bpp, &sl, &end));
	NO_F(fl->limit = add_set_limits(fl));
	NO_F(fl->map = add_init_map(fl));
	return (true);
}
