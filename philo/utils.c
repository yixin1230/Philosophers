/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 10:00:49 by yizhang       #+#    #+#                 */
/*   Updated: 2023/06/15 10:00:51 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	message(t_philo *philo, char *str)
{
	if (!philo->all->dead && !philo->stop && !philo->all->enough_philos)
		printf("%li %li %s\n",
			ph_time() - philo->all->time_start, philo->id, str);
}

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
	struct timeval	current_time;
	long			ret;

	gettimeofday(&current_time, NULL);
	ret = (long)current_time.tv_sec * 1000 + (long)current_time.tv_usec / 1000;
	return (ret);
}

void	my_usleep(long ms)
{
	long	timestamp;

	timestamp = ph_time();
	while (ph_time() - timestamp < ms)
		usleep(150);
}

long	ft_philo_atoi(char *str)
{
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
