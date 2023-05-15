/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:33:31 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 12:44:39 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action(void	*arg)
{
	long	i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = philo->id;
	pthread_mutex_lock(&philo->right);
	printf("timestamp_in_ms %li has taken right fork\n", i);
	pthread_mutex_lock(&philo->left);
	printf("timestamp_in_ms %li has taken left fork\n", i);
	printf("timestamp_in_ms %li is eating\n", i);
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);
	printf("timestamp_in_ms %li is sleeping\n", i);
	printf("timestamp_in_ms %li is thinking\n", i);
	printf("timestamp_in_ms %li died\n", i);
	return (NULL);
}
