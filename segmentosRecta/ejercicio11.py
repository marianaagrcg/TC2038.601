# Función para leer los puntos desde un archivo
def leer_puntos(archivo):
    puntos = []
    with open(archivo, 'r') as file:
        for linea in file:
            x, y = map(int, linea.split())
            puntos.append((x, y))
    return puntos

# Definimos una función para calcular la dirección
def direction(pi, pj, pk):
    return (pk[0] - pi[0]) * (pj[1] - pi[1]) - (pj[0] - pi[0]) * (pk[1] - pi[1])

# Definimos la función ON_SEGMENT para verificar si un punto está en un segmento
def on_segment(pi, pj, pk):
    return (min(pi[0], pj[0]) <= pk[0] <= max(pi[0], pj[0]) and
            min(pi[1], pj[1]) <= pk[1] <= max(pi[1], pj[1]))

# Función principal para determinar si los segmentos se intersectan
def segments_intersect(p1, p2, p3, p4):
    d1 = direction(p3, p4, p1)
    d2 = direction(p3, p4, p2)
    d3 = direction(p1, p2, p3)
    d4 = direction(p1, p2, p4)

    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)):
        return "Los segmentos se intersectan"
    elif d1 == 0 and on_segment(p3, p4, p1):
        return "Los segmentos se tocan en un punto"
    elif d2 == 0 and on_segment(p3, p4, p2):
        return "Los segmentos se tocan en un punto"
    elif d3 == 0 and on_segment(p1, p2, p3):
        return "Los segmentos se tocan en un punto"
    elif d4 == 0 and on_segment(p1, p2, p4):
        return "Los segmentos se tocan en un punto"
    else:
        return "Los segmentos no se tocan"

# Leer los puntos del archivo 'puntos.txt'
puntos = leer_puntos('puntos.txt')

# Asignación de puntos a las variables P1, P2, ..., P8
P1, P2, P3, P4, P5, P6, P7, P8 = puntos

# Pruebas de los segmentos
print(segments_intersect(P1, P2, P3, P4))  # Segmentos P1P2 y P3P4
print(segments_intersect(P5, P6, P7, P8))  # Segmentos P5P6 y P7P8
print(segments_intersect(P3, P4, P7, P8))  # Segmentos P3P4 y P7P8
print(segments_intersect(P1, P7, P5, P6))  # Segmentos P1P7 y P5P6
print(segments_intersect(P1, P2, P7, P8))  # Segmentos P1P2 y P7P8
