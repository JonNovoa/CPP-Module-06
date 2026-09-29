# CPP06 - C++ Casts

## Objetivo

El objetivo de CPP06 es aprender a realizar conversiones entre diferentes tipos utilizando los distintos operadores de cast de C++.

En cada ejercicio se utiliza un tipo de cast diferente:

```text
ex00 → static_cast
ex01 → reinterpret_cast
ex02 → dynamic_cast
```

---

# ex00 - Scalar conversion

## Objetivo

Crear una clase `ScalarConverter` capaz de recibir una representación textual de un literal y convertirla a:

* `char`
* `int`
* `float`
* `double`

La clase utiliza un único método estático:

```cpp
static void convert(const std::string &literal);
```

## Tipos

El programa reconoce literales como:

```text
'A'
42
42.0f
42.0
```

También reconoce los pseudo-literales:

```text
nan
nanf
+inf
-inf
+inff
-inff
```

## Cast utilizado

En este ejercicio se utiliza:

```cpp
static_cast
```

Por ejemplo:

```cpp
static_cast<int>(value)
static_cast<float>(value)
static_cast<double>(value)
static_cast<char>(value)
```

`static_cast` se utiliza para realizar conversiones entre tipos compatibles de forma explícita.

## Ejemplo

```bash
./convert 42.0f
```

Resultado:

```text
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

# ex01 - Serialization

## Objetivo

Convertir un puntero `Data*` en un número entero capaz de almacenar una dirección y volver a convertir ese número en el puntero original.

Se implementan:

```cpp
static uintptr_t serialize(Data *ptr);
static Data *deserialize(uintptr_t raw);
```

## Funcionamiento

Primero tenemos un objeto:

```cpp
Data data;
```

Obtenemos su dirección:

```cpp
Data *original = &data;
```

Después convertimos el puntero en un número:

```cpp
uintptr_t raw = Serializer::serialize(original);
```

Y finalmente volvemos a convertirlo en un puntero:

```cpp
Data *result = Serializer::deserialize(raw);
```

El resultado debe apuntar al mismo objeto:

```cpp
original == result
```

## Cast utilizado

En este ejercicio se utiliza:

```cpp
reinterpret_cast
```

Para convertir el puntero:

```cpp
return reinterpret_cast<uintptr_t>(ptr);
```

Y para recuperarlo:

```cpp
return reinterpret_cast<Data *>(raw);
```

`reinterpret_cast` permite reinterpretar una representación de memoria como otro tipo.

---

# ex02 - Identify real type

## Objetivo

Crear una clase base `Base` y tres clases derivadas:

```text
Base
├── A
├── B
└── C
```

El programa crea aleatoriamente un objeto `A`, `B` o `C` y después identifica su tipo real.

Se implementan:

```cpp
Base *generate(void);

void identify(Base *p);

void identify(Base &p);
```

## Generación

`generate()` utiliza:

```cpp
std::rand() % 3
```

para obtener un valor entre `0` y `2`:

```text
0 → A
1 → B
2 → C
```

Se utiliza `std::srand(std::time(NULL))` en `main()` para cambiar la semilla del generador entre ejecuciones.

## Cast utilizado

En este ejercicio se utiliza:

```cpp
dynamic_cast
```

### Con puntero

```cpp
dynamic_cast<A *>(p)
```

Si el objeto es `A`, devuelve un puntero válido.

Si no es `A`, devuelve `NULL`.

### Con referencia

```cpp
dynamic_cast<A &>(p)
```

Si el objeto es `A`, el cast funciona.

Si no es `A`, lanza una excepción.

Por eso se utiliza `try/catch`.

## Ejemplo

```text
Pointer: B
Reference: B
```

Las dos funciones identifican el mismo objeto utilizando las dos formas de `dynamic_cast`.

---

# Casts utilizados en CPP06

| Ejercicio | Cast               | Uso                                    |
| --------- | ------------------ | -------------------------------------- |
| ex00      | `static_cast`      | Conversión entre tipos escalares       |
| ex01      | `reinterpret_cast` | Conversión entre puntero y `uintptr_t` |
| ex02      | `dynamic_cast`     | Identificar el tipo real de un objeto  |

---

# Compilación

Cada ejercicio dispone de su propio `Makefile`.

Por ejemplo:

```bash
cd ex00
make
```

```bash
cd ../ex01
make
```

```bash
cd ../ex02
make
```

Los proyectos se compilan utilizando C++98:

```text
-Wall -Wextra -Werror -std=c++98
```

---

# Estructura

```text
CPP06/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── ScalarConverter.cpp
│   └── ScalarConverter.hpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Data.hpp
│   ├── Serializer.cpp
│   └── Serializer.hpp
│
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── Base.cpp
    ├── Base.hpp
    ├── A.hpp
    ├── B.hpp
    └── C.hpp
```

# Resumen

CPP06 trabaja principalmente tres formas de conversión:

```text
static_cast
     ↓
conversiones normales entre tipos

reinterpret_cast
     ↓
reinterpretación de una dirección/memoria

dynamic_cast
     ↓
comprobación del tipo real de un objeto
```
