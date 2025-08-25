/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 00:00:00 by kkeec            #+#    #+#             */
/*   Updated: 2025/08/18 00:00:00 by kkeec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"
#include <stdio.h>  // for printf

int	execute_heredoc(t_ast *ast, t_env **env_list)
{
	if (!ast || !env_list)
		return (1);
	(void)ast;
	(void)env_list;
	printf("Neeed to handle heredoc\n");
	return (0);
}
