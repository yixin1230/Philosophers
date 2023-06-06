/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 17:55:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->nb_eaten >= philo->nb_t_eat)
	{
		philo->enough = 1;
		while (++i < philo->n_philo)
		{
			if (philo->all->all_p[i].enough == 0)
				break ;
		}
		if (i == philo->n_philo)
		{
			i = -1;
			while (++i < philo->all->n_philo)
			{
				pthread_mutex_unlock(&philo->all->all_fork[i]);
				pthread_mutex_unlock(&philo->all->all_p[i].lock_print);
				philo->all->all_p[i].stop = 1;
			}
			philo->all->enough_philos = 1;
			return (1);
		}
	}
	return (0);
}

void	*monitor(void *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)arg;
	while (!philo->all->dead || !philo->stop || !philo->all->enough_philos)
	{
		i = 0;
		while (i < philo->n_philo)
		{
			if (check_dead(&philo->all->all_p[i]))
				return (NULL);
			if (philo->all->argc == 6 && check_meals(&philo->all->all_p[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*action(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->all->dead || !philo->stop)
	{
		if (philo->id % 2 == 0 && philo->id != philo->n_philo)
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
