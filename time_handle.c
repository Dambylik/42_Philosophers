/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:56:19 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 12:05:13 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_time_diff(unsigned long a, unsigned long b)
{
	return (a - b);
}

unsigned long	ft_get_time(void)
{
	struct timeval	time;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&time, NULL);
	s = time.tv_sec;
	u = time.tv_usec;
	return (s * 1000 + u / 1000);
}

void	ft_usleep(unsigned long ms)
{
	unsigned long	time;

	time = ft_get_time();
	while (ft_time_diff(ft_get_time(), time) < ms)
		usleep(100);
}
