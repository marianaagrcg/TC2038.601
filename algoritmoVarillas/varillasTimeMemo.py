import time

def cut_rod(p, n, memo):
    if n == 0:
        return 0
    if memo[n] >= 0:
        return memo[n]
    
    q = float('-inf')
    for i in range(1, n + 1):
        q = max(q, p[i] + cut_rod(p, n - i, memo))
    memo[n] = q
    return q

# Generar un arreglo p con valores crecientes después de n=10
p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30] + list(range(31, 81))

# Ejecutar el programa para n = 10, 20, 30, 40, 50
for n in [10, 20, 30, 40, 50]:
    memo = [-1] * (n + 1)
    start_time = time.time()
    result = cut_rod(p, n, memo)
    end_time = time.time()
    print(f"n = {n}, Resultado = {result}, Tiempo de ejecución = {end_time - start_time:.6f} segundos")
