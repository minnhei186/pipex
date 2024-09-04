/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:03:52 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:26:08 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//    int len;
//	int ft_len;
//    char s[] = "today";
//
//    len = strlen(s);
//	ft_len=ft_strlen(s);
//    printf("\"%s\" は %d 文字\n", s, len);
//    printf("\"%s\" は %d 文字\n", s, ft_len);
//    return (0);
//}
