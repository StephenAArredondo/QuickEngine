#ifndef __MESH_H__
#define __MESH_H__

#include <string>

class Mesh
{
private:

	std::string m_strName;
	std::string m_strPathName;

	unsigned int m_uiUniqueID;

	unsigned int m_uiReferenceCount;

	std::vector<QVector3> m_vVertices;
	std::vector<QVector3> m_vNormals;
	std::vector<QVector4> m_vTangents;

	std::vector<QVector2> m_vUV1;
	std::vector<QVector2> m_vUV2;

	std::vector<QVector4> m_vColors;
	std::vector<QVector3> m_vTriangles;

	int m_nNumVertices;
	int m_nNumTriangles;
	int m_nNumUV1s;
	int m_nNumUV2s;
	int m_nNumTangents;
	int m_nNumColors;
	int m_nNumNormals;

	bool Load3DS(std::string strFile);
	bool LoadObj(std::string strFile);

	bool m_bLoaded;

public:

	friend class MeshManager;

	Mesh(void);
	~Mesh(void);

	bool LoadMesh(std::string strFile);

	bool HasVertices() { return (m_nNumVertices > 0); }
	bool HasNormals() { return (m_nNumNormals > 0); }
	bool HasTangents() { return (m_nNumTangents > 0); }
	bool HasUV1s() { return (m_nNumUV1s > 0); }
	bool HasUV2s() { return (m_nNumUV2s > 0); }
	bool HasColors() { return (m_nNumColors > 0); }
	bool HasTriangles() { return (m_nNumTriangles > 0); }

	inline int GetNumVertices() { return m_nNumVertices; }
	inline int GetNumTriangles() { return m_nNumTriangles; }
	inline int GetNumUV1s() { return m_nNumUV1s; }
	inline int GetNumUV2s() { return m_nNumUV2s; }
	inline int GetNumTangents() { return m_nNumTangents; }

	inline std::vector<QVector3>& GetVertices() { return m_vVertices;}
	inline std::vector<QVector3>& GetNormals() { return m_vNormals;}
	inline std::vector<QVector4>& GetTangents() { return m_vTangents;}
	inline std::vector<QVector2>& GetUV1s() { return m_vUV1;}
	inline std::vector<QVector2>& GetUV2s() { return m_vUV2;}
	inline std::vector<QVector4>& GetColors() { return m_vColors;}
	inline std::vector<QVector3>& GetTriangles() { return m_vTriangles;}

	QVector3& GetVert(unsigned int _uiIndex);
	QVector3& GetNormal(unsigned int _uiIndex);
	QVector4& GetTangent(unsigned int _uiIndex);
	QVector2& GetUV1(unsigned int _uiIndex);
	QVector2& GetUV2(unsigned int _uiIndex);
	QVector4& GetColor(unsigned int _uiIndex);
	QVector3& GetTriangle(unsigned int _uiIndex);

	inline std::string GetMeshName() { return m_strName; }

	inline void AddRef() { m_uiReferenceCount++; }
	inline bool RemoveRef() { return ((--m_uiReferenceCount) == 0) ? true : false; }
	void SetUniqueID(unsigned int _uiUniqueID) { m_uiUniqueID = _uiUniqueID; }
};

#endif