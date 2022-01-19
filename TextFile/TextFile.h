#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

class TextFile
{
public:
	//State for sort
	enum class SortState {
		up, //from min to max
		down //from max to min
	};

	//State for textFile
	enum class TextFileState{
		out,
		in
	};

	//Constructors and Destructor
	TextFile();
	TextFile(std::string path, TextFileState state);
	~TextFile();
	
	//Open file
	void open();

	//Check file
	bool is_open();

	//Search str in txtFile
	bool strInFile(std::string addString);
	bool strInFile2(std::string addString, std::vector<std::string> rFile);

	//add str from file2 to file1
	void addToTheEndOfFile(TextFile& addFile);

	//sort column in file
	void sortColumn (SortState state, int col);

	//sum row in column
	void sumRowInCol (SortState state, int col);

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
	
	//vector for str's from file
	std::vector<std::string> rFile;
	
	//main txt file
	std::fstream file;

	//path to file
	std::string path = "";

	//state of textFile
	TextFileState state = TextFileState::in;
};

