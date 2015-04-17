#ifndef __MESH_MANAGER_H__
#define __MESH_MANAGER_H__

#include "BaseManager.h"

class Mesh;

class MeshManager : public BaseManager
{
private:

	std::string strMeshDir;

	std::map<unsigned int, Mesh*> m_vMeshes;
	bool m_bDefaultLoaded;

	MeshManager();
	~MeshManager();
	MeshManager(const MeshManager&){}
	MeshManager* operator=(const MeshManager&){}

	unsigned int FindMeshByName(std::string _strMeshName);

public:

	void Initialize();
	void Shutdown();

	Mesh* GetMesh(unsigned int _uiMeshID);
	Mesh* GetMesh(std::string _strMeshName, bool _bLoadIfNotFound = 0);
	unsigned int LoadMesh(std::string _szFileName);
	unsigned int CreateMesh();

	static MeshManager* GetInstance();

};

/*
if (Event.Key.Code == sf::Key::F1)
{
sf::Image Screen = App.Capture();
Screen.SaveToFile("screenshot.jpg");
}
*/

#endif//__MESH_MANAGER_H__