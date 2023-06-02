/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 17:39:19 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork\n",
		ph_time() - philo->all->time_start, philo->id);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork\n",
		ph_time() - philo->all->time_start, philo->id);
}

void	taking_fork_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->all_fork[philo->left]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork\n",
		ph_time() - philo->all->time_start, philo->id);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	pthread_mutex_lock(&philo->all->all_fork[philo->right]);
	if (philo->all->dead || philo->stop || philo->all->enough_philos)
		return ;
	printf("%li %li has taken a fork\n",
		ph_time() - philo->all->time_start, philo->id);
}

void	eating(t_philo *philo)
{
	philo->non_eat_start = ph_time();
	printf("%li %li is eating\n",
		ph_time() - philo->all->time_start, philo->id);
	my_usleep(philo->t_eat);
	if (philo->all->argc == 6)
		philo->nb_eaten++;
	pthread_mutex_unlock(&philo->all->all_fork[philo->right]);
	pthread_mutex_unlock(&philo->all->all_fork[philo->left]);
}

void	thinking(t_philo *philo)
{
	printf("%li %li is thinking\n",
		ph_time() - philo->all->time_start, philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("%li %li is sleeping\n",
		ph_time() - philo->all->time_start, philo->id);
	my_usleep(philo->t_sleep);
}
