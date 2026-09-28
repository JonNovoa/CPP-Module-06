/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:47:52 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/09/28 19:28:12 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.number = 42;
    data.letter = 'A';

    Data *original = &data;
    
    //Convierte el puntero en un numero
    uintptr_t raw = Serializer::serialize(original);
    //Convierte el numero a puntero
    Data *result = Serializer::deserialize(raw);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Result: " << result << std::endl;

    if (original == result)
        std::cout << "Pointers are equal: " << std::endl;
    else
        std::cout << "Original: " << original << std::endl;

    return 0;
}