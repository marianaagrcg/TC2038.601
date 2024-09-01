#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Función que valida si el patrón p con comodines es un patrón en el texto t
bool isPatternInText(const std::string& text, const std::string& pattern) {
    std::string p = pattern;
    std::vector<std::string> parts;
    std::string temp = "";

    for (char c : p) {
        if (c == '*') {
            if (!temp.empty()) {
                parts.push_back(temp);
                temp = "";
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        parts.push_back(temp);
    }

    size_t pos = 0;
    for (const std::string& part : parts) {
        pos = text.find(part, pos);
        if (pos == std::string::npos) {
            return false;
        }
        pos += part.size();
    }

    return true;
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error abriendo el archivo" << std::endl;
        return 1;
    }

    int n;
    std::string text;
    file >> n >> std::ws;
    std::getline(file, text);

    for (int i = 0; i < n; ++i) {
        std::string pattern;
        std::getline(file, pattern);

        if (isPatternInText(text, pattern)) {
            std::cout << pattern << " SI" << std::endl;
        } else {
            std::cout << pattern << " NO" << std::endl;
        }
    }

    file.close();
    return 0;
}
