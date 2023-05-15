/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:33:31 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 14:34:34 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	long	i;
	t_philo	*philo;
	struct timeval	current_time;

	philo = (t_philo *)arg;
	i = philo->id;
	pthread_mutex_lock(&philo->right);
	gettimeofday(&current_time, NULL);
	printf("%d %li has taken right fork\n", current_time.tv_usec/1000, i);
	pthread_mutex_lock(&philo->left);
	gettimeofday(&current_time, NULL);
	printf("%d %li has taken left fork\n", current_time.tv_usec/1000, i);
	printf("timestamp_in_ms %li is eating\n", i);
	usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);
	printf("timestamp_in_ms %li is sleeping\n", i);
	usleep(philo->t_sleep);
	printf("timestamp_in_ms %li is thinking\n", i);
	if (current_time.tv_usec/1000 >= philo->t_die)
	{
		printf("timestamp_in_ms %li died\n", i);
	}
	return (NULL);
}
