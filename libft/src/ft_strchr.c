/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:09:32 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/10 15:33:20 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	char			*tmp;

	ch = (unsigned char)c;
	tmp = (char *)s;
	while (*tmp != '\0')
	{
		if (*tmp == ch)
			return (tmp);
		tmp++;
	}
	if (*tmp == ch)
		return (tmp);
	return (0);
}
//#include <string.h>
//#include <stdio.h>
//
//int main(void)
//{
//	char str[] = "abc", *p;
//	int c;
//
//	printf("検索文字を入力してください。");
//	c = getchar();
//
//	p = ft_strchr(str, c);
//	if (p != NULL) {
//		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
//		printf("以降の文字列は%sです。\n", p);
//	}
//	else
//		printf("%cは見つかりませんでした\n", c);
//
//	return (0);
//}
