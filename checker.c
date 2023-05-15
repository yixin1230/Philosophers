/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:20:54 by yizhang       #+#    #+#                 */
/*   Updated: 2023/05/15 17:28:40 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	
	if (argc != 6)
		return (-1);
	while (i < 6)
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