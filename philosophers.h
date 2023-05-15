/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 11:42:34 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 10:54:22 by yizhang       ########   odam.nl         */
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
	pthread_mutex_t	left;
	pthread_mutex_t	right;
}t_philo;

typedef struct data
{
	long	n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_t_eat;
	t_philo	*all_p;
}t_data;



long	ft_philo_atoi(char *str);
int		ini_data(t_data *all, char **argv);
void	ini_philo(t_data *all);
void	*action(void	*arg);

#endif
