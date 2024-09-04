/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:48:26 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/05/29 18:51:37 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//#include <ctype.h>
//#include <limits.h>
//
//int main(void)
//{
//    for (int i = 0; i < UCHAR_MAX; ++i) {
//        if (isdigit(i)) {
//            printf("%c (%x)\n", i, i);
//        }
//		if(ft_isdigit(i)){
//				printf("%c (%x)\n", i, i);
//		}
//    }
//}
