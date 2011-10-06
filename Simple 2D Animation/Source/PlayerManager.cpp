//////////////////////////////////////////////////////////////////////////
//
//	Filename: 	PlayerManager.cpp
//
//	Purpose:	Controls all the players in the game
//
//////////////////////////////////////////////////////////////////////////
#include "PlayerManager.h"

//initialize the static variable member(s)
PlayerManager *PlayerManager::m_pInstance = NULL;

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		DeleteInstance
//
//	Purpose:		Delete the instance of the class, and set the pointer to NULL
//
//////////////////////////////////////////////////////////////////////////
void PlayerManager::DeleteInstance()
{
	SAFE_DELETE(m_pInstance);

	COUT << "PlayerManager::DeleteInstance() - SUCCESS" << endl; 
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		GetInstance
//
//	Purpose:		Creates the first instance of this class and returns it's address.
//
//////////////////////////////////////////////////////////////////////////
PlayerManager *PlayerManager::GetInstance()
{
	if(!m_pInstance)
	{
		m_pInstance = new PlayerManager;
	}

	return m_pInstance;
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		Init
//
//	Purpose:		Initializes the player manager
//
//////////////////////////////////////////////////////////////////////////
bool PlayerManager::Init()
{
	//zero out the player struct
	memset(&m_player, 0, sizeof(Player));

	return true;
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		Update
//
//	Purpose:		General update for the player.
//					This will branch out into all the different ways a 
//					player can be updated.
//
//////////////////////////////////////////////////////////////////////////
void PlayerManager::Update()
{
	//////////////////////////////////////////////////////////////////////////
	//keyboard update


	//////////////////////////////////////////////////////////////////////////
	//mouse update


	//////////////////////////////////////////////////////////////////////////
	//self actions


	//////////////////////////////////////////////////////////////////////////
	//non self actions


	//////////////////////////////////////////////////////////////////////////
	//network

}