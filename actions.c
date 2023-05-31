/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/31 15:08:39 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->non_eat_start = ph_time();
	while (!philo->all->dead || !philo->stop)
	{
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		taking_fork(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		eating(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		sleeping(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		thinking(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
	}
	return (NULL);
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	printf("%li %li has taken a fork[%i]\n", ph_time() - philo->all->time_start, philo->id,philo->right);
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	printf("%li %li has taken a fork[%i]\n", ph_time() - philo->all->time_start, philo->id,philo->left);
	
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%li %li is eating\n", ph_time() - philo->all->time_start, philo->id);
	my_usleep(philo->t_eat);
	if (philo->all->argc == 6)
		philo->nb_eaten++;
	philo->non_eat_start = ph_time();
	pthread_mutex_unlock(&philo->lock_print);
	pthread_mutex_unlock(&philo->all->all_fork[philo->right]);
	pthread_mutex_unlock(&philo->all->all_fork[philo->left]);
	
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%li %li is thinking\n", ph_time() - philo->all->time_start, philo->id);
	pthread_mutex_unlock(&philo->lock_print);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("%li %li is sleeping\n", ph_time() - philo->all->time_start, philo->id);
	my_usleep(philo->t_sleep);
	pthread_mutex_unlock(&philo->lock_print);
}
