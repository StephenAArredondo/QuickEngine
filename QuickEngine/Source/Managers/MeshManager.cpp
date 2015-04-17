#include <Common.h>
#include "MeshManager.h"
#include "..\Utilities\Mesh.h"

MeshManager* MeshManager::GetInstance()
{
	static MeshManager pInstance;
	return &pInstance;
}

MeshManager::MeshManager()
{
	m_vMeshes.clear();
	m_bInitialized = false;
	strMeshDir = "..\\..\\Assets\\Meshes\\";
}

MeshManager::~MeshManager()
{
	if(m_bInitialized)
		Shutdown();
}

void MeshManager::Initialize()
{
	m_vMeshes.clear();

	//   	if(LoadMesh("Cube.mesh", strMeshDir) == INVALID_RESOURCE_ID)
	// 	 		CreateMesh();

	m_bInitialized = true;
}

void MeshManager::Shutdown()
{
	std::map<unsigned int, Mesh*>::iterator pIter = m_vMeshes.begin();

	while(pIter != m_vMeshes.end())
	{
		delete pIter->second;
		pIter->second = NULL;

		++pIter;
	}

	m_vMeshes.clear();
	m_bInitialized = false;
}

Mesh* MeshManager::GetMesh(unsigned int _uiMeshID)
{
	std::map<unsigned int, Mesh*>::iterator pIter = m_vMeshes.find(_uiMeshID);

	if(pIter != m_vMeshes.end())
		return pIter->second;

	return m_vMeshes[0];
}

Mesh* MeshManager::GetMesh(std::string _strMeshName, bool _bLoadIsNotFound)
{
	unsigned int uiID =  0;

	if(_bLoadIsNotFound)
		uiID = LoadMesh(_strMeshName);
	else
		uiID = FindMeshByName(_strMeshName);

	return m_vMeshes[uiID];
}

unsigned int MeshManager::LoadMesh(std::string _szFileName)
{
	unsigned int uiUniqueID = FindMeshByName(_szFileName);

	if(uiUniqueID != INVALID_RESOURCE_ID && uiUniqueID != 0)
		return uiUniqueID;

	Mesh* pNewMesh = new Mesh();
	if(!pNewMesh->LoadMesh(strMeshDir + _szFileName))
	{
		delete pNewMesh;
		return (m_bDefaultLoaded) ? 0 : INVALID_RESOURCE_ID;
	}

	std::map<unsigned int, Mesh*>::iterator pIter = m_vMeshes.begin();
	while(pIter != m_vMeshes.end())
	{
		if(pIter->first != uiUniqueID)
			break;

		++uiUniqueID;
		++pIter;
	}

	pNewMesh->SetUniqueID(uiUniqueID);
	pNewMesh->AddRef();
	m_vMeshes[uiUniqueID] = pNewMesh;

	return uiUniqueID;
}

unsigned int MeshManager::CreateMesh()
{
	return 0;
}

unsigned int MeshManager::FindMeshByName(std::string _strMeshName)
{
	std::map<unsigned int, Mesh*>::iterator pIter = m_vMeshes.begin();

	while(pIter != m_vMeshes.end())
	{
		if(pIter->second->GetMeshName() == _strMeshName)
		{
			pIter->second->AddRef();
			return pIter->first;
		}

		++pIter;
	}

	return (m_bDefaultLoaded) ? 0 : INVALID_RESOURCE_ID;
}