#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Función para construir la tabla de prefijos para KMP
std::vector<int> buildKMPTable(const std::string &pattern) {
    std::vector<int> table(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); ++i) {
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        } else {
            if (j > 0) {
                j = table[j - 1];
                --i;
            } else {
                table[i] = 0;
            }
        }
    }
    return table;
}

// Función KMP para buscar una parte del patrón en el texto
int KMPsearch(const std::string &text, const std::string &pattern) {
    std::vector<int> table = buildKMPTable(pattern);
    int j = 0;
    for (int i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                return i - j;
            }
            ++j;
        }
    }
    return -1; // No se encontró el patrón
}

// Función para dividir un patrón en partes separadas por el comodín '*'
std::vector<std::string> splitPattern(const std::string &pattern) {
    std::vector<std::string> parts;
    std::string temp = "";

    for (char c : pattern) {
        if (c == '*') {
            if (!temp.empty()) {
                parts.push_back(temp);
                temp.clear();
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        parts.push_back(temp);
    }

    return parts;
}

// Función que verifica si un patrón (con partes separadas) se encuentra en el texto utilizando KMP
bool isPatternInTextKMP(const std::string &text, const std::vector<std::string> &parts) {
    size_t pos = 0;
    for (const std::string &part : parts) {
        pos = KMPsearch(text.substr(pos), part);
        if (pos == std::string::npos) {
            return false;
        }
        pos += part.size();
    }
    return true;
}

// Función para verificar si una cadena es un número
bool isNumber(const std::string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

// Programa para leer desde un archivo y procesar múltiples bloques de entrada
int main() {
    std::string filename = "input.txt"; 

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        return 1;
    }

    while (file) {
        int n;
        std::string text;

        file >> n; // Leer número de patrones a procesar
        file.ignore(); // Ignorar salto de línea después del número

        if (!getline(file, text)) break; // Leer el texto

        for (int i = 0; i < n; ++i) {
            std::string pattern;
            if (!getline(file, pattern)) break; // Leer el patrón

            // Verificar si lo leído es un número, lo que indica que se ha pasado al siguiente bloque
            if (isNumber(pattern)) {
                // Restablecer `n` y `text` para el siguiente bloque
                std::stringstream ss(pattern);
                ss >> n;
                file.ignore(); // Ignorar salto de línea después del número
                getline(file, text); // Leer el nuevo texto
                i = -1; // Reiniciar el índice para comenzar con los patrones del nuevo bloque
                continue;
            }

            std::vector<std::string> parts = splitPattern(pattern);

            if (isPatternInTextKMP(text, parts)) {
                std::cout << pattern << " SI" << std::endl;
            } else {
                std::cout << pattern << " NO" << std::endl;
            }
        }

        // Para manejar adecuadamente los saltos de línea entre bloques de entrada
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    file.close();
    return 0;
}
