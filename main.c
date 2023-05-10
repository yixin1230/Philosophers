/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/10 18:09:11 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
1.create philosophers
2.
 */

int	main(int argc, char **argv)
{
	t_data	all;

	if (argc != 6)
		return (1);
	if (initualize(&all, argv) < 0)
		return (1);
	fill_table(&all, all.n_philo);
	printf("ok!%li",all.&all_ph->nb);
	return (0);
}