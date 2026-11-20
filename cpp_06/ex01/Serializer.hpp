/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:32:12 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/09 12:07:40 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdint.h>


struct Data
{
	unsigned int		age;
    unsigned int		height;
	std::string	        wish;
	long			    moneyCount;
};

class Serializer
{
	private:

		Serializer(void);
		~Serializer(void);
        Serializer &operator=(const Serializer &rhs);
        Serializer(Serializer const &copy);
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif