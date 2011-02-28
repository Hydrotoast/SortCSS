// This file is part of SortCSS
// Copyright (C) 2011 Gio Borje
//
// GaiaPack is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// GaiaPack is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>

using namespace std;

class FileBuffer
{
private:
	int _szOldFile;
	int _szNewFile;
public:
	string readFile(char* fileName);
	void writeFile(string fileName, string css);
};
