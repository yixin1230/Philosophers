/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 10:00:31 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/15 10:00:33 by yizhang       ########   odam.nl         */
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
				philo->all->all_p[i].stop = 1;
			philo->all->enough_philos = 1;
			return (1);
		}
	}
	return (0);
}

int	check_dead(t_philo *philo)
{
	int		i;
	long	time;

	i = -1;
	if (ph_time() > philo->t_die + philo->non_eat_start)
	{
		pthread_mutex_lock(&philo->all->lock);
		time = ph_time() - philo->all->time_start;
		while (++i < philo->all->n_philo)
			philo->all->all_p[i].stop = 1;
		philo->all->dead = 1;
		printf("%li %li died\n", time, philo->id);
		pthread_mutex_unlock(&philo->all->lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	int		i;
	t_philo	*philo;
	t_data	*all;

	i = 0;
	all = (t_data *)arg;
	philo = all->all_p;
	while (!all->dead)
	{
		i = 0;
		while (i < all->n_philo)
		{
			if (check_dead(&all->all_p[i]))
				return (NULL);
			if (philo->all->argc == 6 && check_meals(&all->all_p[i]))
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
	while (!philo->all->dead && !philo->stop)
	{
		eating(philo);
		thinking_sleeping(philo);
	}
	return (NULL);
}
