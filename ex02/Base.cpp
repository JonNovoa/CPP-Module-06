/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:59:10 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/09/28 20:20:58 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base::~Base()
{
}

//Genera una clase Aleatoriamente
Base *generate(void)
{
    int random = std::rand() % 3;

    if(random == 0)
        return new A;
    else if(random == 1)
        return new B;
    else
        return new C;
}

// IDENTIFICA EL TIPO REAL DEL PUNTERO
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }

    try
    {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }

    try
    {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e)
    {
    }
}