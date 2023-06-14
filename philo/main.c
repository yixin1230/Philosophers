/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/14 12:46:46 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_all(t_data *all)
{
	int	i;

	i = -1;
	free(all->t);
	while (i++ < all->n_philo)
	{
		pthread_mutex_destroy(&all->all_fork[i]);
		pthread_mutex_destroy(&all->all_p[i].lock_print);
	}
	pthread_mutex_destroy(&all->lock);
	free(all->all_fork);
	free(all->all_p);
	return (0);
}

int	ini_thread(t_data *all)
{
	int			i;
	pthread_t	moni;

	i = -1;
	all->time_start = ph_time();
	pthread_create(&moni, NULL, monitor, all);
	while (++i < all->n_philo)
		pthread_create(&all->t[i], NULL, action, &all->all_p[i]);
	if (all->n_philo == 1)
	{
		pthread_detach(all->t[0]);
		pthread_join(moni, NULL);
		return (0);
	}
	i = -1;
	while (++i < all->n_philo)
		pthread_join(all->t[i], NULL);
	pthread_join(moni, NULL);
	return (0);
}

int	init(t_data *all, char **argv, int argc)
{
	if (ini_data(all, argv, argc) != 0)
		return (1);
	if (allocate_all(all) != 0)
		return (1);
	ini_mutex(all);
	ini_philo(all);
	ini_thread(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	all;

	if (checker(argc, argv) != 0)
		return (1);
	if (init(&all, argv, argc) != 0)
		return (2);
	free_all(&all);
	return (0);
}
