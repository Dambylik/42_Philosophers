/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:56:14 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 13:49:53 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_state(t_philo *philo, t_config *conf, char *state)
{
	pthread_mutex_lock(&(conf->printing));
	if (ft_check_health(conf) == 0 && state[8] != 'd')
	{
		pthread_mutex_unlock(&(conf->printing));
		return ;
	}
	printf("%ld %d %s\n", ft_time_diff(ft_get_time(),
			conf->start), philo->id, state);
	pthread_mutex_unlock(&(conf->printing));
}
