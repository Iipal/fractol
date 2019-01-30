/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_fractols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:25:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 18:19:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	fl_mandelbrot(t_fl *fl, int j)
{
	int		i;
	double	rz;
	double	iz;
	double	tmp;

	i = -1;
	iz = 0;
	rz = 0;
	while (++i < fl->depth)
	{
		tmp = (rz * rz) - (iz * iz);
		iz = 2 * rz * iz + fl->map[j].ic;
		rz = tmp + fl->map[j].rc;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}

int	fl_julia(t_fl *fl, int j)
{
	int		i;
	double	rz;
	double	iz;
	double	tmp;

	i = -1;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while (++i < fl->depth)
	{
		tmp = (rz * rz) - (iz * iz);
		iz = 2 * rz * iz + fl->jci;
		rz = tmp + fl->jcr;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}

int	fl_burn_ship(t_fl *fl, int j)
{
	int		i;
	double	rz;
	double	iz;
	double	tmp;

	i = -1;
	iz = 0;
	rz = 0;
	while (++i < fl->depth)
	{
		tmp = ((rz * rz) - (iz * iz));
		iz = 2 * fabs(rz * iz) + fl->map[j].ic;
		rz = tmp + fl->map[j].rc;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}

int	fl_juliav2(t_fl *fl, int j)
{
	int		i;
	double	rz;
	double	iz;
	double	tmp;

	i = -1;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while (++i < fl->depth)
	{
		tmp = (rz * rz) - (iz * iz);
		iz = 3.1 * (rz * iz + fl->jci);
		rz = tmp * .65 + fl->jcr;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}

int	fl_juliav3(t_fl *fl, int j)
{
	int		i;
	double	rz;
	double	iz;
	double	tmp;

	i = -1;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while (++i < fl->depth)
	{
		tmp = (rz * rz) + (iz * iz);
		iz = 2 * rz * iz + fl->jci;
		rz = ((int)tmp & 3) + fl->jcr;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}
