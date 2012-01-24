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

#include <iostream>
#include <string>

#include "stdafx.h"
#include "FileBuffer.h"
#include "Parser.h"
#include "Trim.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 0) {
		if (Trim::Both(argv[1]) == "-v") {
				cout << "SortCSS v0.0.1, Copyright (c) 2011 by Gio Borje" << endl;
		} else {
			FileBuffer* fb = new FileBuffer();

			string contents = fb->readFile(argv[1]);

			Parser* parser = new Parser(contents);
			parser->sortCSS();

			if (argc > 2) {
				bool modeSet = false;
				for (int i = 2; i < argc; i++) { 
					if (Trim::Both(argv[i]) == "-i" || Trim::Both(argv[i]) == "--inline") {
						if (modeSet == false) {
							parser->setLineMode(LineMode::INLINE);
							modeSet = true;
						}
					} else if(Trim::Both(argv[i]) == "-m" || Trim::Both(argv[i]) == "--mixed") {
						if (modeSet == false) {
							parser->setLineMode(LineMode::MIXED);
							modeSet = true;
						}
					} else if (Trim::Both(argv[i]) == "-o" || Trim::Both(argv[i]) == "--output") {
						string destination = (argc > i) ? Trim::Both(argv[i + 1]) : Trim::Both(argv[1]);
						string css = parser->getCSS();
						fb->writeFile(destination, css);
						
						return 0;
					}
				}
			}

			parser->printCSS();
		}
	} else {
		cout << "Usage: sortcss source_css [--inline | --output destination_css]" << endl;
	}

	return 0;
}

