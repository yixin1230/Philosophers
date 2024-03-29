/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/15 09:56:56 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	taking_fork_else(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	message (philo, "has taken a fork");
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	message (philo, "has taken a fork");
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	message (philo, "has taken a fork");
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	message (philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 != 0)
		taking_fork(philo);
	else
		taking_fork_else(philo);
	pthread_mutex_lock(&philo->lock_print);
	philo->non_eat_start = ph_time();
	message (philo, "is eating");
	my_usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->lock_print);
	pthread_mutex_lock(&philo->lock_print);
	if (philo->all->argc == 6)
		philo->nb_eaten++;
	pthread_mutex_unlock(&philo->lock_print);
	drop_fork(philo);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->all->all_fork[philo->right]);
	pthread_mutex_unlock(&philo->all->all_fork[philo->left]);
}

void	thinking_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	message (philo, "is sleeping");
	my_usleep(philo->t_sleep);
	pthread_mutex_unlock(&philo->lock_print);
	message (philo, "is thinking");
	if (philo->t_eat >= philo->t_sleep && philo->n_philo % 2 != 0)
		my_usleep(philo->t_eat - philo->t_sleep + 5);
}
