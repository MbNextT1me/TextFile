#include "TextFile.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	TextFile txt1("1.dat", TextFile::TextFileState::out);
	if (!txt1.is_open()) return 1;

	TextFile txt2("2.dat", TextFile::TextFileState::out);
	if (!txt2.is_open()) return 1;

	//txt1 += "35	08:43:09.638	8.719344	155591	0.038422	0.879733	489.661114	5.039799	-6.123316	46553	STARLINK-1664";
	//txt1 += "33	08:43:30.435	8.725121	157231	0.015170	0.368446	478.717789	11.261605	10.098157	46553	STARLINK-1664";

	//txt1 + txt2;
	//txt1 -= txt2;

	return 0;
}