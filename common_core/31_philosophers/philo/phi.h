/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:50:34 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 15:08:11 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHI_H
# define PHI_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_uni
{
	int				n_phi;
	int				end;
	int				finished_eating;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	rw_lock;
	struct timeval	start;
	pthread_mutex_t	*fork;
}	t_uni;

typedef struct s_phi
{
	int				ttd;
	int				tte;
	int				tts;
	int				n_tpme;
	int				n_eat;
	int				name;
	pthread_mutex_t	ind_rw_lock;
	struct timeval	last_action;
	struct timeval	last_meal;
	struct s_uni	*uni;
}	t_phi;

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

void	*philosophers(void *phi_info);
void	*grim(void *phi_info);

void	philosophers_eat(t_phi *phi_info, int fork[2]);
void	philosophers_think(t_phi *phi_info);
void	philosophers_sleep(t_phi *phi_info);

void	philosophers_print(t_phi *phi_info, char *str, int end);
int		philosophers_rw_end(t_phi *phi_info, char mode);
void	philosophers_rw_time(t_phi *phi_info, char mode, struct timeval *time);
long	get_elspsed_time(struct timeval start, struct timeval now);

int		is_valid_arg(int ac, char **av);
void	clean_uni(t_uni **uni);
t_uni	*init_uni(char **av);
int		init_phi(t_phi **phi_info, t_uni **uni, char **av, int ac);

void	destroy_fork(pthread_mutex_t *thread, int num);
void	destroy_rw_lock(t_phi **phi_info, int num);
void	cleanup_all(t_phi **phi_info, pthread_t **phis);

#endif