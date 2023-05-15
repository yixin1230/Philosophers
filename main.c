/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 12:38:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
1.define a struct ti represent the state of each philosopher
2.implement the behavior of the philosophers in a thread function
3.create philosopher thread and initialize the mutex
4.
 */

int	main(int argc, char **argv)
{
	t_data	all;
	pthread_t	*t;
	int	i;

	i = 0;
	if (argc != 6)
		return (1);
	if (ini_data(&all, argv) < 0)
		return (1);
	//printf("1:%li\n2:%li\n3:%li\n4:%li\n5:%li\n",all.n_philo,all.t_die,all.t_eat,all.t_sleep,all.nb_t_eat);
	t = malloc(all.n_philo * sizeof(pthread_t));
	if (!t)
		return (1);
	while(i < all.n_philo)
	{
		pthread_create(&t[i], NULL, action, &(all.all_p[i]));
		i++;
	}
	i = 0;
	while(i < all.n_philo)
	{
		pthread_join(t[i], NULL);
		i++;
	}
	return (0);
}