/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/23 15:51:30 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)arg;
	while (!philo->stop || !philo->all->dead)
	{
		if (ph_time() - philo->non_eat_start >= philo->t_die)
		{
			philo->all->dead = 1;
			pthread_mutex_lock(&philo->all->lock_print);
			printf("%li %li died\n", ph_time() - philo->time_start, philo->id);
			pthread_mutex_unlock(&philo->all->lock_print);
			while (i < philo->all->n_philo)
			{
				pthread_mutex_unlock(&philo->all->all_fork[i]);
				philo->all->all_p[i].stop = 1;
				i++;
			}
			return (NULL);
		}
	}
	return (NULL);
}

