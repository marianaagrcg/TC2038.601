import time


def CUT_ROD(p, n):
    # Si la longitud de la varilla es 0, no hay ingresos
    if n == 0:
        return 0
    
    # Inicializa la variable para almacenar el máximo ingreso
    q = float('-inf')
    
    # Recorre todas las posibles longitudes de corte
    for i in range(1, n + 1):
        # Calcula el ingreso máximo posible cortando la varilla en la posición i
        q = max(q, p[i - 1] + CUT_ROD(p, n - i))
    
    # Retorna el ingreso máximo
    return q


p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30] + list(range(31, 81)) # Precios para longitudes de 1 a 10
n = 10  # Longitud de la varilla
max_revenue = CUT_ROD(p, n)
# start_time = time.time()
# result = CUT_ROD(p, n)
# end_time = time.time()
# print(f"n = {n}, Resultado = {result}, Tiempo de ejecución = {end_time - start_time:.6f} segundos")

print("El ingreso máximo es:", max_revenue)
