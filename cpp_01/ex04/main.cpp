#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void replaceInString(std::string& content, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos += s2.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return 1;
    }

    std::string fileContent;
    char c;
    while (inputFile.get(c)) {
        fileContent += c;
    }
    inputFile.close();

    replaceInString(fileContent, s1, s2);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file: " << filename + ".replace" << std::endl;
        return 1;
    }

    outputFile << fileContent;
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << filename + ".replace" << std::endl;

    return 0;
}
