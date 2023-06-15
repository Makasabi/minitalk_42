/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:51:05 by mrony             #+#    #+#             */
/*   Updated: 2023/06/13 12:24:40 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	ft_set_server_action(struct sigaction *sa)
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

void	ft_set_str(t_server *server)
{
	if (server->bits == sizeof(int) * 8 && server->flag == 0)
	{
		server->flag = 1;
		ft_printf("\033[0;32mString Length:\033[1;0m %d\n", server->data);
		server->str = ft_calloc(server->data + 1, sizeof(char));
		if (!server->str)
		{
			ft_putstr_fd(FLDCLC, 2);
			exit(EXIT_FAILURE);
		}
		server->str[server->data] = '\0';
		server->bits = 0;
	}
}

void	ft_print_str(t_server *server, int *i, int client_pid)
{
	if (server->bits == 8 && server->flag == 1)
	{
		server->str[*i] = server->data;
		(*i)++;
		if (server->data == '\0')
		{
			ft_printf(STRPNT, server->str);
			free(server->str);
			server->str = NULL;
			server->flag = 0;
			*i = 0;
			if (kill(client_pid, SIGUSR2) < 0)
			{
				ft_putstr_fd(SNDSI2, 2);
				exit(EXIT_FAILURE);
			}
		}
		server->bits = 0;
	}
}

void	ft_server_handler(int signal, siginfo_t *info, void *context)
{
	static t_server		server;
	static int			i;

	(void)context;
	usleep(500);
	if (server.bits == 0)
		server.data = 0;
	if (signal == SIGUSR1 && server.flag == 0)
		server.data |= 1 << (((sizeof(int) * 8 - 1)) - server.bits);
	if (signal == SIGUSR1 && server.flag == 1)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bits);
	server.bits++;
	ft_set_str(&server);
	ft_print_str(&server, &i, info->si_pid);
	if (kill(info->si_pid, SIGUSR1) < 0)
	{
		ft_putstr_fd(SNDSI1, 2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa_s;

	ft_printf(SERPID, getpid());
	sigemptyset(&sa_s.sa_mask);
	sa_s.sa_flags = SA_RESTART | SA_SIGINFO;
	sa_s.sa_sigaction = ft_server_handler;
	ft_set_server_action(&sa_s);
	while (1)
		pause();
	return (0);
}
