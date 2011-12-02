//////////////////////////////////////////////////////////////////////////
//
//	Filename: 	DirectInput.h
//
//	Purpose:	Controls the input system
//
//////////////////////////////////////////////////////////////////////////
#pragma once

//tell directx what version we want...
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "Helpers.h"

#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

class DirectInput
{
private:

	LPDIRECTINPUT8 			m_pDIObject;				//	Direct Input Object.
	LPDIRECTINPUTDEVICE8	m_pDIKey;					//	Direct Input Device for the Keyboard.
	LPDIRECTINPUTDEVICE8	m_pDIMouse;					//	Direct Input Device for the Mouse.

	DIMOUSESTATE2			m_diMouseState;				//holds mouse info
	DWORD					m_dwAxes;					//number of mouse axes
	DWORD					m_dwButtons;				//number of mouse buttons
	char					m_KeyBuffer[256];			//used for keyboard buffering
	char					m_KeyBuffered[256];			//used for keyboard buffering
	char					m_MouseBuffered[8];			//used for buffered mouse input

	static DirectInput *m_pInstance;					//	The instance of this class.

	//Constructor, copy constructor and assignment operator... all in private... ZOMG!!!  
	DirectInput();
	DirectInput(const DirectInput &a){};
	DirectInput &operator=(const DirectInput &a){};

public:

	//	Destructor.
	virtual ~DirectInput(){};

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		DeleteInstance
	//
	//	Purpose:		Delete the instance of the class, and set the pointer to NULL
	//
	//////////////////////////////////////////////////////////////////////////
	static void DeleteInstance();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		GetInstance
	//
	//	Purpose:		Creates the first instance of this class and returns it's address.
	//
	//////////////////////////////////////////////////////////////////////////
	static DirectInput *GetInstance();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Shutdown
	//
	//	Purpose:		Initializes the input class
	//
	//////////////////////////////////////////////////////////////////////////
	void Shutdown(void);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		InitDirectInput
	//
	//	Purpose:		Initializes the input class (keyboard & mouse)
	//
	//////////////////////////////////////////////////////////////////////////
	bool InitDirectInput(HWND hWnd, HINSTANCE hInstance, bool bExclusive);


	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		ReadInput
	//
	//	Purpose:		Initializes the input class
	//
	//////////////////////////////////////////////////////////////////////////
	bool ReadInput(void);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		KeyPressed
	//
	//	Purpose:		Checks to see if that key was pressed
	//
	//////////////////////////////////////////////////////////////////////////
	bool GetKeyPressed(int Key);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		KeyPressed
	//
	//	Purpose:		Checks to see if that key was pressed
	//
	//////////////////////////////////////////////////////////////////////////
	bool GetKeyPressedBuffered(int Key);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		GetMouseButton
	//
	//	Purpose:		Initializes the input class
	//
	//////////////////////////////////////////////////////////////////////////
	bool GetMouseButton(int Button);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		GetMouseButtonBuffered
	//
	//	Purpose:		Initializes the input class
	//
	//////////////////////////////////////////////////////////////////////////
	bool GetMouseButtonBuffered(int Button);

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		GetMouseAxis
	//
	//	Purpose:		Return the value from an axis
	//
	//////////////////////////////////////////////////////////////////////////
	long DirectInput::GetMouseAxis(long lAxis);
};
