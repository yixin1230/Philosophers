/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initualize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 11:25:25 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/02 17:08:46 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ini_data(t_data *all, char **argv, int argc)
{
	all->n_philo = ft_philo_atoi(argv[1]);
	all->t_die = ft_philo_atoi(argv[2]);
	all->t_eat = ft_philo_atoi(argv[3]);
	all->t_sleep = ft_philo_atoi(argv[4]);
	all->enough_philos = 0;
	all->argc = argc;
	all->enough_philos = 0;
	if (argc == 6)
		all->nb_t_eat = ft_philo_atoi(argv[5]);
	else
		all->nb_t_eat = -1;
	all->dead = 0;
	if (all->n_philo < 1 || all->n_philo > 200 || all->t_die == 0 ||
		all->t_eat == 0 || all->t_sleep == 0 || (all->nb_t_eat < 1 && argc == 6))
		return (1);
	return (0);
}

void	ini_philo(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->n_philo)
	{
		all->all_p[i].id = 1 + i;
		all->all_p[i].n_philo = all->n_philo;
		all->all_p[i].t_die = all->t_die;
		all->all_p[i].t_eat = all->t_eat;
		all->all_p[i].t_sleep = all->t_sleep;
		all->all_p[i].nb_t_eat = all->nb_t_eat;
		all->all_p[i].right = i;
		if (i != all->n_philo - 1)
			all->all_p[i].left = i + 1;
		else
			all->all_p[i].left = 0;
		all->all_p[i].nb_eaten = 0;
		all->all_p[i].stop = 0;
		all->all_p[i].enough = 0;
		all->all_p[i].all = all;
		all->all_p[i].non_eat_start = ph_time();
		i++;
	}
}

void	ini_mutex(t_data *all)
{
	int	i;

	i = -1;
	pthread_mutex_init(&all->lock, NULL);
	while (++i < all->n_philo)
	{
		pthread_mutex_init(&all->all_p[i].lock_print, NULL);
		pthread_mutex_init(&all->all_fork[i], NULL);
	}
}

int	allocate_all(t_data *all)
{
	all->t = malloc(all->n_philo * sizeof(pthread_t));
	if (!all->t)
		return (1);
	all->all_fork = malloc(all->n_philo * sizeof(pthread_mutex_t));
	if (!all->all_fork)
		return (2);
	all->all_p = malloc(all->n_philo * sizeof(t_philo));
	if (!all->all_p)
		return (3);
	return (0);
}

int	ini_thread(t_data *all)
{
	int			i;
	pthread_t	moni;

	i = -1;
	all->time_start = ph_time();
	pthread_create(&moni, NULL, monitor, all->all_p);
	while (++i < all->n_philo)
		pthread_create(&all->t[i], NULL, action, &all->all_p[i]);
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
