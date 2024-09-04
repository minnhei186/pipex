/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:30:04 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 12:55:55 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_length(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	*loop16(char *str, int len, unsigned int n)
{
	while (len--)
	{
		if (n % 16 < 10)
		{
			str[len] = n % 16 + '0';
			n = n / 16;
		}
		else
		{
			str[len] = (n % 16 - 10) + 'A';
			n = n / 16;
		}
	}
	return (str);
}

int	ft_xx_output(va_list *args)
{
	char			*str;
	int				len;
	unsigned int	n;
	int				count;

	n = (va_arg(*args, unsigned int));
	len = get_num_length(n);
	count = len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);
	*(str + len) = '\0';
	ft_pf_putstr(loop16(str, len, n));
	free(str);
	return (count);
}

// int main(void)
// {
// 	unsigned int i;
// 	i=123;
// 	int count;

// 	count=printf("%X\n",i);
// 	printf("%X\n",count);
// 	count=ft_printf("%X\n",i);
// 	printf("%i\n",count);
// 	return (0);
// }

////マロックの問題は、マイナスを定数でとっていたために発生した。動的にその場合において作成すればこれらの問題は回避される。つまりdigitに計算を追加使用。
// int digit_re(int d)
//{
//	if(d==0)
//		return (0);
//	else
//		return (digit_re(d/10)+1);
//}
//
// int digit(int d)
//{
//	int len;
//	len=0;
//	if(d<=0)
//	{
//		len=1;
//		d=-d;
//	}
//	return (//		len=len+digit_re(d));
//}
//
//
////void d_output(va_list args)
////{
////	int d=(va_arg(args,int));
//
//
// void d_output(int num)
//{
//	int d=num;
//	int digit_num=digit(d)+1; //digit+terminating character
//	int sign;
//	char *str=(char *)calloc(digit_num,sizeof(char));
//	if(str==NULL)
//		free(str);
//
//
//	if(d==-2147483648)
//	{
//		ft_putstr("-2147483648");
//		free(str);
//		return ;
//	}
//	if(d<0)
//	{
//		sign=1;
//		d=-d;
//	}
//	digit_num=digit_num-2;
//	while(digit_num)
//	{
//		str[digit_num]=d%10+'0';
//		d=d/10;
//		digit_num--;
//	}
//	if(sign)
//		str[digit_num]='-';
//	else
//		str[digit_num]=d%10+'0';
//
//	ft_putstr(str);
//	free(str);
//}
//
