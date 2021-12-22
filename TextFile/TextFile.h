#ifndef _TEXTFILE_H
#define _TEXTFILE_H

#include <fstream>

class TextFile
{
private:
	std::fstream file;

public:

	//Конструкторы и деструктор:

	inline TextFile() {}

	inline TextFile(const char* name, long int mode)
	{
		Open(name, mode);
	}

	inline ~TextFile()
	{
		Close();
	}

	// открытие и закрытие файла:

	inline void Open(const char* name, long int mode)
	{
		file.open(name, std::ios::openmode(mode));
	}

	inline bool CheckForOpen(char* name, long int mode) 
	{
		Open(name, mode);
		return AllNice();
	}

	inline bool IsOpen()
	{
		return file.is_open();
	}

	inline void Close()
	{
		file.close();
	}

	//Чтение файла:

	template <class type> inline void readContent(type* pointer, int length) {
		file.read(reinterpret_cast<char*>(pointer), length);
	}

	inline void readContent(char* pointer, int length) {
		file.read(pointer, length);
	}

	inline void readString(char* pointer, int length) {
		file.read(pointer, length);
		*(pointer + length) = '\0';
	}

	template <class type> inline void read(type* pointer) {
		readContent(reinterpret_cast<char*>(pointer), sizeof(pointer));
	}

	template <class type> inline void read(type* array, int length) {
		readContent(reinterpret_cast<char*>(array), sizeof(type) * length);
	}

	template <class type> inline void readBlock(type* pointer) {
		file >> *pointer;
	}

	//Запись в файл:

	template <class type> inline void writeContent(type* pointer, int length) {
		file.write(reinterpret_cast<char*>(pointer), length);
	}

	inline void writeContent(char* pointer, int length) {
		file.write(pointer, length);
	}

	template <class type> inline void write(type* pointer) {
		writeContent(reinterpret_cast<char*>(pointer), sizeof(type));
	}

	template <class type> inline void write(type* array, int length) {
		writeContent(reinterpret_cast<char*>(array), sizeof(type) * length);
	}

	template <class type> inline void writeAsText(type variable) {
		file << variable;
	}

	template <class type> inline void writeAsText(type* pointer) {
		file << *pointer;
	}

	// перемещение и получение позиции указателя:

	inline int getPointerPosition() {
		return file.tellp();
	}

	inline void setPointerPosition(int position) {
		file.seekp(position);
	}

	// проверка состояния файла:

	inline bool isAllRight() {
		return file.good();
	}

	//Получение позиции указателя и перемещение указателя:

	inline int GetPointerPosition()
	{
		return file.tellp();
	}

	inline void SetPointerPosition(int position)
	{
		file.seekp(position);
	}


	//Проверка состояния файла:

	inline bool AllNice()
	{
		return file.good();
	}

	//Флаги для режимов работы с файлом:

	const static long int ForInput = 0;
	const static long int ForOutput = 1;
	const static long int ForAppend = 2;
	const static long int MoveToEnd = 3;
	const static long int AsBinary = 4;
	const static long int Truncate = 5;
};

#endif