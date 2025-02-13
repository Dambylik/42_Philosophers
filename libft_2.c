/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:55:52 by okapshai          #+#    #+#             */
/*   Updated: 2024/09/25 17:03:03 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_if_neg(long int num, int cpt)
{
	char	*r;

	r = (char *) ft_calloc(cpt + 2, sizeof(char));
	if (!r)
		return (0);
	while (num != 0)
	{
		r[cpt] = num % 10 + '0';
		num = num / 10;
		cpt--;
	}
	r[0] = '-';
	return (r);
}

static char	*ft_manage_pos(long int num, int cpt)
{
	char	*r;

	r = (char *) ft_calloc(cpt + 1, sizeof(char));
	if (!r)
		return (0);
	while (num != 0)
	{
		r[cpt - 1] = num % 10 + '0';
		num = num / 10;
		cpt--;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	char			*r;
	int				cpt;
	long int		num;

	num = n;
	cpt = 0;
	while (n != 0)
	{
		n /= 10;
		cpt++;
	}
	if (num == 0)
	{
		r = (char *) ft_calloc(2, sizeof(char));
		r[0] = '0';
		return (r);
	}
	if (num < 0)
		return (ft_if_neg(num * -1, cpt));
	else
		return (ft_manage_pos(num, cpt));
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 0)
		write(fd, s, i);
	write(fd, "\n", 1);
}
