/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:38:11 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/04 13:41:47 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H
#include<iostream>
#include<string>

template<typename T>
void	swap(T &a, T&b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	max(const T &a, const T &b)
{
	return (a>b ? a : b);
}

template<typename T>
T	min(const T &a, const T &b)
{
	return (a<b ? a : b);
}

#endif
