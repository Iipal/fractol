/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 17:47:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		usage(void)
{
	_MSGN("Usage: ./fractol <only_number>");
	_MSG("\t1. "); _MSGN(MANDELBROT);
	_MSG("\t2. "); _MSGN(JULIA);
	_MSG("\t3. "); _MSGN(BURNINGSHIP);
	_MSG("\t4. "); _MSGN(JULIAV2);
	_MSG("\t5. "); _MSGN(JULIAV3);
}

int				main(int argc, cstring argv[])
{
	const char	*modes[] = {MANDELBROT, JULIA, BURNINGSHIP, JULIAV2, JULIAV3};
	t_fl		*fl;

	_ISARGS(argc, argv, usage);
	_NOTIS(_ERR_ALLOC_MEM_, fl = malloc(sizeof(t_fl)), -1);
	_NOTIS_DO(_ERR_INVALID_ARGS_,
		!(!(fl->mnum = ft_atoi((char*)*argv)) || fl->mnum > 5), -1, usage());
	_NOTIS(_ERR_ALLOC_MEM_, fl->mode = ft_strdup(modes[(fl->mnum - 1)]), -1);
	_NOTIS(_ERR_ALLOC_MEM_, fl_init_fractol(fl), -1);
	mlx_hook(WPTR, MSCROLL_UPS, MOUSE_MASK, fl_mouse_click, fl);
	mlx_hook(WPTR, MSCROLL_DOWN, MOUSE_MASK, fl_mouse_scrolls, fl);
	mlx_hook(WPTR, MOUSE_MOVE, MOUSE_MASK, fl_mouse_julia, fl);
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, fl_key_hooks, fl);
	mlx_hook(WPTR, WIN_EXT, WIN_EXTM, fl_khook_killwindow, fl);
	mlx_loop(MPTR);
}
