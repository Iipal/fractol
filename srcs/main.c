/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 11:37:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		usage(void)
{
	ft_putendl("Usage: ./fractol <only_number>");
	ft_putstr("\t1. ");
	ft_putendl(MANDELBROT);
	ft_putstr("\t2. ");
	ft_putendl(JULIA);
	ft_putstr("\t3. ");
	ft_putendl(BURNINGSHIP);
	ft_putstr("\t4. ");
	ft_putendl(JULIAV2);
	ft_putstr("\t5. ");
	ft_putendl(JULIAV3);
}

int				main(int argc, char *argv[])
{
	const char	*modes[] = {MANDELBROT, JULIA, BURNINGSHIP, JULIAV2, JULIAV3};
	t_fl		*fl;

	ISARGS(argc, argv, E_USAGE);
	MEM(t_fl, fl, 1UL, E_ALLOC);
	fl->mnum = ft_atoi(*argv);
	IFDOMR(E_ARG_NUM, !(fl->mnum = ft_atoi(*argv)) || fl->mnum > 5, usage(), 1);
	NOM_F(E_ALLOC, fl->mode = ft_strdup(modes[fl->mnum - 1]));
	NOM_F(E_ALLOC, fl_init_fractol(fl));
	mlx_hook(fl->mlx->win, MSCROLL_UPS, MOUSE_MASK, fl_mouse_click, fl);
	mlx_hook(fl->mlx->win, MSCROLL_DOWN, MOUSE_MASK, fl_mouse_scrolls, fl);
	mlx_hook(fl->mlx->win, MOUSE_MOVE, MOUSE_MASK, fl_mouse_julia, fl);
	mlx_hook(fl->mlx->win, KEY_PRESSED, KEY_RELEASE, fl_key_hooks, fl);
	mlx_hook(fl->mlx->win, WIN_EXT, WIN_EXTM, fl_khook_killwindow, fl);
	mlx_loop(fl->mlx->mlx);
}
