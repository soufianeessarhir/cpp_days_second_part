/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:41:19 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/26 13:25:19 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
template <typename T>
typename T::iterator easyfind(T &container, int target)
{
	typename T::iterator  it = std::find(container.begin(),container.end(),target);
	if (it == container.end())
		throw std::runtime_error("value not found");
	return it;
}