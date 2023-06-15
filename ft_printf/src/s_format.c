/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:59:19 by mrony             #+#    #+#             */
/*   Updated: 2023/05/31 14:44:55 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	s_format(int i, t_data *data, va_list args)
{
	int		j;

	(void)i;
	j = 0;
	data->str = ft_strdup_printf(va_arg(args, char *));
	if (!(data->str))
		return (0);
	j = ft_putstr_count(data->str);
	free(data->str);
	return (j);
}
