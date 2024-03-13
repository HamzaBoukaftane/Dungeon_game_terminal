/*
* Ce fichier definit les methoded des RoomAbs
* fichier : RoomAbs.cpp
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    12 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "RoomAbs.h"

void RoomAbs::printToStream() const
{
	cout << " --" << getName() << " --" << endl
		 << getDescription() << endl;
	
	for (const auto& [dir, room] : getAdjacetRooms()->getListConnections())
	{
		bool isAdjacent = (room != room::nothing);

		if (isAdjacent)
		{
			cout << " " << room << " is to the " << dir << ". (" << dir[0] << ")" << endl;
		}
	}
	printObjects();
}

void RoomAbs::printObjects() const
{
	bool isAtLeastOneObj = (objects_.size() != NULL);

	if (isAtLeastOneObj)
	{
		cout << " You notice:  " << endl;
		
		for (auto& [name, obj] : objects_)
			cout << "\t" << obj->getDescription() << endl;
	}
}