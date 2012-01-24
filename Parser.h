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

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Data.h"
#include "Trim.h"

using namespace std;

class Parser
{
private:
	string _raw;
	string _css;
	vector<RuleSet> _rules;
	StyleTemplate _template;

	LineMode _lineMode;

	void _parseRaw();
public:
	Parser(string raw);
	void sortCSS();
	void printCSS();
	string getCSS();
	void setLineMode(LineMode lm);
	~Parser();
};
