/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:41:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 09:20:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fl_free(t_fl *fl)
{
	mlx_destroy_image(fl->mlx->mlx, fl->mlx->img);
	mlx_destroy_window(fl->mlx->mlx, fl->mlx->win);
	free(fl->mlx);
	ft_strdel(&(fl->mode));
	free(fl->limit);
	free(fl->map);
	free(fl);
	fl = NULL;
}
