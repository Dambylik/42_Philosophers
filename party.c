/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:56:09 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:38 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_alone(t_config *conf, t_philo *philo)
{
	pthread_mutex_lock(&(conf->forks[philo->right_fork_id]));
	ft_print_state(philo, conf, "\x1B[33m""has taken a fork""\x1B[0m");
	pthread_mutex_unlock(&(conf->forks[philo->right_fork_id]));
	return (0);
}

static void	ft_run_loop(t_config *conf, t_philo *philo)
{
	while (1)
	{
		if (ft_check_health(conf) == 0)
			break ;
		pthread_mutex_lock(&(conf->forks[philo->right_fork_id]));
		ft_print_state(philo, conf, "\x1B[33m""has taken a fork""\x1B[0m");
		pthread_mutex_lock(&(conf->forks[philo->left_fork_id]));
		ft_print_state(philo, conf, "\x1B[33m""has taken a fork""\x1B[0m");
		pthread_mutex_lock(&(conf->health_check));
		philo->last_meal = ft_get_time();
		philo->meal_count++;
		pthread_mutex_unlock(&(conf->health_check));
		ft_print_state(philo, conf, "\x1B[32m""is eating""\x1B[0m");
		ft_usleep(conf->time_to_eat);
		pthread_mutex_unlock(&(conf->forks[philo->right_fork_id]));
		pthread_mutex_unlock(&(conf->forks[philo->left_fork_id]));
		ft_print_state(philo, conf, "\x1B[34m""is sleeping""\x1B[0m");
		ft_usleep(conf->time_to_sleep);
		ft_print_state(philo, conf, "\x1B[35m""is thinking""\x1B[0m");
		usleep(200);
	}
}

void	*ft_routine(void *philosopher)
{
	t_philo		*philo;
	t_config	*conf;

	philo = (t_philo *)philosopher;
	conf = philo->config;
	if (conf->n_philo == 1)
		return (ft_philo_alone(conf, philo));
	if (philo->id % 2 == 0)
		ft_usleep(conf->time_to_eat);
	ft_run_loop(conf, philo);
	return (0);
}

int	ft_start_dinner(t_config *conf)
{
	int				i;

	i = 0;
	conf->start = ft_get_time();
	while (i < conf->n_philo)
	{
		if (pthread_create(&(conf->philos[i].thread), NULL,
				ft_routine, &(conf->philos[i])))
			ft_putstr_fd("Thread creation error!", 2);
		pthread_mutex_lock(&(conf->health_check));
		conf->philos[i].last_meal = ft_get_time();
		pthread_mutex_unlock(&(conf->health_check));
		i++;
	}
	ft_doctor(conf, 0, 0);
	i = 0;
	while (i < conf->n_philo)
	{
		pthread_join(conf->philos[i].thread, NULL);
		i++;
	}
	ft_destroy_mutexes(conf);
	return (0);
}
