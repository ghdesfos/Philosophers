/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopstick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:55:05 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/02/19 19:56:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	RIGHT_CHOPSTICK:	(g_mtx + philo->philo_nb)
**	LEFT_CHOPSTICK:		(g_mtx + (philo->philo_nb + 1) % NB_PHILO)
*/

int		pickup_second_chopstick(t_phil *philo)
{
	int s;

	if (philo->philo_nb % 2 == 0)
	{
		s = pthread_mutex_lock(g_mtx + (philo->philo_nb + 1) % NB_PHILO);
		(s == 0) ? philo->left_chopstick = 1 : 0;
	}
	else
	{
		s = pthread_mutex_lock(g_mtx + philo->philo_nb);
		(s == 0) ? philo->right_chopstick = 1 : 0;
	}
	if (s == 0)
		return (1);
	return (0);
}

void	pickup(t_phil *philo)
{
	int s;

	if (philo->philo_nb % 2 == 0)
	{
		s = pthread_mutex_lock(g_mtx + philo->philo_nb);
		(s == 0) ? philo->right_chopstick = 1 : 0;
	}
	else
	{
		s = pthread_mutex_lock(g_mtx + (philo->philo_nb + 1) % NB_PHILO);
		(s == 0) ? philo->left_chopstick = 1 : 0;
	}
	if (s == 0)
	{
		sleep_global(TIME_THINK);
		if (pickup_second_chopstick(philo))
			return ;
	}
	else
		err_exit(s, "pthread_mutex_lock");
}

void	putdown(t_phil *philo)
{
	philo->left_chopstick = 0;
	pthread_mutex_unlock(g_mtx + (philo->philo_nb + 1) % NB_PHILO);
	philo->right_chopstick = 0;
	pthread_mutex_unlock(g_mtx + philo->philo_nb);
}
