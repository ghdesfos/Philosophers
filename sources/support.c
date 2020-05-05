/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:13:26 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/01/25 22:14:59 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	err_exit(int s, char *str)
{
	b_printf("Error: %s\n", str);
	exit(-1);
	(void)s;
}

void	sleep_global(int time_to_sleep)
{
	time_t			start_time;
	time_t			curr_time;
	struct timespec	tp;

	clock_gettime(CLOCK_REALTIME, &tp);
	start_time = tp.tv_sec;
	while (1)
	{
		clock_gettime(CLOCK_REALTIME, &tp);
		curr_time = tp.tv_sec;
		if (curr_time - start_time >= time_to_sleep)
			break ;
		usleep(500000);
	}
}

/*
**	The read() prevents the freeing of the resources before a key
**	has been pressed by the user.
**	When we reach this function, all mutexes must have been previously unlocked
**	so pthread_mutex_destroy() should not fail.
*/

void	free_resources(t_phil *philos)
{
	int		i;
	int		s;
	char	c;

	read(STD_IN, &c, 1);
	i = -1;
	while (++i < NB_PHILO)
	{
		s = pthread_mutex_destroy(philos[i].mtx);
		if (s != 0)
			err_exit(s, "pthread_mutex_destroy");
		free(philos[i].mtx);
	}
}
