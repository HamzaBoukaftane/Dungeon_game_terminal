/*
* Ce fichier en-tete definit le namespace obj pour les objets.
* Dans ce namespace sont contenu des string constante representant
* le nom des differentes objets, ainsi qu'un namespace
* description qui contient string constante representant la
* description des differentes objets et un namespace details
* qui represente les details des differents objet.
* fichier : ObjetLexical.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <string>

using namespace std;

namespace obj
{
	// Entrance
	const string shoes   = "shoes";

	// Living Room
	const string couch   = "couch";
	const string tv      = "tv";
	const string shotgun = "shotgun";

	// Main Hallway
	const string door = "door";

	// Small Bedroom
	const string chest  = "chest";
	const string bed    = "bed";
	const string ladder = "ladder";
	const string money  = "money";

	// Attic
	const string pencil = "pencil";

	// Kitchen
	const string fridge  = "fridge";
	const string sink    = "sink";
	const string bullet  = "bullet";
	const string chicken = "chicken";

	// Secret Room
	const string deadBody = "dead body";
	const string keySR    = "rusted key";

	namespace description
	{
		// Entrance
		const string shoes = "An old pair of black leather man's shoes ";

		// Living Room
		const string couch   = "A broken red velvet couch ";
		const string tv      = "An opened cheap TV playing the Peaky Blinder's series";
		const string shotgun = "A shotgun Remington Model 870";

		// Main Hallway
		const string door = "A closed wooden door to the east";

		// Small Bedroom
		const string chest      = "A solid metallic chest";
		const string bed        = "A comfy looking king size bed ";
		const string ladderUp   = "A ladder going up";
		const string ladderDown = "A ladder going down to the bedroom";

		// Attic
		const string pencil = "A red pencil";

		// Kitchen
		const string fridge  = " A old style yellow fridge ";
		const string sink    = " A nice modern sink ";
		const string bullet  = " One bullet of type Vital-Shok Ammo 12 Gauge 3. Perfect for a shotgun. ";
		const string chicken = " A smelly rotten chicken.";

		// Secret Room
		const string deadBody = " A dead body from which eminates an horrible smell. ";
		const string keySR    = " A bloodied rusted key.";
	};

	namespace details
	{
		// Entrance
		const string shoes = " Pffff, the smells is horrible! There is nothing there.\n";

		// Living Room
		const string couch   = " The base of the couch is broken. It seems a fight erupted here.\n";
		const string tv      = " Kind of a nice show!\n";
		const string shotgun = " A good ol' straithen shotgun of brand Remington Model 870 with Diamond Skin!\n";

		// Main Hallway
		const string door = " Wonder what is behind that door? I got to open it.\n";

		// Small Bedroom
		const string chest  = " Hmmm! The lock is pretty rusted. Must be old.\n";
		const string bed    = " It looks so comfortable!\n";
		const string ladder = " Well, it is a ladder. Nothing special\n";

		// Attic
		const string pencil = " This is a mysterious looking red pencil. It looks eatable ...\n";

		// Kitchen
		const string fridge   = " This fridge could shelter people from a nuclear bomb. Nothing inside\n";
		const string sink     = " It looks like those 3000$ sink from Reno Depot. What a waste of money!\n";
		const string bullet   = " One bullet of type Vital-Shok Ammo 12 Gauge 3. Perfect for a shotgun.\n";
		const string chicken  = " This chicken has a lot of worms and looks unhealthy\n";

		// Secret Room
		const string deadBody   = " Man! He has been dead for a long time. Maybe it is the past owner of the house.\n";
		const string key        = " This must be a special rusted key. Maybe I can use it.\n";
	};

};