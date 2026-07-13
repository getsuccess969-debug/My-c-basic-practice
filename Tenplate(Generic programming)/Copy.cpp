/*#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
int main() {
	using namespace std::filesystem;
	//porrah
	path source{ current_path() };
	source /= "FileName.cpp";
	path dest{ current_path() };
	dest /= "Copy.cpp";
	std::ifstream input{ source };
	if (!input) { return -1; }
	std::ofstream output{ dest };
	std::string line;
	while (!std::getline(input, line).eof()) {
		output << line << "\n";

	}
	input.close();
	output.close();
	return 0;*/
