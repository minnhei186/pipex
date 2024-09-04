/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:57:38 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:35:33 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + ('a' - 'A');
		return (c);
	}
	else
		return (c);
}

//#include <ctype.h>
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%c\n", ft_tolower('a'));
//	printf("%c\n", ft_tolower('A'));
//	printf("%c\n", ft_tolower('!'));
//}
