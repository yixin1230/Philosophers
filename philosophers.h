/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 11:42:34 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/22 12:08:16 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct philo
{
	long			id;
	long		n_philo;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	long		nb_t_eat;
	long		nb_eaten;
	long		time_start;
	long		non_eat_start;
	int			stop;
	struct data		*all;
	pthread_mutex_t	right;
	pthread_mutex_t	left;
	pthread_mutex_t	lock_print;
}t_philo;

typedef struct data
{
	long			n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			nb_t_eat;
	int				dead;
	int				argc;
	t_philo			*all_p;
	pthread_t		*t;
	pthread_mutex_t	*all_fork;
}t_data;

int		checker(int argc, char **argv);
long	ft_philo_atoi(char *str);
long	ph_time(void);

int		ini_data(t_data *all, char **argv, int argc);
void	ini_philo(t_data *all);
void	ini_mutex(t_data *all);
int		init(t_data *all, char **argv, int argc);
int		allocate_all(t_data *all);

int		process(t_data *all);
void	*action(void *arg);
void	taking_fork(t_philo *philo, char c);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
int	check_dead(t_philo *philo);
int		free_all(t_data *all);

#endif
