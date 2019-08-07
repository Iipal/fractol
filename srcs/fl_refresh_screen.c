/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_refresh_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:05:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 17:46:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

const t_fptr_fls	g_fractals[] = {&fl_mandelbrot, &fl_julia, &fl_burn_ship,
									&fl_juliav2, &fl_juliav3};

static void	*fn_thread1(void *data)
{
	t_fl	*const fl = (t_fl *const)data;
	size_t	i;
	size_t	res;

	i = ~0UL;
	while (WIN_MATRIX / 2 > ++i)
	{
		res = g_fractals[fl->mnum - 1](fl, i);
		if ((size_t)fl->depth > res)
			fl->mlx->screen[i] = (res + (i ? (1 / i) : 1) + 1) * fl->color;
		else
			fl->mlx->screen[i] = !fl->color;
	}
	pthread_exit(0);
}

static void	*fn_thread2(void *data)
{
	t_fl	*const fl = (t_fl *const)data;
	size_t	i;
	size_t	res;

	i = WIN_MATRIX / 2 - 1;
	while (WIN_MATRIX > ++i)
	{
		res = g_fractals[fl->mnum - 1](fl, i);
		if ((size_t)fl->depth > res)
			fl->mlx->screen[i] = (res + (i ? (1 / i) : 1) + 1) * fl->color;
		else
			fl->mlx->screen[i] = !fl->color;
	}
	pthread_exit(0);
}

void	fl_refresh_screen(t_fl *fl)
{
	pthread_t	t1;
	pthread_t	t2;

	clock_t	old = clock();
	ft_bzero(fl->mlx->screen, sizeof(int32_t) * WIN_MATRIX);
	pthread_create(&t1, NULL, fn_thread1, fl);
	pthread_create(&t2, NULL, fn_thread2, fl);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	mlx_put_image_to_window(fl->mlx->mlx, fl->mlx->win, fl->mlx->img, 0, 0);
	printf("%f\n", ((clock() - (float)old) * 1000.0f) / CLOCKS_PER_SEC);
}
