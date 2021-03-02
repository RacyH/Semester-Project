#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include <iomanip>
fstream inFile;

class Save
{
public: 

	void SetFileName();
	string GetFileName() { return IOFile; };
	void SaveFile();
	void LoadFile();

private:
	string IOFile;
	Player playersave;
};

#endif //SAVE_H
