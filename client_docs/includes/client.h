/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:38:34 by mrony             #+#    #+#             */
/*   Updated: 2023/06/13 12:32:42 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include "../../ft_printf/inc/ft_printf.h"

# define ERRARG "Invalid argument\n"

void	ft_failed_kill(char *error);
void	ft_param_error(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *nptr);

// 🦥 🦦 🦚 🦖 🦤 🦭

// ERROR //

# define INVARG "\033[1;35m🦖 Invalid Argument(s) 🦖\n\033[1;0m"
# define USAGE "\033[0;34m🦥 Usage: ./client <server PID> \
<string to be sent>\n\033[1;0m"
# define INVPID "\033[1;35m🦖 Invalid Process ID 🦖\n\033[1;0m"
# define CLIPID "\033[1;34m🦭  Client PID: %d\n\033[1;0m"
# define FLDSI1 "\033[1;35m🦖 Failed initiating sigaction \
			SIGUSR1 🦖\n\033[1;0m"
# define FLDSI2 "\033[1;35m🦖 Failed initiating sigaction \
			SIGUSR2 🦖\n\033[1;0m"
# define SNDSI1 "\e[1;35m🦖 Sending SIGUSR1 failed 🦖\033[1;0m"
# define SNDSI2 "\e[1;35m🦖 Sending SIGUSR2 failed 🦖\033[1;0m"
# define STRLEN "\033[0;34mString Length:\033[1;0m %d\n"

#endif