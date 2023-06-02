/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 13:27:13 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->non_eat_start = ph_time();
	//philo->all->time_start = ph_time();
	while (!philo->all->dead || !philo->stop)
	{
		if (philo->id % 2 == 0)
			taking_fork(philo);
		else
			taking_fork_odd(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		eating(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		sleeping(philo);
		if (philo->all->dead || philo->stop || philo->all->enough_philos)
			return (0);
		thinking(philo);
	}
	return (NULL);
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork1\n", ph_time() - philo->all->time_start, philo->id);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork2\n", ph_time() - philo->all->time_start, philo->id);
}

void	taking_fork_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork1\n", ph_time() - philo->all->time_start, philo->id);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork2\n", ph_time() - philo->all->time_start, philo->id);
}

void	eating(t_philo *philo)
{
	printf("%li %li is eating\n", ph_time() - philo->all->time_start, philo->id);
	usleep(philo->t_eat * 1000);
	if (philo->all->argc == 6)
		philo->nb_eaten++;
	philo->non_eat_start = ph_time();
	pthread_mutex_unlock(&philo->all->all_fork[philo->right]);
	pthread_mutex_unlock(&philo->all->all_fork[philo->left]);
}

void	thinking(t_philo *philo)
{
	printf("%li %li is thinking\n", ph_time() - philo->all->time_start, philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("%li %li is sleeping\n", ph_time() - philo->all->time_start, philo->id);
	usleep(philo->t_sleep * 1000);
}
