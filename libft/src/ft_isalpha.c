/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:13:50 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:20:28 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
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
//        if (isalpha(i)) {
//            printf("%c (%x)\n", i, i);
//		}
//		if(ft_isalpha(i)){
//			printf("%c (%x)\n",i,i);
//		}
//	}
