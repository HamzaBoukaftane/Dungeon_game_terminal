/*
* Ce fichier en-tete definit la classe WorldMap. Cette
* derniere encapsule une liste des differentes piece de
* la maison, la piece de depart et la piece actuelle.
* fichier : WorldMap.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    12 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "Rooms.h"
#include <iostream>
#include <unordered_map>

class WorldMap
{
	
	using RoomPtr   = shared_ptr<RoomAbs>;
	using ListRooms = unordered_map<string,RoomPtr>;

public:

	WorldMap() { setUpMap(); }
	~WorldMap() = default;
	
	const ListRooms&    getRooms()       const { return rooms_; }
	const RoomAbs&      getCurrentRoom() const { return *currentRoom_; }
	const RoomAbs&      getBeginning()   const { return *beginRoom_; }
	
	void removeObjectFromRoom(const string& what) { currentRoom_->removeItem(what); }

	void setCurrentRoom(const string& roomName)
	{
		currentRoom_.reset();
		currentRoom_ = rooms_[roomName];
	}

	void openSesame() { currentRoom_->forceConnection(); }

protected:
	
	void setUpMap();

private:

	RoomPtr   beginRoom_;
	RoomPtr   currentRoom_;
	ListRooms rooms_;

};
