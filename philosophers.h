/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 11:42:34 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/31 15:32:27 by yizhang       ########   odam.nl         */
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
	long			n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			nb_t_eat;
	long			nb_eaten;
	long			non_eat_start;
	int				stop;
	int				enough;
	struct s_data	*all;
	int				right;
	int				left;
	pthread_mutex_t	lock_print;
}t_philo;

typedef struct s_data
{
	long			n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			nb_t_eat;
	int				dead;
	int				argc;
	long			time_start;	
	int				enough_philos;
	t_philo			*all_p;
	pthread_t		*t;
	pthread_mutex_t	*all_fork;
	pthread_mutex_t	lock;
}t_data;

int		checker(int argc, char **argv);
long	ft_philo_atoi(char *str);
long	ph_time(void);
void	my_usleep(unsigned int ms);

int		ini_data(t_data *all, char **argv, int argc);
void	ini_philo(t_data *all);
void	ini_mutex(t_data *all);
int		init(t_data *all, char **argv, int argc);
int		allocate_all(t_data *all);
int		int_thread(t_data *all);
int		check_meals(t_philo *philo);
void	*action(void *arg);
void	taking_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
int		check_dead(t_philo *philo);
int		free_all(t_data *all);
void	*monitor(void *arg);
#endif
