# Proyecto Final · Algoritmos 2026** · Entrega individual

- **Estudiante:** Axel Denilson Cuc Sopon
- **Carné:** 2790-26-29022
- **Curso:** Algoritmos
- 
HITOS:

[HITO 1 Algoritmos.pdf](https://github.com/user-attachments/files/34248922/HITO.1.Algoritmos.pdf)

[HITO 2 Algoritmos.pdf](https://github.com/user-attachments/files/34248924/HITO.2.Algoritmos.pdf)

[HITO 3 Algoritmos.pdf](https://github.com/user-attachments/files/34249081/HITO.3.Algoritmos.pdf)

VIDEO DEMOSTRATIVO:

https://docs.google.com/videos/d/1ctwNB6QoGhF3qvnBQg3Vmge7NSk8OTNHvRVTa3atmEQ/edit?usp=sharing


---

## 1. Descripción

Programa de consola en **C++** para atender la caja de una tienda de barrio. Se ha cumplido al pie de la letra lo indicado en el apartado de la tarea.

Está construido solo con lo visto en el curso: variables, tipos de dato, entrada/salida, validaciones, condicionales, ciclos y Git/GitHub.

## 2. Restricciones del proyecto

El programa **no usa** funciones propias (solo `main`), arreglos ni listas, archivos, clases ni recursión. Los datos del día se llevan con **variables acumuladoras**:

| Variable | Qué acumula |
|---|---|
| `CantidadVentas` | Contador de ventas realizadas |
| `TotalDia` | Suma del total cobrado en el día |
| `TotalDescuentos` | Suma de los descuentos otorgados |
| `VentaMayor` | Venta de mayor monto |
| `VentaMenor` | Venta de menor monto |

## 3. Funcionalidades

### A. Menú principal con ciclo

```
===== SISTEMA DE CAJA =====
1. Registrar venta
2. Ver resumen parcial del dia
3. Cerrar caja y salir
```

El menú se repite hasta que se elige la opción 3. Cualquier otra opción (letras, decimales, números fuera de rango) muestra un error y vuelve a pedir la opción.

### B. Registrar venta (ciclo dentro de ciclo)

Se piden los productos uno por uno hasta que el cajero escribe como  los datos y el *0* sirve para terminar el ciclo y pasar al siguiente apartado. Por cada producto se pide el precio unitario y la cantidad, y se acumula el subtotal de la venta. Si se termina sin productos, la venta se cancela y no se cuenta.

### C. Validaciones

El programa no se cae ante datos inválidos solo muestra un mensaje de error y pide de nuevo los datos

| Dato | Regla |
|---|---|
| Opción del menú | Entero válido: 1, 2 o 3 |
| Precio unitario | Número mayor a  0 ya que este sirve para finalizar|
| Cantidad | Entero entre 1 y 100, de igual manera el *0* finaliza el bloque|
| Monto recibido | Número que cubra el total a pagar |

### D. Cálculos con condicionales

Descuento según el subtotal de la venta:

| Subtotal | Descuento |
|---|---|
| Menor que Q100 | 0 % |
| Q100 a Q499.99 | 5 % |
| Q500 o más | 10 % |

Luego se calcula:

```
Descuento           = Subtotal × porcentaje
Monto con descuento = Subtotal − Descuento
IVA (12 %)          = Monto con descuento × 0.12
Total a pagar       = Monto con descuento + IVA
Cambio              = Monto recibido − Total a pagar
```

Los montos se redondean a centavos. Al final se muestra un **recibo** con subtotal, descuento, IVA, total, pago y cambio.

### E. Resumen del día

Muestra el número de ventas, total vendido, venta mayor, venta menor, promedio por venta y total de descuentos otorgados. Si todavía no hay ventas, muestra un mensaje en lugar de dividir entre cero.

## 4. Cómo ejecutarlo

**Requisitos:** Visual Studio con la carga de trabajo *Desarrollo para el escritorio con C++*.

1. Clona el repositorio.
2. Abre la solución en Visual Studio.
3. Selecciona el proyecto como elemento de inicio.
4. Presiona **Ctrl + F5** (ejecutar sin depurar).

## 5. Ejemplo de uso

```
===== SISTEMA DE CAJA =====
Elija una opcion: 1

--- Nueva venta ---
Ingrese precio unitario del producto (0 para terminar): 10
Ingrese la cantidad del producto (1 a 100, 0 para terminar): 2
Ingrese precio unitario del producto (0 para terminar): 5
Ingrese la cantidad del producto (1 a 100, 0 para terminar): 1
Ingrese precio unitario del producto (0 para terminar): 0

Total a pagar: Q. 28.00

Monto recibido: Q. 50

===== RECIBO =====
Subtotal: Q. 25.00
Descuento: Q. 0.00
IVA: Q. 3.00
Total a pagar: Q. 28.00
Monto recibido: Q. 50.00
Cambio: Q. 22.00
```

## 6. Casos de prueba durante la elaboracion del codigo 

| # | Entrada | Resultado esperado |
|---|---|---|
| 1 | Menú: `abc`, `1abc`, `1.5`, `7` | Error de opción inválida y vuelve a pedir |
| 2 | Precio `-5` | Error de precio negativo y vuelve a pedir |
| 3 | Precio `hola` | Error y vuelve a pedir el precio |
| 4 | Cantidad `101`, `-3`, `2.5`, `x` | Error y vuelve a pedir la cantidad |
| 5 | Precio `0` sin productos | "Venta cancelada", vuelve al menú |
| 6 | 10 × 2 y 5 × 1 | Subtotal 25.00, IVA 3.00, total 28.00 |
| 7 | Subtotal 99.99 | Descuento 0 % |
| 8 | Subtotal 100 | Descuento 5 %: total 106.40 |
| 9 | 300 × 1 | Descuento 15.00, IVA 34.20, total 319.20 |
| 10 | Subtotal 500 | Descuento 10 %: total 504.00 |
| 11 | Pago `20` con total 28.00 | Monto insuficiente, vuelve a pedir |
| 12 | Pago `28` con total 28.00 | Cambio 0.00 |
| 13 | Pago `abc` | Error y vuelve a pedir el pago |
| 14 | Tres ventas (28.00, 319.20, 106.40) y opción 2 | 3 ventas, total 453.60, mayor 319.20, menor 28.00, promedio 151.20, descuentos 20.00 |
| 15 | Opción 2 o 3 sin ventas | "No se han registrado ventas", sin dividir entre cero |


## 7. Estructura del repositorio

```
Proyecto-de-Algoritmos
├── .gitignore
├── LICENSE
├── README.md
└── (proyecto de Visual Studio con el archivo .cpp del sistema de caja)
```

## 8. Uso de IA

**Herramienta utilizada:** Claude (Anthropic), mediante chat web.

### Para qué la usé

- Entender la estructura del programa: menú con `do...while` y `switch`, y ciclos anidados.
- Revisar mi código y encontrar errores. Por ejemplo: un `break` faltante en el `case 1`, una lectura `cin` sobrante que alteraba el subtotal, una bandera asignada a la variable equivocada y ciclos infinitos al escribir letras.
- Aprender a validar entradas con `cin.fail()`, `cin.clear()`, `cin.ignore()` y `cin.peek()`.
- Elaborar esqueletos para trabajar a partir de ello y la tabla de casos de prueba.

### Qué recibí de la IA

La IA me guio paso a paso y me mostró esqueletos con partes vacías para completar. **Luego me entregó, versiones completas de los mismos para comparar con la mía**, y la versión final (pago, recibo y resumen del día) fue generado el esqueleto por parte de la IA a partir de mi código y de las correcciones que fuimos haciendo.

### Qué hice yo

- Escribí mis propias versiones del programa y las usé como base de cada revisión.
- Ejecuté el programa, detecté fallas al probarlo (por ejemplo, el ciclo infinito al escribir letras y el comportamiento del 0 al ingresar la cantidad) y las reporté.
- Tomé decisiones sobre nombres de variables, formato de los mensajes y comportamiento del programa.
- Probé el programa con los casos de la sección 6.
- Hice los commits y la unión de la rama de trabajo con `main` en GitHub.
- Entregue mis lineas de codigo a la IA para su respectiva revision.

### Qué no hizo la IA

No ejecutó ni probó el programa por mí, y no subió nada al repositorio.

### Verificación

Comprobé los resultados con los casos de pruebas indicadas en la parte del Hito 3 y confirmé que el programa cumple los requisitos desde inciso A hasta el inciso E y las restricciones del proyecto (sin funciones propias, arreglos, archivos, clases ni recursión).

### Declaración

Se adjuntaran las pruebas sobre uso de IA para Hito 2 y el la creacion del repo desde terminal, y creacion y avances pertenecientes a Hito 1.
