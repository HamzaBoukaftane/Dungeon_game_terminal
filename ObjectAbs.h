/*
* Ce fichier en-tete definit la classe abstraite ObjectAbs
* dont herite les divers objets contenues dans le jeu
* fichier : ObjectAbs.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include "ObjectLexical.h"
#include <iostream>

class ObjectAbs
{

public:

	ObjectAbs(const string& name, const string& description, const string& details)
	: name_(name), description_(description), details_(details) {}
	
	virtual ~ObjectAbs() = default;

	const string&       getName()          const { return name_; }
	const string&       getDescription()   const { return description_; }

	void printDetails() { cout << details_; }

	virtual bool isTakable() const = 0;

private:

	string details_;
	string name_;
	string description_;
};