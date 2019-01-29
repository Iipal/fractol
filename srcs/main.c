/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/29 15:46:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	usage(void)
{
	_MSGN("Usage: ./fractol <only_number>");
	_MSGN("\t1. Maldebrot");
	_MSGN("\t2. Julia");
}

static bool	add_valid_arg(t_fl *fl, string arg)
{
	const char	*modes[] = {MALDEBROT, JULIA};
	int			mode;

	_NOTIS_F(!(!(mode = ft_atoi(arg)) || mode > 2));
	_NOTIS_F(fl->mode = ft_strdup(modes[--mode]));
	return (true);
}

static bool	add_init_fractol(t_fl *fl)
{
	int	bpp;
	int	sl;
	int	end;

	*fl = (t_fl){NULL, fl->mode};
	_NOTIS_F(fl->mlx = malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, fl->mode));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (int*)mlx_get_data_addr(IPTR, &bpp, &sl, &end));
	return (true);
}

int			main(int argc, cstring argv[])
{
	t_fl	*fl;

	_ISARGS(argc, argv, usage);
	_NOTIS(_ERR_ALLOC_MEM_, fl = malloc(sizeof(t_fl)), -1);
	_NOTIS(_ERR_INVALID_ARGS_, add_valid_arg(fl, (string)*argv), -1);
	_NOTIS(_ERR_ALLOC_MEM_, add_init_fractol(fl), -1);
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, fl_key_hooks, fl);
	mlx_loop(MPTR);
}
