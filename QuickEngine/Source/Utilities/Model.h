#ifndef __MODEL_H__
#define __MODEL_H__

#include <Common.h>
#include "Mesh.h"

class Model
{
private:

	Mesh* m_pMesh;
	QVector4 m_m4OriginalPosition;
	QVector4 m_m4ModifiedPosition;

	QVector3 m_v3Translation;
	QVector3 m_v3Rotation;
	QVector3 m_v3Scale;

	bool m_bMatrixModified;


public:

	Model();
	~Model();

	const Mesh* GetMesh() { return m_pMesh; }
	const QVector4* GetMatrix() { return (m_bMatrixModified) ? &m_m4ModifiedPosition : &m_m4OriginalPosition; }
	QVector3 GetTranslation() { return m_v3Translation; }
	QVector3 GetRotation() { return m_v3Rotation; }
	QVector3 GetScale() { return m_v3Scale; }

	// 	void Draw();
	// 
	// 	void ResetMatrix();
	// 	
	// 	void Translate();
	// 	void Rotate();
	// 	void Scale();
};

#endif