/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:10:39 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/01/25 22:23:45 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		g_end_dinner = 0;
int		g_dead_philosopher = 0;

#define PHILOSOPHER_NOT_ALREADY_DEAD	0

void	check_end_dinner(time_t start_time, time_t curr_time)
{
	if (curr_time - start_time >= TIMEOUT)
	{
		if (g_dead_philosopher == PHILOSOPHER_NOT_ALREADY_DEAD)
			ft_putstr_fd("Now, it is time... To DAAAAAAAANCE ! ! !\n", 1);
		g_end_dinner = 1;
	}
}

#define DINNER_NOT_ALREADY_FINISHED		0

void	reduce_life_of_philosophers(t_phil *philos, time_t prev_time, \
										time_t curr_time)
{
	int	i;
	int	s;

	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_mutex_lock(philos[i].mtx);
		if (s != 0)
			err_exit(s, "pthread_mutex_lock");
		philos[i].life -= curr_time - prev_time;
		if (philos[i].life <= 0)
		{
			if (g_end_dinner == DINNER_NOT_ALREADY_FINISHED)
				ft_putstr_fd("ARGHHHH, A philosopher is dead ! ! !\n", 1);
			g_dead_philosopher = 1;
			return ;
		}
		s = pthread_mutex_unlock(philos[i].mtx);
		if (s != 0)
			err_exit(s, "pthread_mutex_unlock");
	}
}

void	monitor_life_of_philosophers(t_phil *philos)
{
	time_t			start_time;
	time_t			curr_time;
	time_t			prev_time;
	struct timespec	tp;

	clock_gettime(CLOCK_REALTIME, &tp);
	start_time = tp.tv_sec;
	prev_time = tp.tv_sec;
	while (1)
	{
		clock_gettime(CLOCK_REALTIME, &tp);
		curr_time = tp.tv_sec;
		check_end_dinner(start_time, curr_time);
		reduce_life_of_philosophers(philos, prev_time, curr_time);
		update_visualization(philos);
		if (g_end_dinner == 1 || g_dead_philosopher == 1)
			return ;
		usleep(10000);
		prev_time = curr_time;
	}
}

int		main(void)
{
	pthread_t	tid[NB_PHILO];
	t_phil		philos[NB_PHILO];

	set_up_ncurses_environment();
	initialize_mutexes();
	create_threads(tid, philos);
	monitor_life_of_philosophers(philos);
	join_threads(tid);
	destroy_mutexes();
	free_resources(philos);
	end_ncurses_environment();
	return (0);
}
