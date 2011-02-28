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

#include <string>
#include <vector>
#include <map>
#include <hash_map>

using namespace std;

static enum LineMode {
	BLOCK,
	INLINE,
	MIXED
};

static enum Mode {
	inRuleSet,
	outRuleSet,
	fauxRuleSet,
	inComment
};

static enum Property {
	DISPLAY,
	VISIBILITY,
	_FLOAT,
	CLEAR,

	POSITION,
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	Z_INDEX,

	OVERFLOW,

	WIDTH,
	MIN_WIDTH,
	MAX_WIDTH,
	HEIGHT,
	MIN_HEIGHT,
	MAX_HEIGHT,

	MARGIN,
	MARGIN_TOP,
	MARGIN_RIGHT,
	MARGIN_BOTTOM,
	MARGIN_LEFT,
	PADDING,
	PADDING_TOP, 
	PADDING_RIGHT, 
	PADDING_BOTTOM, 
	PADDING_LEFT,

	BORDER,
	BORDER_WIDTH,
	BORDER_STYLE,
	BORDER_COLOR,
	BORDER_TOP, 
	BORDER_RIGHT, 
	BORDER_BOTTOM, 
	BORDER_LEFT,
	BORDER_TOP_WIDTH, 
	BORDER_RIGHT_WIDTH, 
	BORDER_BOTTOM_WIDTH, 
	BORDER_LEFT_WIDTH,
	BORDER_TOP_STYLE, 
	BORDER_RIGHT_STYLE, 
	BORDER_BOTTOM_STYLE, 
	BORDER_LEFT_STYLE,
	BORDER_TOP_COLOR, 
	BORDER_RIGHT_COLOR, 
	BORDER_BOTTOM_COLOR,
	BORDER_LEFT_COLOR,
	BORDER_COLLAPSE,
	BORDER_SPACING,

	BACKGROUND,
	BACKGROUND_COLOR,
	BACKGROUND_IMAGE,
	BACKGROUND_REPEAT,
	BACKGROUND_POSITION,
	BACKGROUND_ATTACHMENT,

	OUTLINE,
	OUTLINE_WIDTH,
	OUTLINE_STYLE,
	OUTLINE_COLOR,

	LIST_STYLE,
	LIST_STYLE_TYPE,
	LIST_STYLE_POSITION,
	LIST_STYLE_IMAGE,
	COUNTER_INCREMENT,
	COUNTER_RESET,

	TABLE_LAYOUT,
	CAPTION_SIDE,
	EMPTY_CELLS,

	COLOR,
	FONT,
	FONT_FAMILY,
	FONT_SIZE,
	LINE_HEIGHT,
	FONT_STYLE,
	FONT_WEIGHT,
	FONT_VARIANT,
	TEXT_ALIGN,
	TEXT_INDENT,
	TEXT_TRANSFORM,
	TEXT_DECORATION,
	LETTER_SPACING,
	WORD_SPACING,
	WHITE_SPACE,
	WIDOWS,
	ORPHANS,
	VERTICAL_ALIGN,
	UNICODE_BIDI,
	DIRECTION,

	OPACITY,
	CLIP,
	PAGE_BREAK_AFTER,
	PAGE_BREAK_BEFORE,
	PAGE_BREAK_INSIDE,

	CURSOR,

	CONTENT,
	QUOTES,

	VOICE_FAMILY,
	VOLUME,
	RICHNESS,
	CUE,
	CUE_AFTER,
	CUE_BEFORE,
	AZIMUTH,
	ELEVATION,

	PLAY_DURING,
	PAUSE,
	PAUSE_BEFORE,
	PAUSE_AFTER,

	SPEAK,
	SPEAK_HEADER,
	SPEAK_NUMERAL,
	SPEAK_PUNCTUATION,
	SPEECH_RATE,
	STRESS,
	PITCH,
	PITCH_RANGE,

	_MOZ_BORDER_RADIUS,
	_WEBKIT_BORDER_RADIUS,
	_KHTML_BORDER_RADIUS,
	BORDER_RADIUS,

	_MOZ_BOX_SHADOW,
	_WEBKIT_BOX_SHADOW,
	_KHTML_BOX_SHADOW,
	BOX_SHADOW,

	_MOZ_TEXT_SHADOW,
	_WEBKIT_TEXT_SHADOW,
	_KHTML_TEXT_SHADOW,
	TEXT_SHADOW,
};


static map<string, Property> PropertyMap;

static void initData()
{
	PropertyMap["display"] = DISPLAY;
	PropertyMap["visibility"] = VISIBILITY;
	PropertyMap["float"] = _FLOAT;
	PropertyMap["clear"] = CLEAR;

	PropertyMap["position"] = POSITION;
	PropertyMap["top"] = TOP;
	PropertyMap["right"] = RIGHT;
	PropertyMap["bottom"] = BOTTOM;
	PropertyMap["left"] = LEFT;
	PropertyMap["z-index"] = Z_INDEX;

	PropertyMap["overflow"] = OVERFLOW;

	PropertyMap["width"] = WIDTH;
	PropertyMap["min-width"] = MIN_WIDTH;
	PropertyMap["max-width"] = MAX_WIDTH;
	PropertyMap["height"] = HEIGHT;
	PropertyMap["min-height"] = MIN_HEIGHT;
	PropertyMap["max-height"] = MAX_HEIGHT;

	PropertyMap["margin"] = MARGIN;
	PropertyMap["margin-top"] = MARGIN_TOP;
	PropertyMap["margin-right"] = MARGIN_RIGHT;
	PropertyMap["margin-bottom"] = MARGIN_BOTTOM;
	PropertyMap["margin-left"] = MARGIN_LEFT;
	PropertyMap["padding"] = PADDING;
	PropertyMap["padding-top"] = PADDING_TOP;
	PropertyMap["padding-right"] = PADDING_RIGHT;
	PropertyMap["padding-bottom"] = PADDING_BOTTOM;
	PropertyMap["padding-left"] = PADDING_LEFT;

	PropertyMap["border"] = BORDER;
	PropertyMap["border-width"] = BORDER_WIDTH;
	PropertyMap["border-style"] = BORDER_STYLE;
	PropertyMap["border-color"] = BORDER_COLOR;
	PropertyMap["border-top"] = BORDER_TOP;
	PropertyMap["border-right"] = BORDER_RIGHT;
	PropertyMap["border-bottom"] = BORDER_BOTTOM;
	PropertyMap["border-left"] = BORDER_LEFT;
	PropertyMap["border-top-width"] = BORDER_TOP_WIDTH;
	PropertyMap["border-right-width"] = BORDER_RIGHT_WIDTH;
	PropertyMap["border-bottom-width"] = BORDER_BOTTOM_WIDTH;
	PropertyMap["border-left-width"] = BORDER_LEFT_WIDTH;
	PropertyMap["border-top-style"] = BORDER_TOP_STYLE;
	PropertyMap["border-right-style"] = BORDER_RIGHT_STYLE;
	PropertyMap["border-bottom-style"] = BORDER_BOTTOM_STYLE;
	PropertyMap["border-left-style"] = BORDER_LEFT_STYLE;
	PropertyMap["border-top-color"] = BORDER_TOP_COLOR;
	PropertyMap["border-right-color"] = BORDER_RIGHT_COLOR;
	PropertyMap["border-bottom-color"] = BORDER_BOTTOM_COLOR;
	PropertyMap["border-left-color"] = BORDER_LEFT_COLOR;
	PropertyMap["border-collapse"] = BORDER_COLLAPSE;
	PropertyMap["border-spacing"] = BORDER_SPACING;

	PropertyMap["background"] = BACKGROUND;
	PropertyMap["background-color"] = BACKGROUND_COLOR;
	PropertyMap["background-image"] = BACKGROUND_IMAGE;
	PropertyMap["background-repeat"] = BACKGROUND_REPEAT;
	PropertyMap["background-position"] = BACKGROUND_POSITION;
	PropertyMap["background-attachment"] = BACKGROUND_ATTACHMENT;

	PropertyMap["outline"] = OUTLINE;
	PropertyMap["outline-width"] = OUTLINE_WIDTH;
	PropertyMap["outline-style"] = OUTLINE_STYLE;
	PropertyMap["outline-color"] = OUTLINE_COLOR;

	PropertyMap["list-style"] = LIST_STYLE;
	PropertyMap["list-style-type"] = LIST_STYLE_TYPE;
	PropertyMap["list-style-position"] = LIST_STYLE_POSITION;
	PropertyMap["list-style-image"] = LIST_STYLE_IMAGE;
	PropertyMap["counter-increment"] = COUNTER_INCREMENT;
	PropertyMap["counter-reset"] = COUNTER_RESET;

	PropertyMap["table-layout"] = TABLE_LAYOUT;
	PropertyMap["caption-side"] = CAPTION_SIDE;
	PropertyMap["empty-cells"] = EMPTY_CELLS;

	PropertyMap["color"] = COLOR;
	PropertyMap["font"] = FONT;
	PropertyMap["font-family"] = FONT_FAMILY;
	PropertyMap["font-size"] = FONT_SIZE;
	PropertyMap["line-height"] = LINE_HEIGHT;
	PropertyMap["font-style"] = FONT_STYLE;
	PropertyMap["font-weight"] = FONT_WEIGHT;
	PropertyMap["font-variant"] = FONT_VARIANT;
	PropertyMap["text-align"] = TEXT_ALIGN;
	PropertyMap["text-indent"] = TEXT_INDENT;
	PropertyMap["text-transform"] = TEXT_TRANSFORM;
	PropertyMap["text-decoration"] = TEXT_DECORATION;
	PropertyMap["letter-spacing"] = LETTER_SPACING;
	PropertyMap["word-spacing"] = WORD_SPACING;
	PropertyMap["white-space"] = WHITE_SPACE;
	PropertyMap["widows"] = WIDOWS;
	PropertyMap["orphans"] = ORPHANS;
	PropertyMap["vertical-align"] = VERTICAL_ALIGN;
	PropertyMap["unicode-bidi"] = UNICODE_BIDI;
	PropertyMap["direction"] = DIRECTION;

	PropertyMap["opacity"] = OPACITY;
	PropertyMap["clip"] = CLIP;
	PropertyMap["page-break-after"] = PAGE_BREAK_AFTER;
	PropertyMap["page-break-before"] = PAGE_BREAK_BEFORE;
	PropertyMap["page-break-inside"] = PAGE_BREAK_INSIDE;

	PropertyMap["cursor"] = CURSOR;

	PropertyMap["content"] = CONTENT;
	PropertyMap["quotes"] = QUOTES;

	PropertyMap["voice-family"] = VOICE_FAMILY;
	PropertyMap["volume"] = VOLUME;
	PropertyMap["richness"] = RICHNESS;
	PropertyMap["cue"] = CUE;
	PropertyMap["cue-after"] = CUE_AFTER;
	PropertyMap["cue-before"] = CUE_BEFORE;
	PropertyMap["azimuth"] = AZIMUTH;
	PropertyMap["elevation"] = ELEVATION;

	PropertyMap["play-during"] = PLAY_DURING;
	PropertyMap["pause"] = PAUSE;
	PropertyMap["pause-before"] = PAUSE_BEFORE;
	PropertyMap["pause-after"] = PAUSE_AFTER;

	PropertyMap["speak"] = SPEAK;
	PropertyMap["speak-header"] = SPEAK_HEADER;
	PropertyMap["speak-numeral"] = SPEAK_NUMERAL;
	PropertyMap["speak-punctuation"] = SPEAK_PUNCTUATION;
	PropertyMap["speech-rate"] = SPEECH_RATE;
	PropertyMap["stress"] = STRESS;
	PropertyMap["pitch"] = PITCH;
	PropertyMap["pitch-range"] = PITCH_RANGE;

	PropertyMap["-moz-border-radius"] = _MOZ_BORDER_RADIUS;
	PropertyMap["-webkit-border-radius"] = _WEBKIT_BORDER_RADIUS;
	PropertyMap["-khtml-border-radius"] = _KHTML_BORDER_RADIUS;
	PropertyMap["border-radius"] = BORDER_RADIUS;

	PropertyMap["-moz-box-shadow"] = _MOZ_BOX_SHADOW;
	PropertyMap["-webkit-box-shadow"] = _WEBKIT_BOX_SHADOW;
	PropertyMap["-khtml-box-shadow"] = _KHTML_BOX_SHADOW;
	PropertyMap["box-shadow"] = BOX_SHADOW;

	PropertyMap["-moz-text-shadow"] = _MOZ_TEXT_SHADOW;
	PropertyMap["-webkit-text-shadow"] = _WEBKIT_TEXT_SHADOW;
	PropertyMap["-khtml-text-shadow"] = _KHTML_TEXT_SHADOW;
	PropertyMap["text-shadow"] = TEXT_SHADOW;
}

typedef struct _Declaration 
{
	string Property;
	string Value;

	string toString()
	{
		return (Property + ": " + Value + ";");
	}

	bool operator<(_Declaration decl)
	{
		if (Property.substr(0, 2) == "/*")
			return false;
		else if (decl.Property.substr(0, 2) == "/*")
			return true;
		else if (PropertyMap[Property] < PropertyMap[decl.Property])
			return true;
		else 
			return false;
	}
} Declaration;

typedef struct _RuleSet 
{
	string Selector;
	vector<Declaration> Declarations;

	string length()
	{
		int sum;
		for (vector<Declaration>::iterator iter = Declarations.begin(); iter != Declarations.end(); ++iter) {
			Declaration decl = *iter;
			sum += decl.toString().length();
		}
	}

	friend bool operator==(_RuleSet rules1, _RuleSet rules2)
	{
		if (rules1.Selector == rules2.Selector)
			return true;
		else
			return false;
	}
} RuleSet;

typedef struct _StyleTemplate 
{
	string beforeOpenBrace;
	string afterOpenBrace;

	string beforeProperty;
	string afterProperty;

	string beforeValue;
	string afterValue;

	string beforeCloseBrace;
	string afterCloseBrace;

	bool removeComments;
} StyleTemplate;
