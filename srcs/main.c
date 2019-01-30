/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 14:14:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		usage(void)
{
	_MSGN("Usage: ./fractol <only_number>");
	_MSGN("\t1. Maldebrot");
	_MSGN("\t2. Julia");
}

int				main(int argc, cstring argv[])
{
	const char	*modes[] = {MANDELBROT, JULIA};
	t_fl		*fl;

	_ISARGS(argc, argv, usage);
	_NOTIS(_ERR_ALLOC_MEM_, fl = malloc(sizeof(t_fl)), -1);
	_NOTIS_DO(_ERR_INVALID_ARGS_,
		!(!(fl->mnum = ft_atoi((char*)*argv)) || fl->mnum > 2), -1, usage());
	_NOTIS(_ERR_ALLOC_MEM_, fl->mode = ft_strdup(modes[(fl->mnum - 1)]), -1);
	_NOTIS(_ERR_ALLOC_MEM_, fl_init_fractol(fl), -1);
	fl_fill_screen(fl);
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, fl_key_hooks, fl);
	mlx_loop(MPTR);
}
