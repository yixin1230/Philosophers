/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:33:31 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/18 17:52:38 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	long	i;
	t_philo	*philo;
	long	start;
	long	end;

	philo = (t_philo *)arg;
	i = philo->id;
	start = ph_time();
	philo->non_eat_start = ph_time();
	while (philo->nb_eaten < philo->nb_t_eat && !philo->all->dead)
	{
		pthread_mutex_lock(&philo->right);
		end = ph_time();
		printf("%li %li has taken a fork\n", end - start, i);
		pthread_mutex_lock(&philo->left);
		end = ph_time();
		printf("%li %li has taken a fork\n", end - start, i);
		end = ph_time();
		printf("%li %li is eating\n", end - start, i);
		philo->non_eat_start = ph_time();
		usleep(philo->t_eat * 1000);
		pthread_mutex_unlock(&philo->right);
		pthread_mutex_unlock(&philo->left);
		end = ph_time();
		if (philo->all->dead)
			return (NULL);
		printf("%li %li is sleeping\n", end - start, i);
		usleep(philo->t_sleep * 1000);
		end = ph_time();
		printf("%li %li is thinking\n", end - start, i);
		end = ph_time();
		if (end - philo->non_eat_start >= philo->t_die)
		{
			printf("%li %li died\n",end - start, i);
			philo->all->dead = 1;
			return (NULL);
		}
		philo->nb_eaten++;
	}
	return (NULL);
}
