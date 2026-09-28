/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:42:10 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/09/28 20:22:32 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    /* C++ necesitas al menos una función virtual en la clase base
    para que sea polimórfica y así poder usar dynamic_cast para
    identificar el tipo real del objeto. Tambien es para asegurar
    que al hacer delete de un puntero a Base, el objeto se destruya 
    correctamente sin fugas de memoria */
    virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif