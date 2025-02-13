/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:13:24 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/26 12:13:28 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_argv(char *arg)
{
	int		n;
	char	*tmp;

	n = ft_atoi(arg);
	tmp = ft_itoa(n);
	if (!tmp)
		return (0);
	if (ft_strcmp(arg, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error! Non valid number of arguments.", 2);
		return (1);
	}
	while (i < argc)
	{
		if (!ft_is_num(argv[i]))
		{
			ft_putstr_fd("Error! Non valid arguments.", 2);
			return (1);
		}
		if (!ft_check_argv(argv[i]))
		{
			ft_putstr_fd("Error! Value is out of range.", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
