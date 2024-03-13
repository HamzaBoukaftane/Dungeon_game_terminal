/*
* Ce fichier  en-tete definit la classe Game et le namespace
* decorateur. La classe Game possede toute les methodes de 
* fonctionnement logique du jeu. Elle encapsule deux booleans,
* un pour determiner si l'on joue encore et l'autre pour 
* determiner si le shotgun est charge. De plus, elle est 
* responsable de l'execution d'une commande et de son impact 
* sur le jeux. Elle encapsule egalement un inventaire, une 
* classe WordsRecognition, un WorldMap et les entrees du
* joueur. 
* fichier : Game.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "WorldMap.h"
#include "functional"
#include <map>
#include "CommandsLexical.h"
#include "WordsRecognition.h"
#include "MessagesLexical.h"

namespace decorator
{
	const string LEFT  = ">>>>>>>>>>>>>>  ";
	const string RIGHT = "  <<<<<<<<<<<<<<";
	const string FULL_LIGNE =
	" **************************************************************";
}


class Game
{
	using Function      = function<void(void)>;
	using ListCmd       = map<string, Function>;
	using ObjectPtr     = shared_ptr<ObjectAbs>;
	using Inventory     = unordered_map<string, ObjectPtr>;
	using ListUsable    = unordered_map<string, Function>;

public:

	Game()  = default;
	~Game() = default;
	void showIntroduction() const;
	void play();

protected:

	void resetCmd();
	void getInputCmd();
	void showCommands() const;
	void death();
	
	void printCurrentRoom() const;
	void printBeginning() const;
	void printInventory() const;
	
	void executeCommand(const string& command);
	void executeDirectionCmd(const string& command);
	void executeEndCmd();
	void executeHelpCmd() const;
	void executeLookCmd(const string& what);
	void executeTakeCmd(const string& what);
	void executeUseCmd(const string& what);	
	
	void useBed();
	void useBullet();
	void useChicken();
	void useCouch();
	void usePencil();
	void useKeySR();
	void useLadder();
	void useTv();
	void useShoes();
	void useShotgun();

	
	
private:

	bool     isPlaying_    = true;
	bool     isGunLoaded_  = false;
	string   playerCmd_    = NOTHING;
	string   playerObject_ = NOTHING;
	WorldMap map_;
	
	WordsRecognition playerInput_;
	Inventory        inventory_;
	
	ListCmd  listCmd_ =
	{
		{cmd::goN , [&](){ executeDirectionCmd(dir::N);   } },
		{cmd::goS , [&](){ executeDirectionCmd(dir::S);   } },
		{cmd::goE , [&](){ executeDirectionCmd(dir::E);   } },
		{cmd::goW , [&](){ executeDirectionCmd(dir::W);   } },
		{cmd::end , [&](){ executeEndCmd();               } },
		{cmd::hlp , [&](){ executeHelpCmd();              } },
		{cmd::look, [&](){ executeLookCmd(playerObject_); } },
		{cmd::take, [&](){ executeTakeCmd(playerObject_); } },
		{cmd::use , [&](){ executeUseCmd(playerObject_);  } }
	};

	ListUsable usables_ =
	{
		{obj::bed    , [&]() { useBed();     }},
		{obj::bullet , [&]() { useBullet();  }},
		{obj::shoes  , [&]() { useShoes();   }},
		{obj::ladder , [&]() { useLadder();  }},
		{obj::shotgun, [&]() { useShotgun(); }},
		{obj::couch  , [&]() { useCouch();   }},
		{obj::pencil , [&]() { usePencil();  }},
		{obj::keySR  , [&]() { useKeySR();   }},
		{obj::chicken, [&]() { useChicken(); }},
		{obj::tv     , [&]() { useTv();      }}
	};

};

