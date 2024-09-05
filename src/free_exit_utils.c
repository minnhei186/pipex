/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:52:45 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/04 14:18:09 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>


void	free_pipe_data(t_pipex *data)
{
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->in_command)
		free(data->in_command);
	if (data->out_command)
		free(data->out_command);
}

void	error_exit(char *message, int error_type, t_pipex *data)
{
	free_pipe_data(data);
	if (error_type == 0)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(STDERR_FILENO, message, ft_strlen(message));
		exit(EXIT_FAILURE);
	}
}

