/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:42:42 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/24 13:09:45 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int main()
{
    std::cout << "\n-----Mutant ex02-----\n\n" << std::endl;
    std::cout << "Creating and using MutantStack:\n\n";

    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    // Iterate over the stack
    std::cout << "MutantStack elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Const iterator usage
    const MutantStack<int> cstack = mstack;
    std::cout << "Const MutantStack elements: ";
    for (MutantStack<int>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Stack operations
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "After pop, top element: " << mstack.top() << std::endl;

    std::cout << "\n\nCreating and using list:\n\n";
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    std::cout << "List elements: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const std::list<int> clst = lst;
    std::cout << "Const list elements: ";
    for (std::list<int>::const_iterator it = clst.begin(); it != clst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Back element: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "After pop_back, new back element: " << lst.back() << std::endl;

    return 0;
}
