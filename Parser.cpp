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
#include "Parser.h"

Parser::Parser(string raw)
{
	initData();

	Parser::setLineMode(LineMode::BLOCK);

	raw += "\n";
	Parser::_raw = raw;
	Parser::_parseRaw();
}

void Parser::sortCSS()
{
	// Iterate through RuleSets
	for (vector<RuleSet>::iterator iter = Parser::_rules.begin(); 
        iter != Parser::_rules.end(); 
        ++iter) {
		// Sort Declarations within RuleSets
		sort(iter->Declarations.begin(), iter->Declarations.end());
	}
}

void Parser::printCSS()
{
	for (vector<RuleSet>::iterator iter = Parser::_rules.begin(); 
        iter != Parser::_rules.end(); 
        ++iter) {
		cout << iter->Selector << 
			Parser::_template.beforeOpenBrace << '{';
		
		if (Parser::_lineMode == LineMode::MIXED && 
                (iter->Declarations.size() == 1 
                    || iter->Declarations.size() == 0)) {
			cout << ' ';
			for (vector<Declaration>::iterator it = iter->Declarations.begin(); 
                it != iter->Declarations.end(); 
                it++) {
				if (!it->Value.empty()) {
					cout << it->Property << ": " << it->Value << "; ";
				} else if (Parser::_template.removeComments == false) {
					cout << Parser::_template.beforeProperty << it->Property + ' '; 
				}
				cout << "}\n";
			}
		} else {
			cout << Parser::_template.afterOpenBrace;
			for (vector<Declaration>::iterator it = iter->Declarations.begin(); 
                it != iter->Declarations.end(); 
                it++) {
				if (!it->Value.empty()) {
					cout << Parser::_template.beforeProperty << 
                        it->Property << 
                        Parser::_template.afterProperty << 
						Parser::_template.beforeValue << 
						it->Value << 
						Parser::_template.afterValue;
				} else if (Parser::_template.removeComments == false) {
					cout << Parser::_template.beforeProperty << 
						it->Property << 
						((Parser::_lineMode == LineMode::INLINE) ? " " : "\n"); 
				}
			}
			cout << Parser::_template.beforeCloseBrace << 
                '}' << 
                Parser::_template.afterCloseBrace;
		}
	}
}

string Parser::getCSS()
{
	Parser::_css = "";
	for (vector<RuleSet>::iterator iter = Parser::_rules.begin(); 
        iter != Parser::_rules.end(); 
        ++iter) {
		Parser::_css += iter->Selector + 
			Parser::_template.beforeOpenBrace + '{';
		
		if (Parser::_lineMode == LineMode::MIXED 
            && (iter->Declarations.size() == 1 
                || iter->Declarations.size() == 0)) {
			Parser::_css += ' ';
			for (vector<Declaration>::iterator it = iter->Declarations.begin(); 
                it != iter->Declarations.end(); 
                it++) {
				if (!it->Value.empty()) {
					Parser::_css += it->Property + ": " + it->Value + "; ";
				} else if (Parser::_template.removeComments == false) {
					Parser::_css +=  Parser::_template.beforeProperty + 
                        it->Property + 
                        ' '; 
				}
			}
			Parser::_css += "}\n";
		} else {
			Parser::_css += Parser::_template.afterOpenBrace;
			for (vector<Declaration>::iterator it = iter->Declarations.begin(); 
                it != iter->Declarations.end(); 
                it++) {
				if (!it->Value.empty()) {
					Parser::_css += Parser::_template.beforeProperty + 
						it->Property + 
						Parser::_template.afterProperty + 
						Parser::_template.beforeValue + 
						it->Value + Parser::_template.afterValue;
				} else if (Parser::_template.removeComments == false) {
					Parser::_css +=  Parser::_template.beforeProperty + 
						it->Property + 
						((Parser::_lineMode == LineMode::INLINE) ? " " : "\n"); 
				}
			}

			Parser::_css += Parser::_template.beforeCloseBrace + '}' + Parser::_template.afterCloseBrace;
		}
	}

	return Parser::_css;
}

void Parser::setLineMode(LineMode lm)
{
	Parser::_lineMode = lm;

	switch (lm) {
		case LineMode::BLOCK:
			Parser::_template.beforeOpenBrace = " ";
			Parser::_template.afterOpenBrace = "\n";
			Parser::_template.beforeProperty = "\t"; 
			Parser::_template.afterProperty = ":";
			Parser::_template.beforeValue = " ";
			Parser::_template.afterValue = ";\n";
			Parser::_template.afterCloseBrace = "\n\n";
			Parser::_template.removeComments = false;
		break;
		case LineMode::INLINE:
			Parser::_template.beforeOpenBrace = " ";
			Parser::_template.afterOpenBrace = " ";
			Parser::_template.beforeProperty = ""; 
			Parser::_template.afterProperty = ":";
			Parser::_template.beforeValue = " ";
			Parser::_template.afterValue = "; ";
			Parser::_template.beforeCloseBrace = "";
			Parser::_template.afterCloseBrace = "\n\n";
		break;
	}
}

Parser::~Parser()
{
}

void Parser::_parseRaw()
{
	int start = 0;
	int tmp = 0;
	int line = 0;

	Mode mode = Mode::outRuleSet;
	int faux = 0;

	Declaration decl;
	Declaration comment;
	RuleSet ruleSet;

	int length = Parser::_raw.length();
	for (int i = 0; i < length; i++) {
		if (Parser::_raw[i] == '\r' || Parser::_raw[i] == '\n') {
			line++;
		}

		switch (Parser::_raw[i]) {
			// Start of declarations
			case '{':
				if (mode == Mode::outRuleSet) {
					mode = Mode::inRuleSet;
					tmp = Trim::Left(i, Parser::_raw.c_str());
					ruleSet.Selector = Parser::_raw.substr(start, tmp - start); // Selector token completion

					// Start of Property token
					start = Trim::Right(i + 1, Parser::_raw.c_str());
				} else {
					mode = Mode::fauxRuleSet;
					faux++;
				}
			break;

			// Start of inline-comments
			case '/':
				if (mode == Mode::inRuleSet && Parser::_raw[i + 1] == '*') {
					mode = Mode::inComment;
					start = i;
				} else if (mode == Mode::inComment) {
					if (Parser::_raw[i] != '*' && Parser::_raw[i + 1] != '/') {
						comment.Property = Parser::_raw.substr(start, i + 1 - start);
						comment.Value = "";
						ruleSet.Declarations.push_back(comment);
						start = Trim::Right(i + 1, Parser::_raw.c_str());

						mode = Mode::inRuleSet;
					}
				}
			break;

			// In between property-value pairs
			case ':':
				if (mode == Mode::inRuleSet) {
					decl.Property = Parser::_raw.substr(start, i - start); // Property token completion

					// Start of Value token
					start = Trim::Right(i + 1, Parser::_raw.c_str());
				}
			break;

			// Before and after property-value pairs
			case ';':
				if (mode == Mode::inRuleSet) {
					decl.Value = Parser::_raw.substr(start, i - start); // Value token completion
					ruleSet.Declarations.push_back(decl); // Declaration token completion

					// Start of Property token
					start = Trim::Right(i + 1, Parser::_raw.c_str());
				}
			break;

			// End of declarations
			case '}':
				if (mode == Mode::inRuleSet) {
					mode = Mode::outRuleSet;
					// Start of Selector token
					start = Trim::Right(i + 1, Parser::_raw.c_str());

					Parser::_rules.push_back(ruleSet); // RuleSet token completion
					ruleSet.Declarations.clear();
				} else if(mode == Mode::fauxRuleSet) {
					if (--faux == 0) {
						mode = Mode::inRuleSet;
					}
				}
			break;
		}
	}
}
