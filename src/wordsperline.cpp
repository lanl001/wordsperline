//============================================================================
// Name        : wordsperline.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace __gnu_cxx;

int main(int argc, char* argv[])
{
	ifstream longreadfile;
	ofstream newfile(argv[2]);
	longreadfile.open(argv[1]);
	char buffer[10000];
	int gcounter = 0;
	int linecounter = 0;
	bool readinghead = false;
	stringstream ss;
	int baseperline;
	ss << argv[3];
	ss >> baseperline;

	while (longreadfile.read(buffer, 10000), longreadfile)
	{
		gcounter = longreadfile.gcount();
		for (int i = 0; i < gcounter; i++)
		{
			if (readinghead == true)
			{
				while (i < gcounter && buffer[i] != '\n')
				{
					newfile << buffer[i];
					i++;
				}
				if (i < gcounter)
				{
					newfile.put('\n');
					readinghead = false;
				}
			}
			if (buffer[i] == '>')
			{
				readinghead = true;
				if (linecounter % baseperline != 0)
					newfile.put('\n');
				linecounter = 0;
				i++;
				newfile.put('>');
				while (i < gcounter && buffer[i] != '\n')
				{
					newfile << buffer[i];
					i++;
				}
				if (i < gcounter)
				{
					newfile.put('\n');
					readinghead = false;
				}
			}
			else if (buffer[i] != '\n' && buffer[i] != '\t' && buffer[i] != ' ')
			{
				newfile.put(buffer[i]);
				linecounter++;
				if (linecounter % baseperline == 0)
				{
					newfile.put('\n');
				}
			}
		}
	}
	gcounter = longreadfile.gcount();
	for (int i = 0; i < gcounter; i++)
	{
		if (readinghead == true)
		{
			while (i < gcounter && buffer[i] != '\n')
			{
				newfile << buffer[i];
				i++;
			}
			if (i < gcounter)
			{
				newfile.put('\n');
				readinghead = false;
			}
			newfile.put('\n');
			readinghead = false;
		}
		if (buffer[i] == '>')
		{
			readinghead = true;
			if (linecounter % baseperline != 0)
				newfile.put('\n');
			linecounter = 0;
			i++;
			newfile.put('>');
			while (i < gcounter && buffer[i] != '\n')
			{
				newfile << buffer[i];
				i++;
			}
			if (i < gcounter)
			{
				newfile.put('\n');
				readinghead = false;
			}
		}
		else if (buffer[i] != '\n' && buffer[i] != '\t' && buffer[i] != ' ')
		{
			newfile.put(buffer[i]);
			linecounter++;
			if (linecounter % baseperline == 0)
			{
				newfile.put('\n');
			}
		}
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
