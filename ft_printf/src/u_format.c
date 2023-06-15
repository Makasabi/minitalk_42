/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:39:40 by mrony             #+#    #+#             */
/*   Updated: 2023/05/31 14:44:57 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	u_format(int i, t_data *data, va_list args)
{
	int		res;

	(void)i;
	data->ui = (va_arg(args, unsigned int));
	res = 0;
	ft_putnbr_ui(data->ui, &res);
	return (res);
}
