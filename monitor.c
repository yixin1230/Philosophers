/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/22 17:54:29 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *arg)
{
	int	i;

	i = 0;
	if (philo->stop || philo->all->dead)
		return (1);
	while (1)
	{
	if (ph_time() - philo->non_eat_start >= philo->t_die)
	{
		philo->all->dead = 1;
		printf("%li %li died\n", ph_time() - philo->time_start, philo->id);
		while (i < philo->all->n_philo)
		{
			pthread_mutex_unlock(&philo->all->all_fork[i]);
			pthread_mutex_lock(&philo->all->lock_print);
			philo->all->all_p[i].stop = 1;
			i++;
		}
		return (1);
	}
	}
	return (NULL);
}

