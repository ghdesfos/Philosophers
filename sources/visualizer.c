/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:45:46 by ghdesfos          #+#    #+#             */
/*   Updated: 2020/02/19 12:28:02 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_up_ncurses_environment(void)
{
	initscr();
	curs_set(0);
	start_color();
	init_pair(C_PAIR_BLUE, BLUE, BLACK);
	init_pair(C_PAIR_BLUE, BLUE, BLACK);
	init_pair(C_PAIR_GREEN, GREEN, BLACK);
	init_pair(C_PAIR_YELLOW, YELLOW, BLACK);
	init_pair(C_PAIR_RED, RED, BLACK);
	init_pair(C_PAIR_WHITE, WHITE, BLACK);
}

void	end_ncurses_environment(void)
{
	endwin();
}

void	update_visualization(t_phil *philos)
{
	int i;

	move(0, 0);
	printw("Simulation of the philosophers' dinner:\n\n");
	i = -1;
	while (++i < NB_PHILO)
	{
		printw("Philosopher number: %d\n", philos[i].philo_nb);
		printw("Life: %d\n", philos[i].life);
		if (philos[i].left_chopstick && philos[i].right_chopstick)
			printw("State: %s\n", "Eating");
		else if (philos[i].left_chopstick || philos[i].right_chopstick)
			printw("State: %s\n", "Thinking");
		else
			printw("State: %s\n", "Resting");
		printw("%s\n", (philos[i].right_chopstick) ? "------" : " ");
		printw("/----\\    o\n");
		printw("|    |   \\|/\n");
		printw("|    |    |\n");
		printw("\\----/   /|\n");
		printw("%s\n\n", (philos[i].left_chopstick) ? "------" : " ");
		refresh();
	}
}
