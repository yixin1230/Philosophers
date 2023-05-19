/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 16:20:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:23:31 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	t_philo	*philo;


	philo = (t_philo *)arg;
	philo->time_start = ph_time();
	philo->non_eat_start = ph_time();
	while (!check_dead(philo))
	{
		taking_fork(philo, 'r');
		taking_fork(philo, 'l');
		eating(philo);
		sleeping(philo);
		if (philo->all->dead)
			return (0);
		thinking(philo);
		if (philo->all->argc == 6)
		{
			if (philo->nb_eaten >= philo->nb_t_eat)
				break ;
			philo->nb_eaten++;
		}
	}
	return (NULL);
}

void	taking_fork(t_philo *philo, char c)
{
	if (c == 'r')
		pthread_mutex_lock(&philo->right);
	else
		pthread_mutex_lock(&philo->left);
	philo->time_end = ph_time();
	printf("%li %li has taken a fork\n", philo->time_end - philo->time_start, philo->id);
}

void	eating(t_philo *philo)
{
	philo->time_end = ph_time();
	printf("%li %li is eating\n", philo->time_end - philo->time_start, philo->id);
	philo->non_eat_start = ph_time();
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);
}

void	thinking(t_philo *philo)
{
	philo->time_end = ph_time();
	printf("%li %li is thinking\n", philo->time_end - philo->time_start, philo->id);
}

void	sleeping(t_philo *philo)
{
	philo->time_end = ph_time();
	printf("%li %li is sleeping\n", philo->time_end -philo->time_start, philo->id);
	usleep(philo->t_sleep * 1000);
}
