#include <iostream>
#include <vector>
#include <string>

//Algoritmo de Z

// Función para calcular la función Z
std::vector<int> calculateZ(std::string s) {
    int n = s.length();
    std::vector<int> Z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= R) {
            Z[i] = std::min(R - i + 1, Z[i - L]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Función para contar todas las ocurrencias de la subcadena usando la función Z
int countOccurrences(std::string text, std::string pattern) {
    std::string concat = pattern + "$" + text;
    std::vector<int> Z = calculateZ(concat);
    
    int count = 0;
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == pattern.length()) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string text1 = "aaabcaabccaabcabcabcabc";
    std::string pattern1 = "abc";
    std::cout << "La subcadena '" << pattern1 << "' aparece " << countOccurrences(text1, pattern1) << " veces en '" << text1 << "'." << std::endl;

    std::string text2 = "mimamamemima";
    std::string pattern2 = "mima";
    std::cout << "La subcadena '" << pattern2 << "' aparece " << countOccurrences(text2, pattern2) << " veces en '" << text2 << "'." << std::endl;

    std::string text3 = "eseososeaseaasiasiseaseaeseoso";
    std::string pattern3 = "sea";
    std::cout << "La subcadena '" << pattern3 << "' aparece " << countOccurrences(text3, pattern3) << " veces en '" << text3 << "'." << std::endl;

    return 0;
}
