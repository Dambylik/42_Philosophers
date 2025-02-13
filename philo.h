/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:02:40 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 13:39:01 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	unsigned long	last_meal;
	int				meal_count;
	int				hungry;
	pthread_t		thread;
	struct s_config	*config;
}	t_philo;

typedef struct s_config
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	int				death_declaration;
	int				all_ate;
	unsigned long	start;
	pthread_t		thread;
	struct s_philo	philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	printing;
	pthread_mutex_t	health_check;
}	t_config;

int				ft_destroy_mutexes(t_config *conf);
int				ft_check_vitals(t_config *philo, int i);
int				ft_check_health(t_config *philos);
int				ft_start_dinner(t_config *conf);
void			ft_print_state(t_philo *philo, t_config *conf, char *state);
void			*ft_routine(void *void_philo);
void			*ft_philo_alone(t_config *conf, t_philo *philo);
void			ft_doctor(t_config *philosophers, int i, int vitals);
int				ft_check_args(int ac, char **av);
int				ft_check_argv(char *arg);
int				ft_init_dinner(t_config *conf, char **av);
int				ft_init_mutex(t_config *conf);
int				ft_init_philosophers(t_config *conf);
void			ft_usleep(unsigned long ms);
unsigned long	ft_get_time(void);
unsigned long	ft_time_diff(unsigned long a, unsigned long b);
int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_is_num(char *arg);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putstr_fd(char *s, int fd);

#endif
