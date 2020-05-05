/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:12:42 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/01/25 22:24:24 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_mutexes(void)
{
	int	i;
	int	s;

	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_mutex_init(g_mtx + i, NULL);
		if (s != 0)
			err_exit(s, "pthread_mutex_init");
	}
}

void	destroy_mutexes(void)
{
	int	i;
	int	s;

	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_mutex_destroy(g_mtx + i);
		if (s != 0)
			err_exit(s, "pthread_mutex_destroy");
	}
}
