/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:48:44 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/01/25 22:22:16 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

# include "../b_printf/b_printf.h"

# define NB_PHILO		7

# define TIME_EAT		4
# define TIME_REST		2
# define TIME_THINK		3

# define TIMEOUT		100

# define PHILO_LIFE		50

# define STD_IN			0

typedef struct			s_phil
{
	int					philo_nb;
	int					life;
	int					left_chopstick;
	int					right_chopstick;
	pthread_mutex_t		*mtx;
}						t_phil;

pthread_mutex_t			g_mtx[NB_PHILO];

/*
**	Below we used the macros defined in the <ncurses.h> header.
*/

# define BLUE			COLOR_CYAN
# define GREEN			COLOR_GREEN
# define YELLOW			COLOR_YELLOW
# define RED			COLOR_RED
# define WHITE			COLOR_WHITE
# define BLACK			COLOR_BLACK

# define C_PAIR_BLUE	1
# define C_PAIR_GREEN	2
# define C_PAIR_YELLOW	3
# define C_PAIR_RED		4
# define C_PAIR_WHITE	5

/*
**	BELOW FUNCTIONS
*/

void					check_end_dinner(time_t start_time, time_t curr_time);
void					reduce_life_of_philosophers(t_phil *philos, \
														time_t prev_time, \
														time_t curr_time);
void					monitor_life_of_philosophers(t_phil *philos);

void					initialize_mutexes(void);
void					destroy_mutexes(void);

void					restore_life_philosopher(t_phil *philo);
void					*thread_philosopher(void *arg);
t_phil					*setup_struct_phil(t_phil	*philo, int philo_nb);
void					create_threads(pthread_t *tid, t_phil *philos);
void					join_threads(pthread_t *tid);

int						pickup_second_chopstick(t_phil *philo);
void					pickup(t_phil *philo);
void					putdown(t_phil *philo);

void					set_up_ncurses_environment(void);
void					end_ncurses_environment(void);
void					update_visualization(t_phil *philos);

void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					err_exit(int s, char *str);
void					sleep_global(int time_to_sleep);
void					free_resources(t_phil *philos);

#endif
