/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_fill_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:05:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 14:14:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fl_fill_screen(t_fl *fl)
{
	const fptr_fls	fls[] = {&fl_mandelbrot, &fl_julia};
	int				i;
	int				res;

	i = -1;
	while (++i < WIN_MATRIX)
	{
		if ((res = fls[fl->mnum - 1](fl, i)) < fl->depth)
			fl->mlx->screen[i] = (res + 1 / i + 1) * fl->color;
		else
			fl->mlx->screen[i] = !fl->color;
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
	ft_bzero(fl->mlx->screen, sizeof(int) * WIN_MATRIX);
}
