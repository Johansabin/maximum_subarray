# Máximo Subarreglo: Cúbica, Cuadrática y Kadane

Laboratorio de **Análisis y Diseño de Algoritmos — UNSA**

Implementación y comparación experimental de tres soluciones al problema del **máximo subarreglo**:

* Algoritmo cúbico — `Θ(n³)`
* Algoritmo cuadrático — `Θ(n²)`
* Algoritmo de Kadane — `Θ(n)`

El objetivo es verificar experimentalmente sus órdenes de crecimiento mediante mediciones de tiempo y analizar qué tan rápido dejan de ser viables al aumentar el tamaño de la entrada.

---

## 1. Lenguaje y equipo de medición

| Característica    | Especificación                  |
| ----------------- | ------------------------------- |
| Lenguaje          | C++                             |
| Compilador        | `g++`                           |
| Optimización      | `-O2`                           |
| Procesador        | Intel Core i5-12450H (12th Gen) |
| Núcleos / hilos   | 8 núcleos / 12 hilos            |
| Frecuencia máxima | 4.4 GHz                         |
| Memoria RAM       | 16 GB                           |
| Sistema operativo | Linux Mint 22.3 Cinnamon        |

Compilación utilizada:

```bash
g++ -O2 max_subarray.cpp -o max_subarray
```

Ejecución:

```bash
./max_subarray
```

---

## 2. Implementación y verificación

Se implementaron las tres soluciones al problema del máximo subarreglo:

1. **Solución cúbica:** `Θ(n³)`
2. **Solución cuadrática:** `Θ(n²)`
3. **Algoritmo de Kadane:** `Θ(n)`

Las tres deben devolver la misma suma máxima.

Para verificar la implementación, se generaron **100 arreglos pequeños aleatorios**, con tamaños entre 1 y 50 y valores enteros entre `-100` y `100`.

Resultado:

```text
100/100 pruebas coinciden
```

Esto confirma que las tres implementaciones producen la misma suma máxima en las pruebas realizadas.

---

## 3. Medición experimental

Se duplicó el tamaño de entrada comenzando desde `n = 1000`:

```text
1000, 2000, 4000, 8000, 16000, ...
```

Los tiempos corresponden a milisegundos.

### Resultados

```text
n | cubica(ms) | cuadratica(ms) | kadane(ms)
------------------------------------------------
1000 | 43.246 | 0.260 | 0.001
2000 | 301.065 | 0.973 | 0.002
4000 | 2426.301 | 3.708 | 0.004
8000 | 19757.081 | 15.072 | 0.008
16000 | N/A | 60.325 | 0.015
32000 | N/A | 250.180 | 0.026
64000 | N/A | 966.142 | 0.061
128000 | N/A | 3870.427 | 0.109
256000 | N/A | 15201.135 | 0.241
512000 | N/A | N/A | 0.402
1024000 | N/A | N/A | 0.813
2048000 | N/A | N/A | 1.637
4096000 | N/A | N/A | 3.227
8192000 | N/A | N/A | 6.558
16384000 | N/A | N/A | 13.019
32768000 | N/A | N/A | 26.191
65536000 | N/A | N/A | 51.971
100000000 | N/A | N/A | 79.690
```

### Salida del programa

La ejecución completa utilizada para las mediciones fue:

```text
camaleonxdd ~/D/ada λ g++ -O2 max_subarray.cpp -o max_subarray

camaleonxdd ~/D/ada λ ./max_subarray

100/100 pruebas coinciden

n | cubica(ms) | cuadratica(ms)| kadane(ms)

1000 | 43.246 | 0.260 | 0.001
2000 | 301.065 | 0.973 | 0.002
4000 | 2426.301 | 3.708 | 0.004
8000 | 19757.081 | 15.072 | 0.008
16000 | N/A | 60.325 | 0.015
32000 | N/A | 250.180 | 0.026
64000 | N/A | 966.142 | 0.061
128000 | N/A | 3870.427 | 0.109
256000 | N/A | 15201.135 | 0.241
512000 | N/A | N/A | 0.402
1024000 | N/A | N/A | 0.813
2048000 | N/A | N/A | 1.637
4096000 | N/A | N/A | 3.227
8192000 | N/A | N/A | 6.558
16384000 | N/A | N/A | 13.019
32768000 | N/A | N/A | 26.191
65536000 | N/A | N/A | 51.971
100000000 | N/A | N/A | 79.690
```

> **Nota:** Las versiones cúbica y cuadrática dejan de ejecutarse automáticamente cuando su tiempo supera un umbral de aproximadamente **5 segundos**. Por ello aparecen como `N/A` para tamaños posteriores.

Esto evita realizar ejecuciones que tomarían tiempos excesivamente largos.

---

## 4. Razón de duplicación

Para determinar experimentalmente el orden de crecimiento, se calcula:

$$
R(n) = \frac{T(2n)}{T(n)}
$$

Al duplicar `n`, los valores esperados son aproximadamente:

| Orden   | Razón esperada |
| ------- | -------------: |
| `Θ(n)`  |             ×2 |
| `Θ(n²)` |             ×4 |
| `Θ(n³)` |             ×8 |

### Razones obtenidas

|           n |    Cúbica | Razón | Cuadrática | Razón | Kadane | Razón |
| ----------: | --------: | ----: | ---------: | ----: | -----: | ----: |
|       1 000 |    43.246 |     — |      0.260 |     — |  0.001 |     — |
|       2 000 |   301.065 | ×6.96 |      0.973 | ×3.74 |  0.002 | ×2.00 |
|       4 000 |  2426.301 | ×8.06 |      3.708 | ×3.81 |  0.004 | ×2.00 |
|       8 000 | 19757.081 | ×8.15 |     15.072 | ×4.07 |  0.008 | ×2.00 |
|      16 000 |       N/A |     — |     60.325 | ×4.00 |  0.015 | ×1.88 |
|      32 000 |       N/A |     — |    250.180 | ×4.15 |  0.026 | ×1.73 |
|      64 000 |       N/A |     — |    966.142 | ×3.86 |  0.061 | ×2.35 |
|     128 000 |       N/A |     — |   3870.427 | ×4.01 |  0.109 | ×1.79 |
|     256 000 |       N/A |     — |  15201.135 | ×3.93 |  0.241 | ×2.21 |
|     512 000 |       N/A |     — |        N/A |     — |  0.402 | ×1.67 |
|   1 024 000 |       N/A |     — |        N/A |     — |  0.813 | ×2.02 |
|   2 048 000 |       N/A |     — |        N/A |     — |  1.637 | ×2.01 |
|   4 096 000 |       N/A |     — |        N/A |     — |  3.227 | ×1.97 |
|   8 192 000 |       N/A |     — |        N/A |     — |  6.558 | ×2.03 |
|  16 384 000 |       N/A |     — |        N/A |     — | 13.019 | ×1.98 |
|  32 768 000 |       N/A |     — |        N/A |     — | 26.191 | ×2.01 |
|  65 536 000 |       N/A |     — |        N/A |     — | 51.971 | ×1.98 |
| 100 000 000 |       N/A |     — |        N/A |     — | 79.690 |     — |

> Las razones de Kadane presentan pequeñas variaciones debido al ruido de medición, especialmente cuando los tiempos son muy pequeños. Sin embargo, al aumentar `n` se observa claramente un comportamiento cercano a ×2.

---

## 5. Orden de crecimiento deducido

Las razones obtenidas coinciden con los valores esperados:

### Algoritmo cúbico

Las razones observadas son aproximadamente ×8:

```text
6.96, 8.06, 8.15
```

Por lo tanto:

$$
\boxed{\Theta(n^3)}
$$

### Algoritmo cuadrático

Las razones se mantienen muy cercanas a ×4:

```text
3.74, 3.81, 4.07, 4.00, 4.15, 3.86, 4.01, 3.93
```

Por lo tanto:

$$
\boxed{\Theta(n^2)}
$$

### Algoritmo de Kadane

Las razones se mantienen aproximadamente alrededor de ×2:

```text
2.00, 2.00, 2.00, 1.88, 1.73, 2.35, ...
```

A partir de tamaños mayores, el comportamiento se estabiliza alrededor de ×2.

Por lo tanto:

$$
\boxed{\Theta(n)}
$$

Los resultados experimentales coinciden con el análisis teórico de las tres soluciones.

---

## 6. Predicción para `n = 10⁸`

Para estimar el tiempo para `n = 100 000 000`, se utiliza la última medición disponible de cada algoritmo y su orden de crecimiento.

### Cúbica

Última medición válida:

```text
n = 4000
T(n) = 2426.301 ms
```

Usando el crecimiento cúbico:

$$
T(10^8) \approx 2426.301
\left(\frac{10^8}{4000}\right)^3
$$

El resultado es aproximadamente:

```text
≈ 3.78 × 10^16 ms
≈ 1.20 × 10^6 años
```

Por lo tanto, resulta completamente inviable para `n = 10⁸`.

---

### Cuadrática

Última medición válida:

```text
n = 256000
T(n) = 15201.135 ms
```

Usando el crecimiento cuadrático:

$$
T(10^8) \approx 15201.135
\left(\frac{10^8}{256000}\right)^2
$$

Resultado aproximado:

```text
≈ 2.32 × 10^6 ms
≈ 38.7 minutos
```

Por lo tanto, tampoco cumple el requisito de terminar en menos de un minuto.

---

### Kadane

Una medición cercana a `10⁸` ya fue realizada directamente:

```text
n = 100000000
T(n) = 79.690 ms
```

Tomando como referencia:

```text
n = 65536000
T(n) = 51.971 ms
```

y asumiendo crecimiento lineal:

$$
T(10^8) \approx 51.971
\left(\frac{10^8}{65536000}\right)
$$

Predicción:

```text
≈ 79.30 ms
```

Medición real:

```text
79.690 ms
```

La diferencia es de aproximadamente:

```text
0.39 ms
```

o alrededor de **0.5 %**.

La predicción resulta, por tanto, bastante cercana al tiempo observado.

---

## 7. Comparación de predicción y medición

| Algoritmo  | Predicción para `n = 10⁸` |      Medición |
| ---------- | ------------------------: | ------------: |
| Cúbica     |         ≈ 1.20 × 10⁶ años |  No ejecutado |
| Cuadrática |                ≈ 38.7 min |  No ejecutado |
| Kadane     |                ≈ 79.30 ms | **79.690 ms** |

Según las predicciones, solamente **Kadane** resulta viable para `n = 10⁸` dentro del límite de un minuto, por lo que fue el único algoritmo ejecutado directamente con ese tamaño.

---

## 8. Conclusiones

Las tres implementaciones resuelven el mismo problema y producen la misma suma máxima, como se verificó mediante **100 pruebas aleatorias**.

Sin embargo, sus órdenes de crecimiento producen diferencias enormes en el tiempo de ejecución:

* La solución cúbica presenta un crecimiento aproximado de **×8** al duplicar `n`, confirmando `Θ(n³)`.
* La solución cuadrática presenta un crecimiento aproximado de **×4**, confirmando `Θ(n²)`.
* Kadane presenta un crecimiento aproximado de **×2**, confirmando `Θ(n)`.

La diferencia entre estos órdenes no es simplemente una cuestión de constantes. Al llegar a `n = 10⁸`, la solución cúbica y la cuadrática se vuelven impracticables, mientras que Kadane continúa resolviendo el problema en menos de un segundo.

Además, la predicción de Kadane para `n = 10⁸` fue de aproximadamente **79.30 ms**, mientras que la medición real fue de **79.690 ms**, mostrando una diferencia muy pequeña.

En consecuencia, el experimento demuestra de forma práctica la importancia del análisis de complejidad algorítmica: **un algoritmo con mejor orden de crecimiento puede superar por varios órdenes de magnitud a otro aparentemente equivalente cuando aumenta el tamaño de la entrada.**

---

## Estructura del repositorio

```text
.
├── max_subarray.cpp
└── README.md
```

### Compilación

```bash
g++ -O2 max_subarray.cpp -o max_subarray
```

### Ejecución

```bash
./max_subarray
```
