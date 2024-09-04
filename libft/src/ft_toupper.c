/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:35:19 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:35:11 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - ('a' - 'A');
		return (c);
	}
	else
		return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//    printf("%c\n", ft_toupper('a'));
//    printf("%c\n", ft_toupper('A'));
//    printf("%c\n", ft_toupper('!'));
//}
