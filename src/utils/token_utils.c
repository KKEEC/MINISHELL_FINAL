/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:00:00 by kkeec             #+#    #+#             */
/*   Updated: 2025/08/25 10:00:00 by kkeec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"
#include "../../includes/utils.h"

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
