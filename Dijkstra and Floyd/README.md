# Manual de Usuario: Programa de Algoritmos de Dijkstra y Floyd-Warshall

## Descripción:
Este programa implementa los algoritmos de Dijkstra y Floyd-Warshall para encontrar la distancia más corta entre pares de nodos en un grafo dirigido, usando una matriz de adyacencias. Lee los datos desde un archivo de texto que contiene la matriz y devuelve los resultados para ambos algoritmos.

---

### Pasos para acceder a Ubuntu en WSL

1. **Instalar WSL (si aún no está instalado):**
   - Abre una terminal de **PowerShell** como administrador (haz clic derecho en el botón de Inicio y selecciona "Windows PowerShell (Administrador)").
   - Escribe el siguiente comando para instalar WSL:

     ```bash
     wsl --install
     ```

   - Si deseas instalar una distribución específica como **Ubuntu**, usa el siguiente comando:

     ```bash
     wsl --install -d Ubuntu
     ```

   - Para asegurarte de que WSL está actualizado, ejecuta el siguiente comando:

     ```bash
     wsl --update
     ```

2. **Acceder a Ubuntu y navegar a la carpeta de tu proyecto:**
   - Una vez que Ubuntu esté instalado, puedes abrirlo desde el menú de inicio de **Windows**.
   - Cuando estés dentro de **Ubuntu**, navega a la carpeta donde tienes tus archivos de código. Como estás trabajando en un directorio dentro de **Windows**, los discos están montados bajo el directorio `/mnt`.

   - Usa el siguiente comando para acceder a tu directorio específico:

     ```bash
     cd /mnt/c/Users/maria/Documents/Escuela/QUINTO\ SEMESTRE\ TEC/Algoritmos/Dijkstra\ and\ Floyd
     ```

---

### Compilar desde Ubuntu (Linux)

1. **Abrir una terminal en Ubuntu**.

2. **Navegar al directorio donde tienes el archivo `main.cpp` y el archivo `in.txt`.**

   - Si no lo has hecho ya, asegúrate de estar en la ruta correcta:

     ```bash
     cd /mnt/c/Users/maria/Documents/Escuela/QUINTO\ SEMESTRE\ TEC/Algoritmos/Dijkstra\ and\ Floyd
     ```

3. **Compilar el programa:**
   - Ejecuta el siguiente comando para compilar el archivo `main.cpp`:

     ```bash
     g++ main.cpp -o programa
     ```

4. **Ejecutar el programa:**
   - Para ejecutar el programa y redirigir la entrada desde el archivo `in.txt`, utiliza el siguiente comando:

     ```bash
     ./programa < in.txt
     ```

5. **Ver el resultado:**
   - El programa imprimirá en la terminal los resultados de las distancias calculadas por los algoritmos de Dijkstra y Floyd-Warshall.
