/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:53:21 by ashih             #+#    #+#             */
/*   Updated: 2018/01/30 22:13:01 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Color Pair 0 ~ 4:		Who last wrote to the core
** Color Pair 5 ~ 8:		Process's PC on the core
** Color Pair 9 ~ 13:		Highlight PID after a live instruction on the core
*/

int		init_ncurses_stuffz(t_master *m)
{
	initscr();
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_YELLOW);
	init_pair(11, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(12, COLOR_WHITE, COLOR_CYAN);
	init_pair(13, COLOR_WHITE, COLOR_RED);
	raw();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	noecho();
	refresh();
	init_windows(m);
	return (0);
}

int		init_windows(t_master *m)
{
	m->win_banner = newwin(24 - 2, 195, 0, 0);
	wprintw(m->win_banner, "%s", BANNER);
	box(m->win_banner, 0, 0);
	wrefresh(m->win_banner);
	m->win_core = newwin(66, 195, 24 - 2, 0);
	display_core(m);
	m->win_control = newwin(26 - 4, 50, 0, 195 + 1);
	display_control(m);
	m->win_player[0] = newwin(15 + 1, 50, 25 + 1 - 4, 195 + 1);
	m->win_player[1] = newwin(15 + 1, 50, 40 + 2 - 3 - 1, 195 + 1);
	m->win_player[2] = newwin(15 + 1, 50, 55 + 3 - 2 - 2, 195 + 1);
	m->win_player[3] = newwin(15 + 1, 50, 70 + 4 - 1 - 3, 195 + 1);
	display_players(m);
	m->win_extra = newwin(2, 50, 85 + 5 - 1 - 3, 195 + 1);
	wprintw(m->win_extra, "This program was made possible thanks to\n"\
							"contributions from viewers like you!");
	wrefresh(m->win_extra);
	return (0);
}

void	update_windows(t_master *m)
{
	display_core(m);
	display_control(m);
	display_players(m);
}
