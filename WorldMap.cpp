/*
* Ce fichier definit l'implementation de la 
* methode SetUp map qui initialise la liste
* des differentes pieces de la maison.
* fichier : WorldMap.cpp
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    12 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "WorldMap.h"

void WorldMap::setUpMap()
{
	rooms_ =
	{
		{room::entrance    , make_unique<Entrance>()    },
		{room::livingRoom  , make_unique<LivingRoom>()  },
		{room::hallway     , make_unique<Hallway>()     },
		{room::smallBedroom, make_unique<SmallBedroom>()},
		{room::kitchen     , make_unique<Kitchen>()     },
		{room::attic       , make_unique<Attic>()       },
		{room::secretRoom  , make_unique<SecretRoom>()  }
	};

	beginRoom_   = rooms_[room::entrance];
	currentRoom_ = rooms_[room::entrance];
}