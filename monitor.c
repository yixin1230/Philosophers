/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:32:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/30 16:51:26 by yizhang       ########   odam.nl         */
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
		if (i == philo->n_philo - 1)
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
	while (1)
	{
		i = 0;
		while (i < philo[i].n_philo)
		{
			if (check_dead(&philo[i]))
				return (NULL);
			if (check_meals(&philo[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
