/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:55:38 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 14:02:13 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_health(t_config *philo)
{
	int	i;

	pthread_mutex_lock(&(philo->health_check));
	if (philo->all_ate || philo->death_declaration)
		i = 0;
	else
		i = 1;
	pthread_mutex_unlock(&(philo->health_check));
	return (i);
}

int	ft_check_vitals(t_config *conf, int i)
{
	pthread_mutex_lock(&(conf->health_check));
	if (ft_time_diff(ft_get_time(), conf->philos[i].last_meal)
		> (unsigned long)conf->time_to_die)
	{
		conf->death_declaration = 1;
		pthread_mutex_unlock(&(conf->health_check));
		ft_print_state(&(conf->philos[i]), conf, "\x1B[31m""died""\x1B[0m" );
		return (1);
	}
	else if (conf->total_meals > 0 && conf->philos[i].hungry == 1)
	{
		if (conf->philos[i].meal_count >= conf->total_meals)
		{
			conf->philos[i].hungry = 0;
			pthread_mutex_unlock(&(conf->health_check));
			return (2);
		}
		pthread_mutex_unlock(&(conf->health_check));
	}
	else
		pthread_mutex_unlock(&(conf->health_check));
	return (0);
}

void	ft_doctor(t_config *philosophers, int i, int vitals)
{
	int	all_philos;

	all_philos = 0;
	while (1)
	{
		i = 0;
		if (ft_check_health(philosophers) == 0)
			break ;
		while (i < philosophers->n_philo)
		{
			vitals = ft_check_vitals(philosophers, i);
			if (vitals == 1)
				break ;
			else if (vitals == 2)
				all_philos++;
			if (all_philos == philosophers->n_philo)
			{
				pthread_mutex_lock(&(philosophers->health_check));
				philosophers->all_ate = 1;
				pthread_mutex_unlock(&(philosophers->health_check));
			}
			i++;
		}
		usleep(100);
	}
}
