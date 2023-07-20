/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:59:18 by mrony             #+#    #+#             */
/*   Updated: 2023/06/12 20:58:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	if (*nptr == 0 || !nptr)
		return (0);
	while ((*nptr >= 8 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * neg);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	unsigned int	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	array = (unsigned char *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		array[i] = '\0';
		i++;
	}
	return ((void *)array);
}
