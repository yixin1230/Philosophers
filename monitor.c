/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 13:27:55 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_meals(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->nb_eaten >= philo->nb_t_eat)
	{
		philo->enough = 1;
		while (i < philo->n_philo)
		{
			if (philo->all->all_p[i].enough == 0)
				break ;
			i++;
		}
		if (i == philo->n_philo)
		{
			i = 0;
			while (i < philo->all->n_philo)
			{
				pthread_mutex_unlock(&philo->all->all_fork[i]);
				pthread_mutex_unlock(&philo->all->all_p[i].lock_print);
				philo->all->all_p[i].stop = 1;
				i++;
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
	philo->all->time_start = ph_time();
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
