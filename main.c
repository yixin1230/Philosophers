/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 14:24:18 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_all(t_data *all)
{
	int	i;

	i = -1;
	while (i++ < all->n_philo)
	{
		pthread_mutex_destroy(&all->all_fork[i]);
		pthread_mutex_destroy(&all->all_p[i].lock_print);
	}
	pthread_mutex_destroy(&all->lock);
	free(all->all_p);
	free(all->all_fork);
	free(all->t);
	return (0);
}

/* void	leaks(void)
{
	system("leaks -q philo");
}
 */
int	main(int argc, char **argv)
{
	t_data	all;

	//atexit(leaks);
	if (checker(argc, argv) != 0)
		return (1);
	if (init(&all, argv, argc) != 0)
		return (2);
	free_all(&all);
	return (0);
}
