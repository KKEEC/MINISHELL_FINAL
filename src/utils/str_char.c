/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by kkeec            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by kkeec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenizer.h"

int	ft_isalpha(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(const char c)
{
	if ((c >= '0' && c <= '9') || ft_isalpha(c))
		return (1);
	else
		return (0);
}
