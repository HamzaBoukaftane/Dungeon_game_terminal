/*
* Ce fichier en-tete definit le namespace room. Dans 
* ce namespace sont contenu des string constante representant
* le nom des differentes piece de la maison, ainsi qu'un namespace
* description qui contient string constante representant la
* description des differentes pieces.
* fichier : RoomLexical.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <string>

using namespace std;

namespace room
{
	const string entrance     = "Foyer";
	const string livingRoom   = "Living room";
	const string hallway      = "Main hallway";
	const string smallBedroom = "Small bedroom";
	const string kitchen      = "Kitchen";
	const string attic        = "Attic";
	const string secretRoom   = "Secret Room";
	const string nothing      = "n/a";

	namespace description
	{
		const string entrance =
			" This the entrance of the house. There is a sturdy carpet on the floor but nothing else.";
		const string livingRoom =
			" This is the living room of the house. Woah!!! What a mess! There is a broken couch and the TV still on! ";
		const string hallway =
			" This is the main hallway of the house. It is very dark and quite creepy. There is no light bulb.";
		const string smallBedroom =
			" This is the small bedroom of the house. It is a very well organized room and very clean. There is no window.";
		const string kitchen =
			" This is the kitchen. It is very dirty with a lot of dust, but at least there is a window and some light passes though ...";
		const string attic =
			" This is the attic of the house. Holy **** ! There is a lot of spiders !!!";
		const string secretRoom =
			" Wooow! This is a secret room of the house. There is no windows and the walls are filled with blood. Wonder what happened here?";
	};
};