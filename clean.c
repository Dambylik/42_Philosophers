/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:55:33 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/25 16:56:25 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_destroy_mutexes(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->n_philo)
	{
		if (!&(config->forks[i]))
			pthread_mutex_destroy(&(config->forks[i]));
		i++;
	}
	if (&(config->printing.__data))
		pthread_mutex_destroy(&(config->printing));
	if (&(config->health_check.__data))
		pthread_mutex_destroy(&(config->health_check));
	if (config)
		free(config);
	return (0);
}
