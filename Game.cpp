/*
* Ce fichier definit les methodes de la classe Game.
* fichier : Game.cpp
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "Game.h"

void Game::showIntroduction() const
{
	cout << decorator::LEFT << "THE ONE AND ONLY HOUSE GAME" << decorator::RIGHT << endl
		 << decorator::LEFT << " INF1015 GAME OF THE YEAR  " << decorator::RIGHT << endl << endl;

	showCommands();
	printBeginning();
}

void Game::play()
{
	while (isPlaying_)
	{
		getInputCmd();
		executeCommand(playerCmd_);
	}
}

void Game::resetCmd()
{
	playerCmd_    = NOTHING;
	playerObject_ = NOTHING;
}

void Game::getInputCmd()
{
	string input;
	resetCmd();

	cout << endl << " > ";
	getline(cin, input);

	playerInput_.analyze(input);

	playerCmd_    = playerInput_.getCmd();
	playerObject_ = playerInput_.getObj();
}

void Game::showCommands() const
{
	cout << " List of the game's commands: "                                  << endl << endl
		<< " 1 - " << cmd::goN  << " to travel North"                                 << endl
		<< " 2 - " << cmd::goS  << " to travel South"                                 << endl
		<< " 3 - " << cmd::goE  << " to travel East"                                  << endl
		<< " 4 - " << cmd::goW  << " to travel West"                                  << endl
		<< " 5 - " << cmd::end  << " to end game"                                     << endl
		<< " 6 - " << cmd::look << " to look items in room/inventory or to check room"<< endl
		<< " 7 - " << cmd::take << " to take items in room"                           << endl
		<< " 8 - " << cmd::hlp  << " to show the command's list"                      << endl
		<< " 9 - " << cmd::use  << " to use items in room"                    << endl << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "      PRO TIP 1 : All Directions Commands are in CAPITAL                " << endl
		<< "                  and the other commands in lower case                  " << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "      PRO TIP 2 : You have to enter the commands first                  " << endl
		<< "                  and after an object if needed.                        " << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "      PRO TIP 3 : You can use object if you are in the                  " << endl
		<< "                  room or if object is in your inventory.               " << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "      PRO TIP 4 : look alone will make you look the entire              " << endl
		<< "                  room.                                                 " << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "      PRO TIP 5 : It is mandatory to specify an object when             " << endl
		<< "                  using commands use and take.                          " << endl
		<<                    decorator::FULL_LIGNE                                   << endl
		<< "                    !!! GOOD LUCK !!!                                   " << endl
		<<                    decorator::FULL_LIGNE                           << endl << endl;
}

void Game::death()
{
	cout << message::ending::death << endl;
	executeEndCmd(); // Pour arreter de mourir. Commenter cette ligne.
}

void Game::printCurrentRoom() const
{
	map_.getCurrentRoom().printToStream();
	printInventory();
}

void Game::printBeginning() const
{
	map_.getBeginning().printToStream();
}

void Game::printInventory() const
{
	bool isEmpty = (inventory_.size() == NULL);
	if (!(isEmpty))
	{
		cout << " You have:" << endl;
		for (auto& [name, obj] : inventory_)
			cout << "\t" << name << endl;
	}
}

void Game::executeCommand(const string& command)
{
	bool isInListCmd = (listCmd_.find(command) != listCmd_.cend());
	bool isCmdFirst = (playerInput_.getIsCmdFirst());

	if (isInListCmd)
		listCmd_[command]();

	else if (!(isCmdFirst))
		cout << message::error::cmdNotFirst << endl;

	else
		cout << message::error::notValidCmd << endl;
}

void Game::executeDirectionCmd(const string& direction)
{
	auto listeConnects = map_.getCurrentRoom().getAdjacetRooms()->getListConnections();
	
	bool isRoom = (listeConnects[direction] != room::nothing);

	if (isRoom)
	{
		map_.setCurrentRoom(listeConnects[direction]);
		cout << " Going " << direction << endl << endl;
	}
	else
		cout << message::error::notValidDirection  << endl;

	printCurrentRoom();
}

void Game::executeEndCmd()
{
	cout << message::ending::end << endl;
	isPlaying_ = false;
}

void Game::executeHelpCmd() const
{
	showCommands();
	printCurrentRoom();
}

void Game::executeLookCmd(const string& what)
{
	auto listObjects = map_.getCurrentRoom().getListObjects();

	bool isInRoom      = (listObjects.find(what) != listObjects.cend());
	bool isInInventory = (inventory_.find(what) != inventory_.cend());
	bool isObject      = (what != NOTHING);
	bool isUnknowedObj = (playerInput_.getIsUnknowed());

	if (!(isObject) && !(isUnknowedObj))
	{
		cout << endl;
		printCurrentRoom();
	}

	else if (isUnknowedObj)
		cout << message::error::look::noValidObject << endl;

	else if (isInRoom)
		listObjects[what]->printDetails();

	else if (isInInventory)
		inventory_[what]->printDetails();

	else
		cout << message::error::notInRoomOrInInventory << endl;
}

void Game::executeTakeCmd(const string& what)
{
	auto listObjects   = map_.getCurrentRoom().getListObjects();
	
	bool isInRoom      = (listObjects.find(what) != listObjects.cend());
	bool isInInventory = (inventory_.find(what) != inventory_.cend());
	bool isObject      = (what != NOTHING);

	if (isInRoom)
	{
		bool isTakable = (listObjects[what]->isTakable());

		if (isTakable)
		{
			inventory_.insert({ what, listObjects[what] });
			cout << " The " << what << " was added to your inventory.\n" << endl;
			map_.removeObjectFromRoom(what);
		}
		else
			cout << message::error::notTakable << endl;
	}
	
	else if (!(isObject))
		cout << message::error::take::noValidObject << endl;

	else if (isInInventory)
		cout << " You already got " << what << " in your inventory.\n" << endl;

	else
		cout << message::error::notInRoomOrInInventory << endl << endl;
	
	printCurrentRoom();
}

void Game::executeUseCmd(const string& what)
{
	auto listObjects = map_.getCurrentRoom().getListObjects();

	bool isInRoom      = (listObjects.find(what) != listObjects.cend());
	bool isInInventory = (inventory_.find(what) != inventory_.cend());
	bool isUsable      = (usables_.find(what) != usables_.cend());
	bool isObject      = (what != NOTHING);

	if (isInInventory)
		usables_[what]();

	else if (!(isObject))
		cout << message::error::use::noValidObject << endl;

	else if (isUsable && isInRoom && !(isInInventory))
		usables_[what]();

	else if (!(isInRoom) && !(isInInventory))
		cout << message::error::notInRoomOrInInventory << endl;

	else if (!(isInInventory) && !(isUsable))
		cout << message::error::notUsable << endl;

	else
		cout << message::error::notUsable_2 << endl;
}

void Game::useBullet()
{
	bool isShotGunInInventory = (inventory_.find(obj::shotgun) != inventory_.cend());
	
	if (isShotGunInInventory)
	{
		isGunLoaded_ = true;
		inventory_.erase(obj::bullet);
		cout << message::usable::bullet::shottyLoaded << endl;
	}
	else
		cout << message::usable::bullet::notUsableInThisContext << endl;
}

void Game::useShoes()
{
	cout << message::usable::shoes << endl;
	death();
}

void Game::useShotgun()
{
	bool isHallway = (map_.getCurrentRoom().getName() == room::hallway);

	if (isGunLoaded_)
	{
		if (isHallway)
		{
			cout << message::usable::shotgun::unleashDivinePower << endl;
			isGunLoaded_ = false;
			map_.openSesame();
			printCurrentRoom();
		}
		else
			cout << message::usable::shotgun::notUsableInThisContext << endl;
	}
	else
		cout << message::usable::shotgun::notLoaded << endl;
}

void Game::useLadder()
{
	bool isAttic    = (map_.getCurrentRoom().getName() == room::attic);
	bool isSBedroom = (map_.getCurrentRoom().getName() == room::smallBedroom);

	if (isAttic)
	{
		cout << message::usable::ladder::down << endl;
		map_.setCurrentRoom(room::smallBedroom);
	}
	else if (isSBedroom)
	{
		cout << message::usable::ladder::up << endl;
		map_.setCurrentRoom(room::attic);
	}
	printCurrentRoom();
}

void Game::useBed()
{
	cout << message::usable::bed << endl;
	death();
}

void Game::useCouch()
{
	cout << message::usable::couch << endl;
	death();
}

void Game::usePencil()
{
	cout << message::usable::pencil << endl;
	death();
}

void Game::useKeySR()
{
	bool isSBedroom = (map_.getCurrentRoom().getName() == room::smallBedroom);

	if (isSBedroom)
	{
		cout << message::usable::keySR::unlockChest  << endl
			 << message::ending::win                 << endl;
		isPlaying_ = false;
	}
	else
		cout << message::usable::keySR::notUsableInThisContext << endl;
}

void Game::useChicken()
{
	cout << message::usable::chicken << endl;
	death();
}

void Game::useTv()
{
	cout << message::usable::tv << endl;
}
