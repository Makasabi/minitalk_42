/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:28:13 by mrony             #+#    #+#             */
/*   Updated: 2023/06/14 18:15:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	g_flag;

void	ft_set_client_action(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd(FLDSI1, 2);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd(FLDSI2, 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_client_handler(int signal, siginfo_t *info, void *context)
{
	static int	flag;

	(void)info;
	(void)context;
	if (signal == SIGUSR1 && flag == 0)
	{
		ft_printf("\033[0;34m.\033[1;0m");
	}
	if (signal == SIGUSR2)
	{
		ft_printf("\033[0;34mString Status: \033[1;0mReceived 🦚\n");
		flag = 1;
	}
	g_flag = 1;
}

void	ft_int_to_bin(int size, int pid)
{
	long unsigned int	i;
	int					cpy;

	i = 0;
	cpy = size;
	while (i < 32)
	{
		g_flag = 0;
		if ((cpy << i) & 0x80000000)
		{
			if (kill(pid, SIGUSR1) < 0)
				ft_failed_kill(SNDSI1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				ft_failed_kill(SNDSI2);
		}
		i++;
		while (!g_flag)
			usleep(10);
	}
}

void	ft_char_to_bin(char c, int pid)
{
	long unsigned int	i;
	char				cpy;

	i = 0;
	cpy = c;
	while (i < 8)
	{
		g_flag = 0;
		if ((cpy << i) & 0x80)
		{
			if (kill(pid, SIGUSR1) < 0)
				ft_failed_kill(SNDSI1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				ft_failed_kill(SNDSI2);
		}
		i++;
		while (!g_flag)
			usleep(10);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa_c;
	int					i;

	i = 0;
	if (ac != 3)
		ft_param_error();
	if (kill(ft_atoi(av[1]), 0) < 0)
		ft_failed_kill(INVPID);
	sigemptyset(&sa_c.sa_mask);
	sa_c.sa_flags = SA_RESTART | SA_SIGINFO;
	sa_c.sa_sigaction = ft_client_handler;
	ft_set_client_action(&sa_c);
	ft_printf(CLIPID, getpid());
	ft_printf(STRLEN, ft_strlen(av[2]));
	ft_int_to_bin(ft_strlen(av[2]), ft_atoi(av[1]));
	while (av[2][i])
	{
		ft_char_to_bin(av[2][i], ft_atoi(av[1]));
		i++;
	}
	ft_char_to_bin('\0', ft_atoi(av[1]));
	return (0);
}
