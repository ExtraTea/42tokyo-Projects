/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:45:03 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/27 11:02:30 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	encode_deliver(int pid, unsigned char package, int depth);

void	do_nothing(int id)
{
	if (id == SIGUSR2)
		write(1, "message was received.\n", 22);
}

int	ft_client(int pid, char *s)
{
	unsigned char		package;
	int					i;
	struct sigaction	action;

	if (sigemptyset(&action.sa_mask) == -1)
		return (-1);
	action.sa_handler = do_nothing;
	action.sa_flags = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		return (-1);
	while (*s != 0)
	{
		package = (unsigned char)*(s++);
		if (encode_deliver(pid, package, 0) == -1)
			break ;
	}
	i = 0;
	while (i++ < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (-1);
		usleep(TR_INTERVAL);
	}
	return (0);
}

int	encode_deliver(int pid, unsigned char package, int depth)
{
	if (depth < 7)
		if (encode_deliver(pid, package / 2, depth + 1) == -1)
			return (-1);
	if ((package & 0b1) == 0b0)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (-1);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			return (-1);
	}
	usleep(TR_INTERVAL);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	return (ft_client(pid, argv[2]));
}
