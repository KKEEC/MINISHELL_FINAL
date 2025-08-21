/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by kkeec            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by kkeec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/tokenizer.h"
#include "../../includes/env.h"

t_token	*tokenize(const char *input, t_env *env_list, int *status)
{
	t_token			*tokens;
	size_t			i;
	char			*acc;
	t_tokenize_ctx	ctx;

	tokens = NULL;
	i = 0;
	acc = NULL;
	if (!input)
		return (NULL);
	ctx.input = input;
	ctx.i = &i;
	ctx.acc = &acc;
	ctx.tokens = &tokens;
	ctx.env_list = env_list;
	ctx.status = status;
	tokenize_loop(&ctx);
	return (finalize_tokenization(&ctx));
}
