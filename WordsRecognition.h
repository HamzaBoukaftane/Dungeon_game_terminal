/*
* Ce fichier en-tete definit la classe WordsRecognition. Cette derniere
* permet d'analyser un string afin d'y retrouver les commandes et 
* les objets qui y sont rattache si besoin. Elle encapsule egalement
* deux variables de type string (cmd_ et object_) qui permettent de
* conserver tout en distinguant l'analyse d'un string.
* fichier : WordsRecognition.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <unordered_map>
#include <string>
#include <set>
#include <vector>
#include "ObjectLexical.h"
#include "CommandsLexical.h"

using namespace std;

static const string& NOTHING = "";

class WordsRecognition
{

	using ListWords       = set<string>;
	using WordsDictionary = unordered_map<string, ListWords>;

public:
	
	WordsRecognition()  = default;
	~WordsRecognition() = default;
	
	const string& getCmd()      const { return cmd_;    }
	const string& getObj()      const { return object_; }
	
	const bool& getIsUnknowed() const { return isUnknowed_; }
	const bool& getIsCmdFirst() const { return isFirstCmd_; }

	void analyze(const string& input)
	{
		findCmdWord(input);
		findKeyWord(input);
	}

protected:
	
	void findCmdWord(const string& input);
	void findKeyWord(const string& input);

private:

	string object_     = NOTHING;
	string cmd_        = NOTHING;
	
	bool   isUnknowed_ = false;
	bool   isFirstCmd_ = true;
	
	WordsDictionary words_ =
	{
		{ obj::shoes   , {"leather", "shoe"                               }},
		{ obj::couch   , {"red","broken", "couch"                         }},
		{ obj::tv      , {"opened", "cheap", "tv","TV", "Tv", "television"}},
		{ obj::shotgun , {"Remington", "shotgun", "weapon", "shotty"      }},
		{ obj::door    , {"wooden", "closed", "door"                      }},
		{ obj::chest   , {"solid", "metallic", "chest"                    }},
		{ obj::bed     , {"comfy", "king size", "bed", "comfortable"      }},
		{ obj::ladder  , {"up", "down" , "ladder"                         }},
		{ obj::pencil  , {"pen", "pencil"                                 }},
		{ obj::fridge  , {"yellow","fridge", "refrigerator"               }},
		{ obj::sink    , {"modern", "expansive", "nice" , "sink"          }},
		{ obj::bullet  , {"ammo", "bullet", "ammunition", "shotgun shell" }},
		{ obj::chicken , {"smelly", "rotten","chicken"                    }},
		{ obj::deadBody, {"body", "dead body", "corpse"                   }},
		{ obj::keySR   , {"special", "rusted", "key"                      }}
	};

	ListWords commands_ = 
	{
		cmd::goN,
		cmd::goS,
		cmd::goE,
		cmd::goW,
		cmd::end,
		cmd::hlp,
		cmd::look,
		cmd::take,
		cmd::use
	};
};