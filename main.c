/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/18 18:21:58 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	all;
	int	i;

	i = 0;
	if (checker(argc, argv) < 0)
		return (1);
	if (init(&all, argv) != 0)
		return (2);
	while(i < all.n_philo && !all.dead)
	{
		if (all.dead)
			return (0);
		pthread_create(&all.t[i], NULL, action, &(all.all_p[i]));
		i++;
	}
	i = 0;
	while(i < all.n_philo)
	{
		if (all.dead)
			return (0);
		pthread_join(all.t[i], NULL);

		i++;
	}
	return (0);
}