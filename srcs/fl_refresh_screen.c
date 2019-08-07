/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_refresh_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:05:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 17:16:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fl_refresh_screen(t_fl *fl)
{
	const t_fptr_fls	fractls[] = {&fl_mandelbrot, &fl_julia, &fl_burn_ship,
								&fl_juliav2, &fl_juliav3};
	size_t				i;
	size_t				res;

	i = ~0UL;
	while (WIN_MATRIX > ++i)
	{
		res = fractls[fl->mnum - 1](fl, i);
		if (fl->depth > res)
			fl->mlx->screen[i] = (res + (i ? (1 / i) : 1) + 1) * fl->color;
		else
			fl->mlx->screen[i] = !fl->color;
	}
	mlx_put_image_to_window(fl->mlx->mlx, fl->mlx->win, fl->mlx->img, 0, 0);
}
