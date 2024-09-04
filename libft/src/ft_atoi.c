/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:03:06 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 17:54:06 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	digits_process(const char *str, int sign, long long res)
{
	while (ft_isdigit(*str))
	{
		if (res > ((LONG_MAX - (*str - '0')) / 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return ((int)digits_process(str, sign, res) * sign);
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int	main(void)
//{
//	char	*str;
//
//	str = "9223372036854775808";
//	printf("atoi:%d\n", atoi(str));
//	printf("ft_atoi:%d\n", ft_atoi(str));
//	return (0);
//}
