/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:20:54 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/31 15:13:49 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	
	if (argc != 6 && argc != 5)
		return (-1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ph_time(void)
{
	struct timeval current_time;
	long	ret;
	
	gettimeofday(&current_time,	NULL);
	ret = (long)current_time.tv_sec * 1000 + (long)current_time.tv_usec / 1000;
	return (ret);
}

void	my_usleep(unsigned int ms)
{
	long	time;

	time = ph_time();
	while (ph_time() - time < ms)
		usleep(923);
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

int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if (ph_time() - philo->non_eat_start >= philo->t_die)
	{
		//printf ("ph_time() - philo->non_eat_start: %li >= philo->t_die:%li\n", ph_time() - philo->non_eat_start ,philo->t_die);
		philo->all->dead = 1;
		pthread_mutex_lock(&philo->lock_print);
		printf("%li %li died\n", ph_time() - philo->all->time_start, philo->id);
		pthread_mutex_unlock(&philo->lock_print);
		while (i < philo->all->n_philo)
		{
			pthread_mutex_unlock(&philo->all->all_fork[i]);
			pthread_mutex_unlock(&philo->all->all_p[i].lock_print);
			philo->all->all_p[i].stop = 1;
			i++;
		}
		pthread_mutex_unlock(&philo->all->test);
		return (1);
	}
	return	(0);
}