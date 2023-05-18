/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initualize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 11:25:25 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/18 14:37:09 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ini_data(t_data *all, char **argv)
{
	all->n_philo = ft_philo_atoi(argv[1]);
	all->t_die = ft_philo_atoi(argv[2]);
	all->t_eat = ft_philo_atoi(argv[3]);
	all->t_sleep = ft_philo_atoi(argv[4]);
	all->nb_t_eat = ft_philo_atoi(argv[5]);
	all->all_fork = malloc(all->n_philo * sizeof(pthread_mutex_init));
	if (!all->all_fork)
		return (-1);
	ini_mutex(all);
	if (all->n_philo < 1 || all->n_philo > 200 || all->t_die == 0 ||
		all->t_eat == 0 || all->t_sleep == 0 || all->nb_t_eat == 0)
		return (-1);
	all->all_p = malloc(all->n_philo * sizeof(t_philo));
	if (!all->all_p)
		return (-1);
	ini_philo(all);
	return (0);
}

long	ft_philo_atoi(char *str)
{
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	if (!str)
		return (-1);
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
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
		all->all_p[i].right = all->all_fork[i];
		all->all_p[i].left = all->all_fork[i + 1];
		i++;
	}
}

void	ini_mutex(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->n_philo)
	{
		if (pthread_mutex_init(&(all->all_fork[i]), NULL) == 0)
			return ;
		i++;
	}
}
/* 
int	init(t_data *all)
{

}
 */