/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:27:33 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/09/26 12:45:43 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <limits>
#include <cmath>
#include <iomanip>

static bool isChar(const std::string &literal)
{
    return (literal.length() == 3
        && literal[0] == '\''
        && literal[2] == '\'');
}

static bool isInt(const std::string &literal)
{
    size_t i = 0;

    if (literal.empty())
        return false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (i == literal.length())
        return false;

    while (i < literal.length())
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string &literal)
{
    // Si es infinito negativo, positivo o no es numero
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;

    std::string number = literal.substr(0, literal.length() - 1);

    char *end;
    // String to float
    std::strtof(number.c_str(), &end);

    /*
        *end == '\0' significa que strtof ha leido toda la cadena.
        number.find('.') comprueba que contiene un punto decimal.
    */
    return (*end == '\0' && number.find('.') != std::string::npos);
}

static bool isDouble(const std::string &literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    if (literal.empty())
        return false;

    char *end;
    std::strtod(literal.c_str(), &end);

    return (*end == '\0' && literal.find('.') != std::string::npos);
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::fixed << std::setprecision(1);

    if (isChar(literal))
    {
        char value = literal[1];

        std::cout << "char: '" << value << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    else if (isInt(literal))
    {
        int value = std::atoi(literal.c_str());

        if (value < 32 || value > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

        std::cout << "int: " << value << std::endl;
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    else if (isFloat(literal))
    {
        float value;

        /*
            Gestionamos los pseudo-literales especiales (nanf, +inff, -inff).
            Si no es uno de ellos, convertimos el string a float.
        */
        if (literal == "nanf")
            value = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            value = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            value = -std::numeric_limits<float>::infinity();
        else
            value = std::strtof(literal.c_str(), NULL);

        if (value < 32 || value > 126
            || std::isnan(value) || std::isinf(value))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

        if (std::isnan(value) || std::isinf(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;

        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    else if (isDouble(literal))
    {
        double value;

        /*
            Gestionamos los pseudo-literales especiales (nan, +inf, -inf).
            Si no es uno de ellos, convertimos el string a double.
        */
        if (literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::strtod(literal.c_str(), NULL);

        if (value < 32 || value > 126
            || std::isnan(value) || std::isinf(value))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

        if (std::isnan(value) || std::isinf(value))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(value) << std::endl;

        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}