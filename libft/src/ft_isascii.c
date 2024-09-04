/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:31 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/05/30 13:52:37 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_isascii('a'));
//	printf("%d\n", ft_isascii('A'));
//	printf("%d\n", ft_isascii('1'));
//	printf("%d\n", ft_isascii('ｱ'));
//}
