/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:22:39 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	process(t_data *all)
{
	int	i;

	i = 0;
	while(i < all->n_philo && !all->dead)
	{
		pthread_create(&all->t[i], NULL, action, &(all->all_p[i]));
		i++;
	}
	i = 0;
	while(i < all->n_philo && !all->dead)
	{
		pthread_join(all->t[i], NULL);
		i++;
	}
	return (0);
}

int	free_all(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->n_philo)
	{
		if(pthread_mutex_destroy(&all->all_fork[i]) != 0)
			return (1);
		i++;
	}
	while (i < all->n_philo)
	{
		if (pthread_detach(all->t[i]) != 0)
			return (1);
		i++;
	}
	if (all->all_p)
		free(all->all_p);
	if (all->all_fork)
		free(all->all_fork);
	if (all->t)
		free(all->t);
	return (0);
}

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_data	all;

	//atexit(leaks);
	if (checker(argc, argv) != 0)
		return (1);
	if (init(&all, argv, argc) != 0)
		return (2);
	process(&all);
	free_all(&all);
	return (0);
}
