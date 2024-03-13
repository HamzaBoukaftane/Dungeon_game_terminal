/*
* Ce fichier en-tete definit la classe abstraite
* RoomAbs dont herite les autres pieces concretes.
* fichier : RoomAbs.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <iostream>
#include "Connections.h"
#include "Objects.h"

using namespace std;


class RoomAbs
{
	
	using ConnectionsPtr = unique_ptr<Connections>;
	using ObjectPtr      = shared_ptr<ObjectAbs>;
	using ListObjects    = unordered_map<string, ObjectPtr>;

public:
	
	RoomAbs(const string& name, const string& description)
		: name_(name), description_(description)
	{
		adjacentRooms_ = make_unique<Connections>();
	}
	
	virtual ~RoomAbs() = default;

	const ConnectionsPtr& getAdjacetRooms() const { return adjacentRooms_; }
	const ListObjects&    getListObjects()  const { return objects_; }
	const string&         getName()         const { return name_; }

	void printToStream() const;
	void printObjects() const;
	
	void removeItem(const string& what) { objects_.erase(what); }

	void forceConnection()
	{
		adjacentRooms_->setConnectionsEast(room::secretRoom);
	}

protected:

	const string& getDescription()  const { return description_; }

	virtual void setConnections() = 0;

	ConnectionsPtr adjacentRooms_;
	ListObjects    objects_;

private:
	
	string name_;
	string description_;

};



