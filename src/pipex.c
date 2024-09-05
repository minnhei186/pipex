/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:23 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/05 13:22:01 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	data_null_init(t_pipex *data)
{
	data->infile = NULL;
	data->outfile = NULL;
	data->in_command = NULL;
	data->out_command = NULL;
}

void	data_init(t_pipex *data, char **argv)
{
//	if (access(argv[1], F_OK) == -1)
//		error_exit("in_file_cannot_access", 0, data);
//	if (access(argv[4], F_OK) == -1)
//		error_exit("out_file_cannot_access", 0, data);
}

void	command_do(char **argv, t_pipex *data)
{
	if (execvp(argv[2], NULL) == -1)
		error_exit("execvp_error", 0, data);
}

int	main(int argc, char **argv)
{
	t_pipex	pipex_data;

	if (argc != 5)
		return (1);
	data_null_init(&pipex_data);
	data_init(&pipex_data, argv);
	command_do(argv,&pipex_data);
	return (0);
}
