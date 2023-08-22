#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// If std::string::find does not find any more occurrences of s1, it returns std::string::npos 
// (which is a special constant value indicating "no position").
void replaceInString(std::string& content, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos += s2.length();
    }
}

int replace(std::string fileName, std::string s1, std::string s2)
{
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file: " << fileName << std::endl;
        return 1;
    }
	
	std::string fileContent;
    char c;
    while (inputFile.get(c)) {
        fileContent += c;
    }
    inputFile.close();
    replaceInString(fileContent, s1, s2);
	
	std::ofstream outputFile((fileName + ".replace"));
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file: " << fileName + ".replace" << std::endl;
        return 1;
    }

    outputFile << fileContent;
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << fileName + ".replace" << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return EXIT_FAILURE;
    }

	if (replace(argv[1], argv[2], argv[3]))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
