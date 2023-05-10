/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initualize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 11:25:25 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/10 18:06:51 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initualize(t_data *all, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	all = (t_data *)malloc(sizeof(t_data));
	if (!all)
		return (-1);
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
	all->all_ph = NULL;
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

t_ph	*new_ph(long	i)
{
	t_ph	*new;
	pthread_t	t;

	new = (t_ph *)malloc(sizeof(t_ph));
	new->t = t;
	new->nb = i;
	new->prev = new;
	new->next = new;
	return (new);
}

void	add_ph_back(t_ph **top, t_ph *new)
{
	if (!new)
		return ;
	if (!*top)
		*top = new;
	else
	{
		new->next = *top;
		new->prev = (*top)->prev;
		new->prev->next = new;
		(*top)->prev = new;
	}
}

void	fill_table(t_data *all, long nb)
{
	long	i;

	i = 1;
	while(i <= nb)
	{
		add_ph_back(&all->all_ph, new_ph(i));
		i++;
	}
}