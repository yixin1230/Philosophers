/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:33:31 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/18 15:49:59 by yizhang       ########   odam.nl         */
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
	pthread_mutex_lock(&philo->right);
	end = ph_time();
	printf("%li %li has taken right fork\n", end - start, i);
	pthread_mutex_lock(&philo->left);
	end = ph_time();
	printf("%li %li is eating\n", end - start, i);
	usleep(philo->t_eat * 1000);
	end = ph_time();
	printf("%li %li has taken left fork\n", end - start, i);
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);
	end = ph_time();
	printf("%li %li is sleeping\n", end - start, i);
	usleep(philo->t_sleep * 1000);
	end = ph_time();
	printf("%li %li is thinking\n", end - start, i);
	end = ph_time();
	if (end - start >= philo->t_die)
	{
		printf("%li %li died\n",end - start, i);
	}
	return (NULL);
}
