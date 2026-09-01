# Máximo Subarreglo: Cúbica, Cuadrática y Kadane

Laboratorio de **Análisis y Diseño de Algoritmos — UNSA**

Implementación y comparación experimental de tres soluciones al problema del máximo subarreglo:

* Solución cúbica — `Θ(n³)`
* Solución cuadrática — `Θ(n²)`
* Algoritmo de Kadane — `Θ(n)`

El objetivo es comprobar experimentalmente sus órdenes de crecimiento mediante mediciones de tiempo y estudiar cómo cambia su rendimiento al aumentar el tamaño de la entrada.

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

Se implementaron tres soluciones al problema del máximo subarreglo:

1. **Cúbica:** prueba todos los segmentos y calcula su suma desde cero.
2. **Cuadrática:** mantiene la suma acumulada al extender cada segmento.
3. **Kadane:** recorre el arreglo una sola vez, manteniendo la mejor suma que termina en cada posición y la mejor suma global.

Las tres soluciones deben devolver la misma suma máxima.

Para verificar la implementación, se generaron **100 arreglos pequeños aleatorios**, con tamaños entre 1 y 50 y valores enteros entre `-100` y `100`.

Resultado:

```text
100/100 pruebas coinciden
```

Las tres implementaciones produjeron el mismo resultado en las 100 pruebas realizadas.

---

## 3. Medición

Se midió el tiempo de ejecución duplicando el tamaño de la entrada:

```text
1000, 2000, 4000, 8000, 16000, ...
```

Los tiempos están expresados en milisegundos.

### Tabla de tiempos

|           n | Cúbica (ms) | Cuadrática (ms) | Kadane (ms) |
| ----------: | ----------: | --------------: | ----------: |
|       1 000 |      43.246 |           0.260 |       0.001 |
|       2 000 |     301.065 |           0.973 |       0.002 |
|       4 000 |    2426.301 |           3.708 |       0.004 |
|       8 000 |   19757.081 |          15.072 |       0.008 |
|      16 000 |         N/A |          60.325 |       0.015 |
|      32 000 |         N/A |         250.180 |       0.026 |
|      64 000 |         N/A |         966.142 |       0.061 |
|     128 000 |         N/A |        3870.427 |       0.109 |
|     256 000 |         N/A |       15201.135 |       0.241 |
|     512 000 |         N/A |             N/A |       0.402 |
|   1 024 000 |         N/A |             N/A |       0.813 |
|   2 048 000 |         N/A |             N/A |       1.637 |
|   4 096 000 |         N/A |             N/A |       3.227 |
|   8 192 000 |         N/A |             N/A |       6.558 |
|  16 384 000 |         N/A |             N/A |      13.019 |
|  32 768 000 |         N/A |             N/A |      26.191 |
|  65 536 000 |         N/A |             N/A |      51.971 |
| 100 000 000 |         N/A |             N/A |      79.690 |

Las versiones cúbica y cuadrática dejan de ejecutarse automáticamente cuando su tiempo supera aproximadamente **5 segundos**. Por ello aparecen como `N/A` para tamaños posteriores.

Esto evita realizar ejecuciones que requerirían tiempos excesivamente largos.

---

## 4. Razón de duplicación

Para analizar experimentalmente el orden de crecimiento se utiliza la razón:

$$
\frac{T(2n)}{T(n)}
$$

Si al duplicar `n` el tiempo se multiplica aproximadamente por:

| Razón | Orden de crecimiento |
| ----: | -------------------- |
|    ×2 | `Θ(n)`               |
|    ×4 | `Θ(n²)`              |
|    ×8 | `Θ(n³)`              |

Por lo tanto, la razón de duplicación permite estimar el exponente del crecimiento mediante:

$$
b = \log_2\left(\frac{T(2n)}{T(n)}\right)
$$

---

### Tabla de razones

|          n | Cúbica `T(2n)/T(n)` | Cuadrática `T(2n)/T(n)` | Kadane `T(2n)/T(n)` |
| ---------: | ------------------: | ----------------------: | ------------------: |
|      1 000 |                   — |                       — |                   — |
|      2 000 |               ×6.96 |                   ×3.74 |               ×2.00 |
|      4 000 |               ×8.06 |                   ×3.81 |               ×2.00 |
|      8 000 |               ×8.15 |                   ×4.07 |               ×2.00 |
|     16 000 |                 N/A |                   ×4.00 |               ×1.88 |
|     32 000 |                 N/A |                   ×4.15 |               ×1.73 |
|     64 000 |                 N/A |                   ×3.86 |               ×2.35 |
|    128 000 |                 N/A |                   ×4.01 |               ×1.79 |
|    256 000 |                 N/A |                   ×3.93 |               ×2.21 |
|    512 000 |                 N/A |                     N/A |               ×1.67 |
|  1 024 000 |                 N/A |                     N/A |               ×2.02 |
|  2 048 000 |                 N/A |                     N/A |               ×2.01 |
|  4 096 000 |                 N/A |                     N/A |               ×1.97 |
|  8 192 000 |                 N/A |                     N/A |               ×2.03 |
| 16 384 000 |                 N/A |                     N/A |               ×1.98 |
| 32 768 000 |                 N/A |                     N/A |               ×2.01 |
| 65 536 000 |                 N/A |                     N/A |               ×1.99 |

---

### Orden de crecimiento deducido

| Algoritmo  | Razón esperada | Razón observada | `b = log₂(razón)` |   Orden |
| ---------- | -------------: | --------------: | ----------------: | ------: |
| Cúbica     |             ×8 |            ≈ ×8 |               ≈ 3 | `Θ(n³)` |
| Cuadrática |             ×4 |            ≈ ×4 |               ≈ 2 | `Θ(n²)` |
| Kadane     |             ×2 |            ≈ ×2 |               ≈ 1 |  `Θ(n)` |

La solución cúbica presenta razones cercanas a ×8, la cuadrática razones cercanas a ×4 y Kadane razones cercanas a ×2.

Las pequeñas variaciones observadas en Kadane se deben principalmente a que sus tiempos de ejecución son muy pequeños y, por tanto, la medición es más sensible al ruido del sistema.

Los resultados experimentales coinciden con los órdenes de crecimiento obtenidos mediante el análisis teórico.

---

## 5. Predicción para `n = 10⁸`

Para estimar el tiempo de ejecución se utiliza el modelo:

$$
T(n)=a n^b
$$

donde `b` corresponde al exponente obtenido a partir del orden de crecimiento.

### Cúbica

Última medición válida:

```text
n = 4000
T(n) = 2426.301 ms
```

Con `b = 3`:

$$
T(10^8)
\approx
2426.301
\left(\frac{10^8}{4000}\right)^3
$$

Resultado:

```text
≈ 3.78 × 10^16 ms
≈ 1.20 × 10^6 años
```

La ejecución resulta completamente inviable para `n = 10⁸`.

---

### Cuadrática

Última medición válida:

```text
n = 256000
T(n) = 15201.135 ms
```

Con `b = 2`:

$$
T(10^8)
\approx
15201.135
\left(\frac{10^8}{256000}\right)^2
$$

Resultado:

```text
≈ 2.32 × 10^6 ms
≈ 38.7 minutos
```

La ejecución tampoco cumple el límite de un minuto.

---

### Kadane

Última medición antes de `10⁸`:

```text
n = 65536000
T(n) = 51.971 ms
```

Con `b = 1`:

$$
T(10^8)
\approx
51.971
\left(\frac{10^8}{65536000}\right)
$$

Predicción:

```text
≈ 79.30 ms
```

Por lo tanto, según la estimación, Kadane es la única solución que puede ejecutarse para `n = 10⁸` en menos de un minuto.

---

## 6. Predicción vs. medición

Kadane fue ejecutado directamente con:

```text
n = 100000000
```

Resultado medido:

```text
79.690 ms
```

| Algoritmo  | Predicción para `n = 10⁸` |      Medición |
| ---------- | ------------------------: | ------------: |
| Cúbica     |         ≈ 1.20 × 10⁶ años |  No ejecutado |
| Cuadrática |            ≈ 38.7 minutos |  No ejecutado |
| Kadane     |                ≈ 79.30 ms | **79.690 ms** |

Para Kadane:

$$
\text{diferencia} \approx 79.690 - 79.30 = 0.39\text{ ms}
$$

La diferencia relativa es aproximadamente **0.5 %**, por lo que la predicción se encuentra muy cerca del tiempo medido.

---

## 7. Conclusiones

Las tres soluciones resuelven el mismo problema y producen la misma suma máxima, lo cual fue comprobado mediante 100 arreglos pequeños generados aleatoriamente.

La medición experimental muestra tres comportamientos claramente diferenciados:

* **Cúbica:** al duplicar `n`, el tiempo aumenta aproximadamente ×8 → `Θ(n³)`.
* **Cuadrática:** al duplicar `n`, el tiempo aumenta aproximadamente ×4 → `Θ(n²)`.
* **Kadane:** al duplicar `n`, el tiempo aumenta aproximadamente ×2 → `Θ(n)`.

La razón de duplicación permite identificar experimentalmente el orden de crecimiento sin necesidad de basarse únicamente en el código.

Para `n = 10⁸`, las diferencias se vuelven especialmente grandes. La solución cúbica requeriría aproximadamente **1.20 millones de años**, mientras que la cuadrática tardaría aproximadamente **38.7 minutos**. En cambio, Kadane procesa esa cantidad de elementos en aproximadamente **79.690 ms**.

La predicción para Kadane fue de aproximadamente **79.30 ms**, frente a los **79.690 ms** medidos, mostrando una diferencia relativa de alrededor del **0.5 %**.

El experimento muestra cómo el orden de crecimiento determina la escalabilidad de un algoritmo. Para entradas suficientemente grandes, el cambio de algoritmo tiene un impacto mucho mayor que una mejora en las constantes de ejecución o en el hardware utilizado.

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
