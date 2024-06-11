/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:46:52 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 16:53:56 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

t_uni	*init_uni(char **av)
{
	t_uni	*uni;

	uni = (t_uni *)malloc(sizeof(t_uni));
	if (uni == NULL)
		return (NULL);
	uni->n_phi = ft_atoi(av[1]);
	if (uni->n_phi <= 0)
		return (free(uni), NULL);
	if (pthread_mutex_init(&(uni->print_lock), NULL) != 0)
		return (free(uni), NULL);
	if (pthread_mutex_init(&(uni->rw_lock), NULL) != 0)
		return (pthread_mutex_destroy(&(uni->print_lock)), free(uni), NULL);
	gettimeofday(&(uni->start), NULL);
	uni->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * uni->n_phi);
	if (uni->fork == NULL)
		return (pthread_mutex_destroy(&(uni->print_lock)),
			pthread_mutex_destroy(&(uni->rw_lock)), free(uni), NULL);
	uni->end = 0;
	uni->finished_eating = 0;
	return (uni);
}

int	is_all_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] < '0' || '9' < av[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_all_plus_int(int ac, char **av)
{
	long	num;
	int		i;

	i = 1;
	while (i < ac)
	{
		num = ft_atol(av[i]);
		if (num <= 0)
			return (0);
		if (num < (long)INT_MIN || (long)INT_MAX < num)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_arg(int ac, char **av)
{
	return (is_all_num(ac, av) * is_all_plus_int(ac, av));
}

int	init_phi(t_phi **phi_info, t_uni **uni, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < (*uni)->n_phi)
	{
		(*phi_info)[i].ttd = ft_atoi(av[2]);
		(*phi_info)[i].tte = ft_atoi(av[3]);
		(*phi_info)[i].tts = ft_atoi(av[4]);
		(*phi_info)[i].n_tpme = -1;
		if (ac == 6)
			(*phi_info)[i].n_tpme = ft_atoi(av[5]);
		(*phi_info)[i].n_eat = 0;
		(*phi_info)[i].name = i;
		(*phi_info)[i].uni = *uni;
		(*phi_info)[i].last_meal = (*uni)->start;
		(*phi_info)[i].last_action = (*phi_info)[i].last_meal;
		if (pthread_mutex_init(&((*uni)->fork[i]), NULL) != 0)
			return (destroy_fork((*uni)->fork, i),
				destroy_rw_lock(phi_info, i), -1);
		if (pthread_mutex_init(&((*phi_info)[i].ind_rw_lock), NULL) != 0)
			return (destroy_fork((*uni)->fork, i + 1),
				destroy_rw_lock(phi_info, i), -1);
		i++;
	}
	return (0);
}
