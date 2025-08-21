/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:00:00 by kkeec             #+#    #+#             */
/*   Updated: 2025/08/21 10:00:00 by kkeec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"
#include "../../../includes/utils.h"
#include <unistd.h>

int	is_operator(t_token_type type)
{
	if (type == TOKEN_PIPE
		|| type == TOKEN_REDIR_IN
		|| type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND
		|| type == TOKEN_HEREDOC)
		return (1);
	return (0);
}

void	write_pipe_in_error(t_token *token)
{
	if (token->next->next && token->next->next->type == TOKEN_PIPE)
		write(STDERR_FILENO, " syntax error near unexpected token `|'\n",
			39);
	else
		write(STDERR_FILENO, " syntax error near unexpected token `<'\n",
			39);
}

void	write_token_error(t_token *token)
{
	if (token->next->value)
	{
		write(STDERR_FILENO, " syntax error near unexpected token ", 36);
		write(STDERR_FILENO, "`", 1);
		write(STDERR_FILENO, token->next->value,
			ft_strlen(token->next->value));
		write(STDERR_FILENO, "'\n", 2);
	}
	else
		write(STDERR_FILENO, " syntax error near unexpected token `newline'\n",
			45);
}

int	handle_pipe_redir_error(t_token *token)
{
	t_token	*check;

	if (token->type == TOKEN_PIPE && (token->next->type == TOKEN_REDIR_OUT
			|| token->next->type == TOKEN_APPEND))
	{
		check = token->next->next;
		if (check && check->type == TOKEN_WORD)
			return (0);
		if (token->next->type == TOKEN_APPEND)
			write(STDERR_FILENO, " syntax error near unexpected token `>>'\n",
				40);
		else
			write(STDERR_FILENO,
				" syntax error near unexpected token `newline'\n", 45);
		return (1);
	}
	return (-1);
}
