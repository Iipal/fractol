/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_cir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:56:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 18:22:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	fl_ci(t_limit *limit, double y)
{
	return (y * ((limit->imax - limit->imin) / WIN_Y) + limit->imin);
}

double	fl_cr(t_limit *limit, double x)
{
	return (x * ((limit->rmax - limit->rmin) / WIN_Y) + limit->rmin);
}

void	fl_fill_ir(t_map *map, t_limit *limit)
{
	int	i;

	i = -1;
	while (++i < WIN_MATRIX)
	{
		map[i].rc = fl_cr(limit, map[i].x);
		map[i].ic = fl_ci(limit, map[i].y);
	}
}
