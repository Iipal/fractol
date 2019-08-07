/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_fractols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:25:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/07 17:45:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	fl_mandelbrot(t_fl *fl, size_t j)
{
	size_t	i;
	double	rz;
	double	iz;
	double	tmp;

	i = ~0UL;
	iz = 0.0;
	rz = 0.0;
	while ((size_t)fl->depth > ++i)
	{
		tmp = rz * rz - iz * iz;
		iz = 2.0 * rz * iz + fl->map[j].ic;
		rz = tmp + fl->map[j].rc;
		if (rz * rz + iz * iz > 4.0)
			break ;
	}
	return (i);
}

size_t	fl_julia(t_fl *fl, size_t j)
{
	size_t	i;
	double	rz;
	double	iz;
	double	tmp;

	i = ~0UL;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while ((size_t)fl->depth > ++i)
	{
		tmp = (rz * rz) - (iz * iz);
		iz = 2.0 * rz * iz + fl->jci;
		rz = tmp + fl->jcr;
		if ((rz * rz + iz * iz) > 4.0)
			break ;
	}
	return (i);
}

size_t	fl_burn_ship(t_fl *fl, size_t j)
{
	size_t	i;
	double	rz;
	double	iz;
	double	tmp;

	i = ~0UL;
	iz = 0.0;
	rz = 0.0;
	while ((size_t)fl->depth > ++i)
	{
		tmp = ((rz * rz) - (iz * iz));
		iz = 2.0 * fabs(rz * iz) + fl->map[j].ic;
		rz = tmp + fl->map[j].rc;
		if ((rz * rz + iz * iz) > 4.0)
			break ;
	}
	return (i);
}

size_t	fl_juliav2(t_fl *fl, size_t j)
{
	size_t	i;
	double	rz;
	double	iz;
	double	tmp;

	i = ~0UL;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while ((size_t)fl->depth > ++i)
	{
		tmp = (rz * rz) - (iz * iz);
		iz = 3.1 * (rz * iz + fl->jci);
		rz = tmp * .65 + fl->jcr;
		if ((rz * rz + iz * iz) > 4)
			break ;
	}
	return (i);
}

size_t	fl_juliav3(t_fl *fl, size_t j)
{
	size_t	i;
	double	rz;
	double	iz;
	double	tmp;

	i = ~0UL;
	iz = fl->map[j].ic;
	rz = fl->map[j].rc;
	while ((size_t)fl->depth > ++i)
	{
		tmp = (rz * rz) + (iz * iz);
		iz = 2.0 * rz * iz + fl->jci;
		rz = ((size_t)tmp & 3UL) + fl->jcr;
		if ((rz * rz + iz * iz) > 4.0)
			break ;
	}
	return (i);
}
