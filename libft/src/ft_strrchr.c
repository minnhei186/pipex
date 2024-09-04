/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:17:38 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 16:04:03 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp;
	int				n;
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	tmp = (char *)s;
	n = ft_strlen(tmp) + 1;
	i = 0;
	tmp = tmp + (n - 1);
	while (i < n)
	{
		if (*tmp == ch)
			return (tmp);
		i++;
		tmp--;
	}
	return (0);
}

//#include <string.h>
//#include <stdio.h>
//
//int main(void)
//{
//	char str[] = "abcdefghijklmnabcdefghijklmn", *p;
//	int c;
//
//	printf("検索文字を入力してください。");
//	c = getchar();
//
//	p = ft_strrchr(str, c);
//	if (p != NULL) {
//		printf("%cは文字列の%ld番目にあります。\n", c, p-str);
//		printf("以降の文字列は%sです。\n", p);
//	}
//	else
//		printf("%cは見つかりませんでした\n", c);
//
//	return (0);
//}
