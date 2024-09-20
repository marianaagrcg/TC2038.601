#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // Para trabajar con archivos
#include <sstream>  // Para procesar cada línea del archivo

// Función para calcular el arreglo Z
std::vector<int> calculateZ(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) {
                R++;
            }
            z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (z[k] < R - i + 1) {
                z[i] = z[k];
            } else {
                L = i;
                while (R < n && s[R - L] == s[R]) {
                    R++;
                }
                z[i] = R - L;
                R--;
            }
        }
    }
    return z;
}

// Función para encontrar la subcadena utilizando el algoritmo Z
void searchSubstring(const std::string& text, const std::string& pattern) {
    std::string concat = pattern + "$" + text;
    std::vector<int> z = calculateZ(concat);
    int patternLength = pattern.length();
    int count = 0;

    for (int i = 0; i < z.size(); i++) {
        if (z[i] == patternLength) {
            count++;
        }
    }

    std::cout << "La subcadena \"" << pattern << "\" aparece " << count << " veces en \"" << text << "\"" << std::endl;
}

int main() {
    std::ifstream inputFile("input.txt"); // Archivo que contiene los casos
    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string text, pattern;
        
        // Leer el texto y el patrón de cada línea
        if (ss >> text >> pattern) {
            searchSubstring(text, pattern);  // Llamar a la función de búsqueda
        } else {
            std::cerr << "Formato de línea incorrecto en: " << line << std::endl;
        }
    }

    inputFile.close();
    return 0;
}
