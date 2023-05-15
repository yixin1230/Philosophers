/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initualize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 11:25:25 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 12:37:25 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ini_data(t_data *all, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (i < 6)
	{
		nb = ft_philo_atoi(argv[i]);
		if (nb < 0)
			return (-1);
		i++;
	}
	all->n_philo = ft_philo_atoi(argv[1]);
	all->t_die = ft_philo_atoi(argv[2]);
	all->t_eat = ft_philo_atoi(argv[3]);
	all->t_sleep = ft_philo_atoi(argv[4]);
	all->nb_t_eat = ft_philo_atoi(argv[5]);
	all->all_p = malloc(all->n_philo * sizeof(t_philo));
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
		pthread_mutex_init(&(all->all_p[i].left), NULL);
		pthread_mutex_init(&(all->all_p[i].right), NULL);
		i++;
	}
}