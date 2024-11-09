/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:15 by frocha            #+#    #+#             */
/*   Updated: 2024/11/08 16:29:17 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char *infile_path, int *fd)
{
	int	fd_infile;

	handle_infile_opening(infile_path, &fd_infile);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
	{
		perror("Error duplicating input file descriptor in first child");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error duplicating pipe write end in first child");
		exit(EXIT_FAILURE);
	}
	close(fd_infile);
	close(fd[0]);
	close(fd[1]);
}

void	second_child(char *outfile_path, int *fd)
{
	int	fd_outfile;

	handle_outfile_opening(outfile_path, &fd_outfile);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Error duplicating pipe read in second child");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("Error duplicating output file in second child");
		exit(EXIT_FAILURE);
	}
	close(fd_outfile);
	close(fd[0]);
	close(fd[1]);
}
