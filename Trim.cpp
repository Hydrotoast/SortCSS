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
#include "Trim.h"

string Trim::Left(const string str)
{
	size_t pos = str.find_first_not_of(" \f\n\r\t\v");
	str.substr(pos);
	return str;
}

string Trim::Right(const string str)
{
	size_t pos = str.find_last_not_of(" \f\n\r\t\v");
	str.substr(0, pos);
	return str;
}

string Trim::Both(const string str)
{
	return Trim::Right(Trim::Left(str));
}

int Trim::Left(int start, const string str)
{
	while (isspace(str[--start])); 
	return ++start;
}

int Trim::Right(int start, const string str)
{
	while (isspace(str[++start]));
	return start;
}
