// This file is part of SortCSS
// Copyright (C) 2011 Gio Borje
//
// SortCSS is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SortCSS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "StdAfx.h"
#include "FileBuffer.h"

string FileBuffer::readFile(char* fileName) 
{
	struct stat fs;

	ifstream _file(fileName, ios::binary);
	string contents, line = "";

	if (_file.bad()) {
		cerr << "Cannot open bad file." << endl;
	} else {
		stat(fileName, &fs);
		FileBuffer::_szOldFile = fs.st_size;
		cout << "CSS File Input: " << &fileName[0] << endl;

		while (_file.good()) {
			getline(_file, line);
			contents += (line + "\n");
		}
	}
	_file.close();

	return contents;
}

void FileBuffer::writeFile(string fileName, string css)
{
	ofstream _file(fileName.c_str(), ios::out|ios::binary);
	if (_file.fail()) {
		cerr << "Failed writing CSS to file: " << fileName << endl;
	} else {
		_file << css << endl;
		_file.close();
		clog << "CSS File Output: " << &fileName[0] << endl;

		struct stat fs;
		stat(fileName.c_str(), &fs);
		FileBuffer::_szNewFile = fs.st_size;

		cout << setprecision(4) <<
			"Old File Size: " << FileBuffer::_szOldFile << " bytes" << endl <<
			"New File Size: " << FileBuffer::_szNewFile << " bytes" << endl << 
			"Compression Ratio: " << (((float)FileBuffer::_szNewFile / (float)FileBuffer::_szOldFile) * 100.00) << "%" << endl;
	}
}