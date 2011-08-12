//////////////////////////////////////////////////////////////////////////
//
//	Filename: 	VoxelManager.cpp
//
//	Author:		Nicholas Legg
//
//	Purpose:	high frequency timer
//
//////////////////////////////////////////////////////////////////////////
#include "VoxelManager.h"

//initialize the static variable member(s)
VoxelManager *VoxelManager::m_pInstance = NULL;

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		DeleteInstance
//
//	Last Modified: 	07/08/2006
//
//	Purpose:		Delete the instance of the class, and set the pointer to NULL
//
//////////////////////////////////////////////////////////////////////////
void VoxelManager::DeleteInstance()
{
	SAFE_DELETE(m_pInstance);

	COUT << "VoxelManager::DeleteInstance() - SUCCESS" << endl; 
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		GetInstance
//
//	Last Modified: 	07/08/2006
//
//	Purpose:		Creates the first instance of this class and returns it's address.
//
//////////////////////////////////////////////////////////////////////////
VoxelManager *VoxelManager::GetInstance()
{
	if(!m_pInstance)
		m_pInstance = new VoxelManager;

	return m_pInstance;
}

//////////////////////////////////////////////////////////////////////////
// 
//	Function: 		InitTimer
//
//	Last Modified: 	2006/01/15
//
//	Purpose:		Initializes the frequency and counter
//
//////////////////////////////////////////////////////////////////////////
void VoxelManager::Init()
{

}