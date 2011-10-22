//////////////////////////////////////////////////////////////////////////
//
//	Filename: 	InputInterp.cpp
//
//	Purpose:	Controls all the players in the game
//
//////////////////////////////////////////////////////////////////////////
#include "InputInterp.h"

//initialize the static variable member(s)
InputInterp *InputInterp::m_pInstance = NULL;

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		DeleteInstance
//
//	Purpose:		Delete the instance of the class, and set the pointer to NULL
//
//////////////////////////////////////////////////////////////////////////
void InputInterp::DeleteInstance()
{
	SAFE_DELETE(m_pInstance);

	COUT << "InputInterp::DeleteInstance() - SUCCESS" << endl; 
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		GetInstance
//
//	Purpose:		Creates the first instance of this class and returns it's address.
//
//////////////////////////////////////////////////////////////////////////
InputInterp *InputInterp::GetInstance()
{
	if(!m_pInstance)
	{
		m_pInstance = new InputInterp;
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
void InputInterp::Init(HWND hWnd, HINSTANCE hInstance)
{
	m_pDirectInput = DirectInput::GetInstance();
	m_pDirectInput->InitDirectInput(hWnd, hInstance, true);
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		Update
//
//	Purpose:		called every frame to check for inputs 
//
//////////////////////////////////////////////////////////////////////////
void InputInterp::Update()
{
	m_pDirectInput->ReadInput();

	// get current game state m_pGameState->GetState();

	//all the different game states
	switch(1)
	{
		//main game world 1st person
	case 1: 
		{
			m_vPlayers[tempPlayerPacket.nPlayer].d3dPosition.z += tempPlayerPacket.fValue;
			break;
		}
	default :
		{
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		MainGameFirstPerson
//
//	Purpose:		input update for the main game state 
//
//////////////////////////////////////////////////////////////////////////
void InputInterp::MainGameFirstPerson()
{
}