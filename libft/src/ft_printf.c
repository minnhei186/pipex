/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:56:40 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 12:54:51 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	output_state(va_list *args, char specifier)
{
	if (specifier == 'c')
		return (ft_c_output(args));
	if (specifier == 's')
		return (ft_s_output(args));
	if (specifier == 'p')
		return (ft_p_output(args));
	if (specifier == 'd')
		return (ft_d_output(args));
	if (specifier == 'i')
		return (ft_i_output(args));
	if (specifier == 'u')
		return (ft_u_output(args));
	if (specifier == 'x')
		return (ft_x_output(args));
	if (specifier == 'X')
		return (ft_xx_output(args));
	if (specifier == '%')
		return (ft_percent_output());
	return (-1);
}

static int	analysis_state(const char **format_p, va_list *args)
{
	int	count;
	int	written_len;

	if (**format_p == '%')
	{
		(*format_p)++;
		written_len = output_state(args, **format_p);
		if (written_len == -1)
			return (-1);
		else
			count = written_len;
	}
	else
	{
		ft_pf_putchar(**format_p);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;
	int		count;

	total_count = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		count = analysis_state(&format, &args);
		if (count == -1)
			return (-1);
		total_count = total_count + count;
		format++;
	}
	va_end(args);
	return (total_count);
}

// int main()
// {
// 	int  d;
// 	d=10;

// 	ft_printf("%i\n",d);
// 	printf("d decimal=%d",d);
// 	printf("i integer=%i",d);
// 	return (0);
// }
