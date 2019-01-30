/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_mouse_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:47:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 17:35:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	add_mouse_zoom(int button, int x, int y, t_fl *fl)
{
	double	rbeta;
	double	ibeta;
	double	mult;

	rbeta = fl_cr(fl->limit, x);
	ibeta = fl_ci(fl->limit, y);
	mult = (button == 5 ? 0.9 : 1.1);
	fl->limit->rmax = fl->limit->rmax * mult + rbeta * (1.0 - mult);
	fl->limit->rmin = fl->limit->rmin * mult + rbeta * (1.0 - mult);
	fl->limit->imax = fl->limit->imax * mult + ibeta * (1.0 - mult);
	fl->limit->imin = fl->limit->imin * mult + ibeta * (1.0 - mult);
	fl_fill_ir(fl->map, fl->limit);
	fl_refresh_screen(fl);
}

int		fl_mouse_click(int button, int x, int y, t_fl  *fl)
{
	(void)x;
	(void)y;
	if (button == MLEFT_BUTTON)
		fl->is_julia = !fl->is_julia;
	return (0);
}

#include <stdio.h>
int		fl_mouse_scrolls(int button, int x, int y, t_fl  *fl)
{
	if (button == MOUSE_SCROLLUP || button == MOUSE_SCROLLDOWN)
		add_mouse_zoom(button, x, y, fl);
	return (1);
}

int		fl_mouse_julia(int x, int y, t_fl *fl)
{
	if (fl->mnum == 2 && fl->is_julia)
	{
		fl->jcr = fl_cr(fl->limit, x);
		fl->jci = fl_ci(fl->limit, y);
		fl_refresh_screen(fl);
	}
	return (0);
}
