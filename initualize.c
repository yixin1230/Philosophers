/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initualize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 11:25:25 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/10 13:57:34 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initualize(t_philo *all, char **argv)
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
	all->number_of_philosophers = ft_philo_atoi(argv[1]);
	all->time_to_die = ft_philo_atoi(argv[2]);
	all->time_to_eat = ft_philo_atoi(argv[3]);
	all->time_to_sleep = ft_philo_atoi(argv[4]);
	all->number_of_times_each_philosopher_must_eat = ft_philo_atoi(argv[5]);
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