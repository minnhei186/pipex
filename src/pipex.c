/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosokawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:23 by hosokawa          #+#    #+#             */
/*   Updated: 2024/09/09 17:52:51 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	data_null_init(t_pipex *data)
{
	data->infile = NULL;
	data->outfile = NULL;
	data->in_command = NULL;
	data->out_command = NULL;
	data->infile_fd = -1; // freeにおいて
	data->outfile_fd = -1;
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
}

void	get_file_fd(t_pipex *data)
{
	if (access(data->infile, F_OK) == -1)
		error_exit("in_file_cannot_access", 0, data);
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd == -1)
		error_exit("in_file_cannot_open", 0, data);
	if (access(data->outfile, F_OK) == -1)
		error_exit("out_file_cannot_access", 0, data);
	data->outfile_fd = open(data->outfile, O_WRONLY);
	if (data->outfile_fd == -1)
		error_exit("out_file_cannot_open", 0, data);
}

// exeに問題があるのではないようだ
// dupとpipeに問題がある可能性があるかもね。
// プロセスとpipeとdupについて,パイプとプロセスについて考え
// pipeの定義と静的か、どのようなものなんか、プロセスと、ファイルディスクーのコピーについて

//pipeをそのままに
void	exec_absorb_redirect(t_pipex *data, int *pipe_fd)
{
	int	pid;


	pid = fork();

	if (pid == 0)
	{
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		printf("wait\n");
		printf("%s %s \n", data->in_command[0], data->in_command[1]);
		exit(0);
		//if (execvp(data->in_command[0], data->in_command) == -1)
		//	error_exit("execvp_error", 0, data);
	}
	else
	{
		
		wait(0);
		printf("now_parent\n");
	}
}

void	exec_release_redirect(t_pipex *data, int *pipe_fd)
{
	if (fork() == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		if (execvp(data->out_command[0], data->out_command) == -1)
			error_exit("execvp_error", 0, data);
		exit(0);
	}
	wait(0);
	printf("now_parent\n");
}

void	command_do(t_pipex *data)
{
	int	pipe_fd[2];

	pipe(pipe_fd);
	exec_absorb_redirect(data, pipe_fd);
//	exec_release_redirect(data, pipe_fd);
	free_pipe_data(data);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	printf("finish\n");
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
