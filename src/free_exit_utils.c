/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:52:45 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/11 12:58:58 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex_double_free(char **ppt)
{
	int	i;

	i = 0;
	while (ppt[i])
	{
		free(ppt[i]);
		i++;
	}
	free(ppt);
}

void	free_pipe_data(t_pipex *data)
{
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->in_command)
		pipex_double_free(data->in_command);
	if (data->out_command)
		pipex_double_free(data->out_command);
}

void	close_fd_data(t_pipex *data)
{
	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
}

void	error_exit(char *message, int error_type, t_pipex *data)
{
	free_pipe_data(data);
	close_fd_data(data);
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
