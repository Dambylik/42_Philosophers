/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:55:42 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 13:17:25 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philosophers(t_config *conf)
{
	int	i;

	i = 0;
	while (i < conf->n_philo)
	{
		conf->philos[i].id = i + 1;
		if (conf->philos[i].id % 2 == 0)
		{
			conf->philos[i].right_fork_id = i;
			conf->philos[i].left_fork_id = (i + 1) % conf->n_philo;
		}
		else
		{
			conf->philos[i].right_fork_id = (i + 1) % conf->n_philo;
			conf->philos[i].left_fork_id = i;
		}
		conf->philos[i].last_meal = 0;
		conf->philos[i].meal_count = 0;
		conf->philos[i].config = conf;
		conf->philos[i].hungry = 1;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_config *conf)
{
	int	i;

	i = 0;
	while (i < conf->n_philo)
	{
		if (pthread_mutex_init(&(conf->forks[i]), NULL))
			ft_putstr_fd("Mutex creation error!", 2);
		i++;
	}
	if (pthread_mutex_init(&(conf->printing), NULL))
		ft_putstr_fd("Mutex creation error!", 2);
	if (pthread_mutex_init(&(conf->health_check), NULL))
		ft_putstr_fd("Mutex creation error!", 2);
	return (0);
}

int	ft_init_dinner(t_config *conf, char **argv)
{
	conf->n_philo = ft_atoi(argv[1]);
	conf->time_to_die = ft_atoi(argv[2]);
	conf->time_to_eat = ft_atoi(argv[3]);
	conf->time_to_sleep = ft_atoi(argv[4]);
	conf->death_declaration = 0;
	conf->all_ate = 0;
	if (conf->n_philo < 1 || conf->n_philo > 200 || conf->time_to_die < 1
		|| conf->time_to_eat < 1 || conf->time_to_sleep < 1)
		ft_putstr_fd("Error! Non valid arguments.", 2);
	if (argv[5])
	{
		conf->total_meals = ft_atoi(argv[5]);
		if (conf->total_meals <= 0)
		{
			ft_putstr_fd("Error! They have to eat at least once.", 2);
			return (1);
		}
	}
	else
		conf->total_meals = -1;
	if (ft_init_mutex(conf))
		return (1);
	if (ft_init_philosophers(conf))
		return (1);
	return (0);
}
