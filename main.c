/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:55:57 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 12:41:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config	*conf;

	conf = malloc(sizeof(t_config) * 1);
	if (!conf)
	{
		ft_putstr_fd("Malloc error!", 2);
		return (0);
	}
	if (ft_check_args(argc, argv))
	{
		free(conf);
		return (0);
	}
	if (ft_init_dinner(conf, argv))
	{
		free(conf);
		return (0);
	}
	if (ft_start_dinner(conf))
		return (ft_destroy_mutexes(conf));
	return (1);
}
