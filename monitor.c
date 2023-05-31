/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/31 11:56:37 by yizhang       ########   odam.nl         */
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
	while (!philo->all->dead)
	{
		i = 0;
		while (i < philo[i].n_philo)
		{
			//printf("ph: %i, ph_time() - philo->non_eat_start: %li\n",i, ph_time() - philo[i].non_eat_start);
			if (check_dead(&philo[i])||check_meals(&philo[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
