/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_refresh_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:05:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 18:21:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fl_refresh_screen(t_fl *fl)
{
	const t_fptr_fls	fls[] = {&fl_mandelbrot, &fl_julia, &fl_burn_ship,
								&fl_juliav2, &fl_juliav3};
	int					i;
	int					res;

	i = -1;
	ft_bzero(fl->mlx->screen, sizeof(int) * WIN_MATRIX);
	while (++i < WIN_MATRIX)
		if ((res = fls[fl->mnum - 1](fl, i)) < fl->depth)
			fl->mlx->screen[i] = (res + 1 / i + 1) * fl->color;
		else
			fl->mlx->screen[i] = !fl->color;
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
}
