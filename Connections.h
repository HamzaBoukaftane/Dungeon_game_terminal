/*
* Ce fichier en-tete definit la classe connection
* qui encapsule une liste des connections possible
* qui permet de manipuler les differentes connections 
* en fonction des cardinaux et le namespace dir pour 
* les directions connection entre piece
* fichier : Connection.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    12 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <unordered_map>
#include <string>
#include "RoomLexical.h"

using namespace std;

namespace dir
{
	const string N = "North";
	const string S = "South";
	const string E = "East";
	const string W = "West";
};

class Connections
{

	using ListeConnections = unordered_map<string, string>;

public:
	
	Connections() = default;
	~Connections() = default;

	const ListeConnections& getListConnections() const { return connections_;}
	
	void setConnectionsNorth(const string& roomName) { connections_[dir::N] = roomName; }
	void setConnectionsSouth(const string& roomName) { connections_[dir::S] = roomName; }
	void setConnectionsEast (const string& roomName) { connections_[dir::E] = roomName; }
	void setConnectionsWest (const string& roomName) { connections_[dir::W] = roomName; }
 
private:
	
	ListeConnections connections_
	{
		{dir::N, room::nothing },
		{dir::S, room::nothing },
		{dir::E, room::nothing },
		{dir::W, room::nothing }
	};
};
