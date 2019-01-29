/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:41:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/29 15:43:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fl_free(t_fl *fl)
{
	mlx_destroy_image(MPTR, IPTR);
	mlx_destroy_window(MPTR, WPTR);
	free(fl->mlx);
	ft_strdel(&(fl->mode));
	free(fl);
	fl = NULL;
}
