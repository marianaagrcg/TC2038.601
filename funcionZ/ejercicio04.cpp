#include <iostream>
#include <vector>
#include <string>

// Función para calcular el arreglo Z
std::vector<int> calculateZ(std::string s) {
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

    std::cout << "La subcadena " << pattern << " aparece " << count << " veces en " << text << std::endl;
}

int main() {
    // Pruebas con las cadenas y subcadenas proporcionadas
    searchSubstring("aaabcaabccaabcabcabcabc", "abc");
    searchSubstring("mimamamemima", "mima");
    searchSubstring("eseososeaseaasiasiseaseaeseoso", "sea");

    return 0;
}
