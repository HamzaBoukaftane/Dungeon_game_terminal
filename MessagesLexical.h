/*
* Ce fichier en-tete definit le namespace message pour les differents
* evenements qui occurent dans le jeu. Dans ce namespace sont contenu 
* les messages d'erreurs, les messages de fin et les messages d'utilisation
* des objets.
* fichier : MessagesLexical.h
* auteurs Hamza Boukaftane and Rayan-Atman Ait-Aoudia
* date    16 decembre 2022
* Created 8 decembre 2022
*/

#pragma once
#include <string>

using namespace std;

namespace message
{
	namespace error
	{
		
		const string notInRoomOrInInventory =
			" Where do you see that ? C++ is a hell of a drug!";
	
		const string notTakable             =
			" How could you possibly image put that in your pocket ?\n";
		
		const string notUsable              =
			" How the hell am I suppose to use that !";
	
		const string notUsable_2            =
			" Can not use that.";

		const string cmdNotFirst =
			" You have to write the command first and nothing else!";
		
		const string notValidCmd =
			" I do not understand that command.";
		
		const string notValidDirection      =
			" Can not go there.\n";
		
		namespace take
		{
			const string noValidObject =
				" Can not take unspecified or inexistant object.\n";
		};

		namespace use
		{
			const string noValidObject =
				" Can not use unspecified or inexistant object.";
		};

		namespace look
		{
			const string noValidObject =
				" This object is not in the game or there is too many whitespace after look";
		};

	};

	namespace ending
	{
		const string death =
			"             YOU ARE DEAD!            ";

		const string end   =
			" Thank you for playing the game !!! See you next time !!!";

		const string win   =
			" You have won the game! Congratz and have a nice life!\n";
	};

	namespace usable
	{
		namespace bullet
		{
			const string shottyLoaded           =
				" Shotty is cocked and loaded !!";

			const string notUsableInThisContext =
				"  Nothing to use the bullet with!";
		};

		const string shoes =
			" AHHH! The smell too strong ... I won't make it ...\n";

		namespace shotgun
		{
			const string unleashDivinePower     =
				"  Booom ! What power!\n";

			const string notUsableInThisContext =
				" Hmm! I only have one round. It would not be wise to waste it here";

			const string notLoaded              =
				" To use that I need bullets.";
		};

		namespace ladder
		{
			const string up   =
				" Going up the ladder.\n";

			const string down =
				" Falling down the ladder. Ouch! I am too clumsy.\n";
		};

		const string bed    =
			" You lay on the comfy bed and you remember your ex-wife!!! EMOTIONAL DAMAGE!!!\n";

		const string couch  =
			" You lay on the couch and you think about your INF1015 exam's. PANIC ATTACK!!\n";

		const string pencil =
			" By using this pencil, you were not suppose to eat it. But you did !\n";

		namespace keySR
		{
			const string unlockChest            =
				" \n You have open the chest and found a ton of money ! No need to pursue your Diploma!";

			const string notUsableInThisContext =
				" Can not use that here!";
		};

		const string chicken =
			" Num, Num, Num, Disgusting! Already my stomach hurt ... The pain ...\n";

		const string tv      =
			" There is no remote to control the TV, but you saw an ad about shotgun openeing door.";
	};
};

