/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/18 14:37:23 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
1.check the condition:
	only numbers,
	can't be more than 200,
	can't be less than 1 philo,
	other things have to be bigger than 0;
2.initialization
3.action,supervisor(check if the time passed) and 
	monitor(check if all philo marked as finished)
4.clearing the memory
	join the threads
	destroy the mutexes
	clear the memory
	free all the allocations that we made
 */
int	main(int argc, char **argv)
{
	t_data	all;
	pthread_t	*t;
	int	i;

	i = 0;
	if (checker(argc, argv) < 0)
		return (1);
	if (ini_data(&all, argv) < 0)
		return (2);
	t = malloc(all.n_philo * sizeof(pthread_t));
	if (!t)
		return (3);
	while(i < all.n_philo)
	{
		pthread_create(&t[i], NULL, action, &(all.all_p[i]));
		i++;
	}
	i = 0;
	while(i < all.n_philo)
	{
		pthread_join(t[i], NULL);
		i++;
	}
	return (0);
}