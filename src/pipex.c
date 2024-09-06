/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:23 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/06 13:21:07 by hosokawa         ###   ########.fr       */
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
	data->infile = ft_strdup(argv[1]);
	if (!data->infile)
		error_exit("infile_malloc_error", 0, data);
	data->outfile = ft_strdup(argv[4]);
	if (!data->outfile)
		error_exit("outfile_malloc_error", 0, data);
	data->in_command = ft_split(argv[2], ' ');
	if (!data->in_command)
		error_exit("in_command_malloc_error", 0, data);
	data->out_command = ft_split(argv[3], ' ');
	if (!data->out_command)
		error_exit("out_command_malloc_error", 0, data);
	if (access(data->infile, F_OK) == -1)
		error_exit("in_file_cannot_access", 0, data);
	if (access(data->outfile, F_OK) == -1)
		error_exit("out_file_cannot_access", 0, data);
}


//リダイレクションとコマンドだけでは通信する必要もない、なぜならその情報はもういらないから、しかし処理して表した情報を別の処理に使いたいなら、パイプを必要とする。なるほどね。
void	command_do(t_pipex *data)
{
	int		pid;
	int		pipe_fd[2];
	char	str[1000];
	int filein_fd;
	int fileout_fd;

	filein_fd=open(data->infile,O_RDONLY);
	fileout_fd=open(data->outfile,O_WRONLY);
	ft_memset(str,'\0',1000);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(filein_fd, STDIN_FILENO);
		dup2(pipe_fd[1],STDOUT_FILENO);
		if (execvp(data->in_command[0], data->in_command) == -1)
			error_exit("execvp_error", 0, data);
	}
	else
	{
		wait(0);
		printf("now_parent\n");
		dup2(pipe_fd[0],STDIN_FILENO);
		dup2(fileout_fd,STDOUT_FILENO);
		if (execvp(data->out_command[0], data->out_command) == -1)
			error_exit("execvp_error", 0, data);
	}
	close(filein_fd);
}

int	main(int argc, char **argv)
{
	t_pipex	pipex_data;

	if (argc != 5)
		return (1);
	data_null_init(&pipex_data);
	data_init(&pipex_data, argv);
	command_do(&pipex_data);
	return (0);
}
