//////////////////////////////////////////////////////////////////////////
//
//	Filename: 	WorldGod.h
//
//	Purpose:	controls the loading and unloading of the world based
//				on the location of the player
//
//////////////////////////////////////////////////////////////////////////
#pragma once
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include "Helpers.h"
#include "Timer.h"
#include "Camera.h"
#include "BlockObject.h"
#include <vector>
#include <list>
using std::vector;
using std::list;

#define BLOCKARRAY_SIZE 8

struct CACHE_ALIGN WorldChunk2
{
	BlockObject				BlockArray[BLOCKARRAY_SIZE][BLOCKARRAY_SIZE][BLOCKARRAY_SIZE];
	list<BlockObject*>		VisibleArray;
	D3DXVECTOR3				d3dHigh;		//high values of the bounding
	D3DXVECTOR3				d3dLow;			//low values of the bounding
};

class CACHE_ALIGN WorldGod  
{
private:

	CCamera			*m_pCamera;
	Timer			*m_pTimer;
	int timernick;

	static	WorldGod *m_pInstance;			//instance to the singleton	

	WorldGod(){};
	WorldGod(const WorldGod &a){};
	WorldGod &operator=(const WorldGod &a){};

public:

	//	~WorldGod: Destructor
	~WorldGod(){};

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
	static WorldGod *GetInstance();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		InitTimer
	//
	//	Purpose:		Initializes the frequency and counter
	//
	//////////////////////////////////////////////////////////////////////////
	void Init();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Shutdown
	//
	//	Purpose:		does any needed shutdown operations
	//
	//////////////////////////////////////////////////////////////////////////
	void Shutdown();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Update
	//
	//	Purpose:		Updates the general counter
	//
	//////////////////////////////////////////////////////////////////////////
	bool Update();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Check
	//
	//	Purpose:		check if anything is needed to be loaded or unloaded
	//
	//////////////////////////////////////////////////////////////////////////
	void Check();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Load
	//
	//	Purpose:		check if anything is needed to be loaded or unloaded
	//
	//////////////////////////////////////////////////////////////////////////
	void Load();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Unload
	//
	//	Purpose:		check if anything is needed to be loaded or unloaded
	//
	//////////////////////////////////////////////////////////////////////////
	void Unload();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Save
	//
	//	Purpose:		check if anything is needed to be loaded or unloaded
	//
	//////////////////////////////////////////////////////////////////////////
	void Save();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Cull
	//
	//	Purpose:		check if anything is needed to be loaded or unloaded
	//
	//////////////////////////////////////////////////////////////////////////
	void Cull();

	//////////////////////////////////////////////////////////////////////////
	// 
	//	Function: 		Generate
	//
	//	Purpose:		we don't have an terrain around the player it needs to 
	//					be generated
	//
	//////////////////////////////////////////////////////////////////////////
	void Generate();
};