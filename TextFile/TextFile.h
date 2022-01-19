#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

class TextFile
{
public:
	//State for textFile
	enum class TextFileState{
		out,
		in
	};

	TextFile();
	TextFile(std::string path, TextFileState state);
	~TextFile();
	
	//Open file
	void open();

	//Check file
	bool is_open();

	//Sear string in txtFile
	bool strInFile(std::string addString);
	bool strInFile2(std::string addString, std::vector<std::string> rFile);

	//«+=» - add uniq str
	void operator += (std::string addString);

	//«+» - create new file with uniq str
	void operator + (TextFile &addFile);

	//«-=» - del same str with addFile
	void operator -= (TextFile& addFile);

	//«-» - create new file with only uniq in both file str
	void operator - (TextFile& addFile);

private:
	//Read file
	void readFile();
	std::vector<std::string> rFile;
	std::fstream file;
	std::string path = "";
	TextFileState state = TextFileState::in;
};

