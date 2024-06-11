/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:45:05 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/27 13:10:27 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	lock_pid(pid_t *pid_now, pid_t pid_info)
{
	if (*pid_now == -1)
		*pid_now = pid_info;
	if (*pid_now != pid_info)
		return (-1);
	return (0);
}

void	decode_print(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static int				n_called = 0;
	static pid_t			pid_now = -1;

	(void)ucontext;
	// if (lock_pid(&pid_now, info->si_pid) == -1)
	// 	return ;
	c = c * 2 + (sig - SIGUSR1);
	if (++n_called == 8)
	{
		if (c == 0)
		{
			if (pid_now != -1)
				pid_now = -1;
			n_called = 0;
			if (kill(info->si_pid, SIGUSR2) == -1)
				return ;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		n_called = 0;
	}
}

int	ft_server(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigemptyset(&action.sa_mask) == -1)
		return (-1);
	action.sa_sigaction = decode_print;
	action.sa_flags = SA_SIGINFO;
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		return (-1);
	while (1)
		pause();
}

int	main(void)
{
	ft_server();
}
