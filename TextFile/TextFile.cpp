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
		std::cout << "\tSuccess\n";
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

	for (auto element : rFile)
	{
		oFile << element << "\n";
	}

	for (auto element : addFile.rFile)
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

	for (auto element : rFile)
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
	
	for (auto element : rFile)
	{
		if (!strInFile2(element, addFile.rFile)) oFile << element << "\n";
	}

	for (auto element : addFile.rFile)
	{
		if (!strInFile(element)) oFile << element << "\n";
	}

	std::cout << "\tSuccess!\n";
	oFile.close();
}

