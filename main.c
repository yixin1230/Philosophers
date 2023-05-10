/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 09:21:41 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/10 13:56:14 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	all;

	if (argc != 6)
		return (1);
	if (initualize(&all, argv) < 0)
		return (1);
	printf("ok!%li",all.time_to_die);
	return (0);
}