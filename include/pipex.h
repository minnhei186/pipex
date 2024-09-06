/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:29:09 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/05 14:08:27 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**in_command;
	char	**out_command;
}			t_pipex;

// free_exit_utils
void		free_pipe_data(t_pipex *data);
void		error_exit(char *message, int error_type, t_pipex *data);

#endif
