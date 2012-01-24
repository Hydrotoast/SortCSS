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

#include <string>

using namespace std;

class Trim
{
public:
	static string Left(const string str);
	static string Right(const string str);
	static string Both(const string str);
	static int Left(int start, const string str);
	static int Right(int start, const string str);
};
