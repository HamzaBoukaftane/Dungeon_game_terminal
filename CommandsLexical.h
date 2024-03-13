/*
* Ce fichier en-tete definit le namespace cmd pour les commandes.
* Dans ce namespace sont contenu des string constante representant
* le nom des differentes commandes du jeu.
* fichier : CommandsLexical.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <string>

using namespace std;

namespace cmd
{
	const string goN  = "N";
	const string goS  = "S";
	const string goE  = "E";
	const string goW  = "W";
	const string end  = "exit";
	const string hlp  = "help";
	const string look = "look";
	const string use  = "use";
	const string take = "take";
};
