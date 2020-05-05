/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:32 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/01/25 21:44:45 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

extern int	g_end_dinner;
extern int	g_dead_philosopher;

void		restore_life_philosopher(t_phil *philo)
{
	int s;

	s = pthread_mutex_lock(philo->mtx);
	if (s != 0)
		err_exit(s, "pthread_mutex_lock");
	philo->life = PHILO_LIFE;
	s = pthread_mutex_unlock(philo->mtx);
	if (s != 0)
		err_exit(s, "pthread_mutex_unlock");
}

void		*thread_philosopher(void *arg)
{
	t_phil *philo;

	philo = (t_phil*)arg;
	while (1)
	{
		pickup(philo);
		sleep_global(TIME_EAT);
		restore_life_philosopher(philo);
		putdown(philo);
		sleep_global(TIME_REST);
		if (g_dead_philosopher == 1 || g_end_dinner == 1)
			return (NULL);
	}
	return (NULL);
}

t_phil		*setup_struct_phil(t_phil *philo, int philo_nb)
{
	int s;

	philo->philo_nb = philo_nb;
	philo->life = PHILO_LIFE;
	philo->left_chopstick = 0;
	philo->right_chopstick = 0;
	if (!(philo->mtx = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
		return (NULL);
	s = pthread_mutex_init(philo->mtx, NULL);
	if (s != 0)
		err_exit(s, "pthread_mutex_init");
	return (philo);
}

void		create_threads(pthread_t *tid, t_phil *philos)
{
	int	i;
	int	s;

	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_create(tid + i, NULL, &thread_philosopher,
							(void*)setup_struct_phil(philos + i, i));
		if (s != 0)
			err_exit(s, "pthread_create");
	}
}

void		join_threads(pthread_t *tid)
{
	int	i;
	int	s;

	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_join(tid[i], NULL);
		if (s != 0)
			err_exit(s, "pthread_join");
	}
}
