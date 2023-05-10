/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 11:42:34 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/10 18:15:32 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct ph
{
	long		nb;
	pthread_t	t;
}t_ph;

typedef struct data
{
	long	n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_t_eat;
	t_ph	*all_ph;
}t_data;



long	ft_philo_atoi(char *str);
int		initualize(t_data *all, char **argv);
void	fill_table(t_data *all, long nb);

#endif
