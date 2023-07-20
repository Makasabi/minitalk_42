/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:21:38 by mrony             #+#    #+#             */
/*   Updated: 2023/05/31 14:45:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	xx_format(int i, t_data *data, va_list args)
{
	char	*base;
	int		res;

	(void)i;
	(void)args;
	base = "0123456789ABCDEF";
	res = 0;
	data->ui = va_arg(args, unsigned int);
	ft_putnbr_hexa(data->ui, base, &res);
	return (res);
}
