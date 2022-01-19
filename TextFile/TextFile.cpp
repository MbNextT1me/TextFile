#include "TextFile.h"

TextFile::TextFile()
{
}

TextFile::TextFile(std::string path, TextFileState state)
{
	this->path = path;
	this->state = state;
	open();
}

TextFile::~TextFile()
{
	file.close();
}

void TextFile::open()
{
	if (state == TextFileState::in) {
		file.open(path, std::fstream::in);
		readFile();
	}
	else if (state == TextFileState::out)
	{
		file.open(path, std::fstream::app);
		readFile();
	}
}

bool TextFile::is_open()
{
	std::cout << "Try to open file...";
	
	if (!file.is_open()) {
		std::cout << "\tWrong path!\n";
		return false;
	}
	else {
		std::cout << "\tSuccess\n\n";
		return true;
	}
}

bool TextFile::strInFile(std::string addString)
{
	for (int i = 0; i < rFile.size(); i++)
	{
		if (rFile[i] == addString) return true;
	}

	return false;
}

bool TextFile::strInFile2(std::string addString, std::vector<std::string> rFile)
{
	for (int i = 0; i < rFile.size(); i++)
	{
		if (rFile[i] == addString) return true;
	}

	return false;
}

void TextFile::addToTheEndOfFile(TextFile& addFile)
{
	std::cout << "Add str-s from file 2 to file 1...";

	for (auto &element : addFile.rFile)
	{
		file << "\n" << element;
	}

	std::cout << "\tSuccess!\n";
}

void TextFile::sortColumn(SortState state, int col)
{
	std::cout << "Start sorting " << col << " column...";

	int rows = (int)rFile.size() - 1;
	int columns = 0;

	std::string str = rFile[0];

	//file << "\n" << str;

	char *next_token = NULL;
	char* c_str = new char[str.length() + 1];
	strcpy_s(c_str, str.length() + 1,str.c_str());

	char* pch = strtok_s(c_str, " \t", &next_token);
	while (pch != NULL)                         
	{
		columns++;
		pch = strtok_s(NULL, " \t", &next_token);
	}
		
	char** arr = new char * [rows] {};

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[columns]{};
	}

	std::cout << "\tSuccess!\n";
}

void TextFile::sumRowInCol(SortState state, int col)
{
	std::cout << "Start sum " << col << "column...";

	std::cout << "\tSuccess!";
}

void TextFile::operator += (std::string addString)
{
	if (strInFile(addString)){
		std::cout << "\nString already exist in file!\n";
	}
	else {
		SetConsoleCP(1251);
		file << std::endl << addString;
		SetConsoleCP(866);
		std::cout << "\nString add to file!\n";
	}
}

void TextFile::readFile() {
	std::string str;

	if (state == TextFileState::out)
	{
		file.close();
		file.open(path, std::fstream::in);

		while (!file.eof()) {
			str = "";
			std::getline(file, str);
			rFile.push_back(str);
		}

		file.close();
		file.open(path, std::fstream::app);
	}
	else {
		while (!file.eof()) {
			str = "";
			std::getline(file, str);
			rFile.push_back(str);
		}
	}
}

void TextFile::operator + (TextFile &addFile)
{
	std::cout << "Creating sum.txt file...";
	std::ofstream oFile("sum.txt");

	for (auto &element : rFile)
	{
		oFile << element << "\n";
	}

	for (auto &element : addFile.rFile)
	{
		if(!strInFile(element)) oFile << element << "\n";
	}
	std::cout << "\tSuccess!\n";
	oFile.close();
}

void TextFile::operator-=(TextFile& addFile)
{
	std::cout << "Starting delete same str in file...";

	file.close();
	file.open(path, std::fstream::out);

	for (auto &element : rFile)
	{
		if (!strInFile2(element, addFile.rFile)) file << element << "\n";
	}

	file.close();
	file.open(path, std::fstream::app);

	std::cout << "\tSuccess!\n";
}

void TextFile::operator - (TextFile& addFile)
{
	std::cout << "Creating sub.txt file...";
	std::ofstream oFile("sub.txt");
	
	for (auto &element : rFile)
	{
		if (!strInFile2(element, addFile.rFile)) oFile << element << "\n";
	}

	for (auto &element : addFile.rFile)
	{
		if (!strInFile(element)) oFile << element << "\n";
	}

	std::cout << "\tSuccess!\n";
	oFile.close();
}

