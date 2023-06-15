/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:34:26 by mrony             #+#    #+#             */
/*   Updated: 2023/06/12 22:09:22 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>

# include "../../ft_printf/inc/ft_printf.h"

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

# define INVPID "\033[1;35m🦖 Invalid Process ID 🦖\n\033[1;0m"
# define SERPID "\033[1;32m🦦 Server PID: %d\n\033[1;0m"
# define FLDSI1 "\033[1;35m🦖 Failed initiating sigaction \
			SIGUSR1 🦖\n\033[1;0m"
# define FLDSI2 "\033[1;35m🦖 Failed initiating sigaction \
			SIGUSR2 🦖\n\033[1;0m"
# define SNDSI1 "\e[1;35m🦖 Sending SIGUSR1 failed 🦖\033[1;0m"
# define SNDSI2 "\e[1;35m🦖 Sending SIGUSR2 failed 🦖\033[1;0m"
# define FLDCLC "\e[1;35m🦖 Calloc allocation failed 🦖\033[1;0m"
# define STRPNT "\033[0;32mString Received:'\033[1;0m%s\033[0;32m'\033[1;0m\n"

typedef struct s_server
{
	int		bits;
	int		data;
	int		flag;
	char	*str;
}			t_server;

#endif