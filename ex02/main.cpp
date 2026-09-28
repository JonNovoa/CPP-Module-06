/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:22:44 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/09/28 20:27:55 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // CAMBIA LA SEMILLA ALEATORIA
    std::srand(std::time(NULL));
    
    Base *p = generate();

    std::cout << "Pointer: ";
    identify(p);

    std::cout << "Reference: ";
    identify(*p);

    delete p;

    return 0;
}