/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:02:24 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 13:06:02 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    
    public:
        Array();      
        Array(unsigned int n);   
        Array(const Array& other);    
        Array& operator=(const Array& other); 
        ~Array();        
    
        T& operator[](unsigned int index);         
        const T& operator[](unsigned int index) const; 
    
        unsigned int size() const;   
};

#include "Array.tpp"

#endif