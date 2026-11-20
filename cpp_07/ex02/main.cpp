/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:02:55 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 13:27:23 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#pragma GCC diagnostic ignored "-Wself-assign-overloaded"

int main()
{
    std::cout << "\n -------Array ex02-------- \n\n";
    try
    {
        std::cout << "\n-----Test default constructor:-----\n\n";
        Array<int> emptyArray;
        std::cout << "Size of emptyArray: " << emptyArray.size() << "\n";
        try
        {
            emptyArray[0] = 10;
        } catch (const std::exception& e) 
        {
            std::cerr << "Caught exception on emptyArray access: " << e.what() << "\n\n";
        }

        std::cout << "---------Test with integers:----------\n\n";
        Array<int> a(3);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;

        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << "a[" << i << "] = " << a[i] << "\n";

        std::cout << "\n -----Test with std::string: ------\n\n";
        Array<std::string> b(2);
        b[0] = "hello";
        b[1] = "world";

        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << "\n";

        std::cout << "\n----Testing copy constructor:-----\n\n";
        Array<std::string> c(b);
        std::cout << "b[0] = " << b[0] << " expected: 'hello'\n";
        std::cout << "c[0] = " << c[0] << " exepected:  'hello'\n";
        std::cout << "changing c[0] to 'gooddbye'\n";
        c[0] = "goodbye";
        std::cout << "b[0] = " << b[0] << " expected: 'hello'\n";
        std::cout << "c[0] = " << c[0] << " exepected:  'goodbye'\n";

        std::cout << "\n----Testing out-of-bounds:----\n\n";
        std::cout << a[3] << "\n"; // should throw

    } catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n-------Test self-assignment:------\n\n";
    Array<int> arr(2);
    arr[0] = 5;
    arr[1] = 10;
    std::cout << "before self alignement\n";
    std::cout << "arr[0]: " << arr[0] << ", arr[1]: " << arr[1] << "\n";
    arr = arr;
    std::cout << "after self alignement\n";
    std::cout << "arr[0]: " << arr[0] << ", arr[1]: " << arr[1] << "\n";

    std::cout << "\n----Test large array creation (1000 ints):-----\n\n";
    Array<int> bigArray(1000);
    bigArray[999] = 42;
    std::cout << "Last element: " << bigArray[999] << "\n";

    std::cout << "\n-----Test multiple levels of copy:-----\n\n";
    std::cout << "Creating array d\n";
    Array<std::string> d(2);
    d[0] = "copy1";
    d[1] = "copy2";
    std::cout << "d[0]: " << d[0] << " expected: copy1\n";
    std::cout << "d[1]: " << d[1] << " expected: copy2\n";
    std::cout << "copying d in e\n";
    Array<std::string> e(d);
    std::cout << "copying e in f\n";
    Array<std::string> f(e);
    std::cout << "d[0]: " << d[0] << " expected: copy1\n";
    std::cout << "d[1]: " << d[1] << " expected: copy2\n";
    std::cout << "f[0]: " << f[0] << " expected: copy1\n";
    std::cout << "f[1]: " << f[1] << " expected: copy2\n";
    f[0] = "modified";
    std::cout << "d[0]: " << d[0] << " expected: copy1\n";
    std::cout << "d[1]: " << d[1] << " expected: copy2\n";
    std::cout << "f[0]: " << f[0] << " expected: modified\n";
    std::cout << "f[1]: " << f[1] << " expected: copy2\n";
    return 0;
}
#pragma GCC diagnostic pop