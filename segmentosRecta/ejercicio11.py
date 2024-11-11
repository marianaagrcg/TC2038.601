# Función para leer los puntos desde un archivo
def leer_puntos(archivo):
    puntos = []
    with open(archivo, 'r') as file:
        for linea in file:
            x, y = map(int, linea.split())
            puntos.append((x, y))
    return puntos

# Función para leer los segmentos desde un archivo
def leer_segmentos(archivo):
    segmentos = []
    with open(archivo, 'r') as file:
        for linea in file:
            # Lee los índices de los puntos y resta 1 para usarlos como índices en la lista de puntos
            p1, p2, p3, p4 = map(int, linea.split())
            segmentos.append((p1-1, p2-1, p3-1, p4-1))  # Ajuste de índices
    return segmentos

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

# Leer los segmentos del archivo 'segmentos.txt'
segmentos = leer_segmentos('segmentos.txt')

# Pruebas de los segmentos leídos
for i, (i1, i2, i3, i4) in enumerate(segmentos, 1):
    resultado = segments_intersect(puntos[i1], puntos[i2], puntos[i3], puntos[i4])
    print(f"Prueba {i}: Segmentos P{i1+1} P{i2+1} y P{i3+1} P{i4+1} -> {resultado}")
