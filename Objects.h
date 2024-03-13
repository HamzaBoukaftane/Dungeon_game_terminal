/*
* Ce fichier en-tete definit divers classe heritant
* de la classe de base objet.
* fichier : Object.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "ObjectAbs.h"

class Door : public ObjectAbs
{
public:

	Door()
	: ObjectAbs(obj::door, obj::description::door,obj::details::door) {}
	~Door() = default;

	virtual bool isTakable() const override { return false; }
};

class Bed : public ObjectAbs
{
public:

	Bed()
	: ObjectAbs(obj::bed, obj::description::bed, obj::details::bed) {}
	~Bed() = default;

	virtual bool isTakable() const override { return false; }
};

class Ladder : public ObjectAbs
{
public:

	Ladder(const string dirL)
	: ObjectAbs(obj::ladder, dirL, obj::details::ladder) {}
	~Ladder() = default;

	virtual bool isTakable() const override { return false; }
};

class Tv : public ObjectAbs
{
public:

	Tv()
	: ObjectAbs(obj::tv, obj::description::tv, obj::details::tv) {}
	~Tv() = default;

	virtual bool isTakable() const override { return false; }
};

class Shoes: public ObjectAbs
{
public:
	
	Shoes()
	: ObjectAbs(obj::shoes, obj::description::shoes, obj::details::shoes){}
	~Shoes() = default;

	virtual bool isTakable() const override { return true; }
};

class Pencil : public ObjectAbs
{
public:

	Pencil()
	: ObjectAbs(obj::pencil, obj::description::pencil, obj::details::pencil) {}
	~Pencil() = default;

	virtual bool isTakable() const override { return true; }
};

class KeySR : public ObjectAbs
{
public:

	KeySR()
	: ObjectAbs(obj::keySR, obj::description::keySR, obj::details::key) {}
	~KeySR() = default;

	virtual bool isTakable() const override { return true; }
};

class Chicken : public ObjectAbs
{
public:

	Chicken()
	: ObjectAbs(obj::chicken, obj::description::chicken, obj::details::chicken) {}
	~Chicken() = default;

	virtual bool isTakable() const override { return true; }
};

class Bullet : public ObjectAbs
{
public:

	Bullet()
	: ObjectAbs(obj::bullet, obj::description::bullet, obj::details::bullet) {}
	~Bullet() = default;

	virtual bool isTakable() const override { return true; }
};

class Shotgun : public ObjectAbs
{
public:

	Shotgun()
	: ObjectAbs(obj::shotgun, obj::description::shotgun, obj::details::shotgun) {}
	~Shotgun() = default;

	virtual bool isTakable() const override { return true; }
};

class Couch : public ObjectAbs
{
public:

	Couch()
	: ObjectAbs(obj::couch, obj::description::couch, obj::details::couch) {}
	~Couch() = default;

	virtual bool isTakable() const override { return false; }
};

class Chest : public ObjectAbs
{
public:

	Chest()
	: ObjectAbs(obj::chest, obj::description::chest, obj::details::chest) { }
	~Chest() = default;
	
	virtual bool isTakable() const override { return false; }
};

class Fridge : public ObjectAbs
{
public:

	Fridge()
	: ObjectAbs(obj::fridge, obj::description::fridge, obj::details::fridge) {}
	~Fridge() = default;

	virtual bool isTakable() const override { return false; }
};

class DeadBody : public ObjectAbs
{
public:

	DeadBody()
	: ObjectAbs(obj::deadBody, obj::description::deadBody, obj::details::deadBody) {}
	~DeadBody() = default;

	virtual bool isTakable() const override { return false; }
};

class Sink : public ObjectAbs
{
public:

	Sink()
	: ObjectAbs(obj::sink, obj::description::sink, obj::details::sink) {}
	~Sink() = default;

	virtual bool isTakable() const override { return false; }
};

