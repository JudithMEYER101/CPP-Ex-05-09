/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:47:54 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/04 13:50:00 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_H
# define ITER_H

#include<iostream>
#include<string>

template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif