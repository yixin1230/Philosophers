/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/30 15:56:54 by yizhang       ########   odam.nl         */
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
		if (check_dead(philo) == 1)
			return (NULL);
		if (philo->nb_eaten >= philo->nb_t_eat)
		{
			philo->enough = 1;
			while (i < philo->n_philo)
			{
				if (philo->all->all_p[i].enough == 0)
					break ;
				i++;
			}
			if (i == philo->n_philo - 1)
				philo->all->enough_philos = 1;
		}
	}
	return (NULL);
}
