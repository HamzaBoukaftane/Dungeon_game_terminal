/*
* Ce fichier definit les implementations des methode findCmdWord
* et findKeyWord de la classe WordsRecognition. 
* fichier : WordsRecognition.cpp
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "WordsRecognition.h"

void WordsRecognition::findCmdWord(const string& input)
{
	
	isFirstCmd_ = true;
	cmd_        = NOTHING;

	for (auto cmd : commands_)
	{
		bool isCmd   = (input.find(cmd) != string::npos);
		bool isFirst = (input.find(cmd) == NULL);

		if (isCmd)
		{
			if (isFirst)
				cmd_ = cmd;
			else
				isFirstCmd_ = false;
		}
	}
}

void WordsRecognition::findKeyWord(const string& input)
{	
	size_t maxCmdSize  = cmd::look.size();
	
	object_     = NOTHING;
	isUnknowed_ = false;

	for (auto& [obj, words] : words_)
	{
		for (auto word : words)
		{
			bool isMatch = (input.find(word) != string::npos);

			if (isMatch)
				object_ = obj;
		}
	}

	bool isGoodCmd   = (cmd_ != NOTHING);
	bool isObject    = (object_ != NOTHING);
	bool isSomething = (input.size() > ++++maxCmdSize);

	if (isGoodCmd && !(isObject) && isSomething)
		isUnknowed_ = true;
}

