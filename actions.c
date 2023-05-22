/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/22 17:32:24 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_start = ph_time();
	philo->non_eat_start = ph_time();
	while (!philo->all->dead || !philo->stop)
	{
		if (philo->all->dead || philo->stop)
			return (0);
		taking_fork(philo, 'r');
		if (philo->all->dead || philo->stop)
			return (0);
		eating(philo);
		if (philo->all->dead || philo->stop)
			return (0);
		sleeping(philo);
		if (philo->all->dead || philo->stop)
			return (0);
		thinking(philo);
		if (philo->all->argc == 6)
		{
			if (philo->nb_eaten >= philo->nb_t_eat)
				break ;
			philo->nb_eaten++;
		}
		if (philo->all->dead || philo->stop)
			return (0);
	}
	return (NULL);
}

void	taking_fork(t_philo *philo, char c)
{
	pthread_mutex_lock(&philo->all->lock_print);
	pthread_mutex_lock(&philo->right);
	printf("%li %li has taken a fork\n", ph_time() - philo->time_start, philo->id);
	pthread_mutex_lock(&philo->left);
	printf("%li %li has taken a fork\n", ph_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(&philo->all->lock_print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->lock_print);
	printf("%li %li is eating\n", ph_time() - philo->time_start, philo->id);
	my_usleep(philo->t_eat);
	philo->non_eat_start = ph_time();
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->all->lock_print);
	
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->lock_print);
	printf("%li %li is thinking\n", ph_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(&philo->all->lock_print);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->lock_print);
	printf("%li %li is sleeping\n", ph_time() - philo->time_start, philo->id);
	my_usleep(philo->t_sleep);
	pthread_mutex_unlock(&philo->all->lock_print);
}
