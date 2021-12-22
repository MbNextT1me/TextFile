#include "TextFile.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	TextFile file("chirp_20210126_084300_003.txt", TextFile::ForInput);

	return 0;
}