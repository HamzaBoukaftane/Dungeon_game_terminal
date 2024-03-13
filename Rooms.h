/*
* Ce fichier en-tete definit les classes differentes
* concretes heritant de RoomAbs.
* fichier : Rooms.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "RoomAbs.h"

class Attic : public RoomAbs
{
public:

	Attic()
	: RoomAbs(room::attic, room::description::attic)
	{
		objects_ =
		{
			{obj::ladder  , make_unique<Ladder>(obj::description::ladderDown)  },
			{obj::pencil  , make_unique<Pencil>()                              }
		};
	}
	~Attic() = default;

protected:

	virtual void setConnections() override {}

};

class Entrance : public RoomAbs
{
public:

	Entrance()
	: RoomAbs(room::entrance, room::description::entrance)
	{
		setConnections();
		objects_ = { {obj::shoes, make_unique<Shoes>()} };
	}
	~Entrance() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsNorth(room::hallway);
		adjacentRooms_->setConnectionsEast(room::livingRoom);
	}
};

class Hallway : public RoomAbs
{
public:

	Hallway()
	: RoomAbs(room::hallway, room::description::hallway)
	{
		setConnections();
		objects_ = { {obj::door, make_unique<Door>()} };
	}
	~Hallway() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsNorth(room::kitchen);
		adjacentRooms_->setConnectionsWest(room::smallBedroom);
		adjacentRooms_->setConnectionsSouth(room::entrance);
	}
};

class Kitchen : public RoomAbs
{
public:

	Kitchen()
	: RoomAbs(room::kitchen, room::description::kitchen)
	{
		setConnections();
		objects_ =
		{
			{obj::fridge , make_unique<Fridge>() },
			{obj::sink   , make_unique<Sink>()   },
			{obj::chicken, make_unique<Chicken>()},
			{obj::bullet,  make_unique<Bullet>() }
		};
	}
	~Kitchen() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsSouth(room::hallway);
	}
};

class LivingRoom : public RoomAbs
{
public:

	LivingRoom()
	: RoomAbs(room::livingRoom, room::description::livingRoom)
	{
		setConnections();
		objects_ =
		{
			{obj::couch  , make_unique<Couch>()  },
			{obj::tv     , make_unique<Tv>()     },
			{obj::shotgun, make_unique<Shotgun>()}
		};
	}
	~LivingRoom() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsWest(room::entrance);
	}
};

class SecretRoom : public RoomAbs
{
public:

	SecretRoom()
	: RoomAbs(room::secretRoom, room::description::secretRoom)
	{
		setConnections();
		objects_ =
		{
			{obj::deadBody, make_unique<DeadBody>()},
			{obj::keySR   , make_unique<KeySR>()   }
		};
	}
	~SecretRoom() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsWest(room::hallway);
	}
};

class SmallBedroom : public RoomAbs
{
public:

	SmallBedroom()
	: RoomAbs(room::smallBedroom, room::description::smallBedroom)
	{
		setConnections();
		objects_ =
		{
			{obj::ladder, make_unique<Ladder>(obj::description::ladderUp)},
			{obj::chest , make_unique<Chest>()                           },
			{obj::bed   , make_unique<Bed>()                             }
		};
	}
	~SmallBedroom() = default;

protected:

	virtual void setConnections() override
	{
		adjacentRooms_->setConnectionsEast(room::hallway);
	}
};