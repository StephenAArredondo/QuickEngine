#include <Common.h>
#include "Mesh.h"
#include <io.h>

Mesh::Mesh(void)
{
	m_strName.resize(20);

	m_nNumVertices = 0;
	m_nNumTriangles = 0;

	m_vVertices.clear();
	m_vNormals.clear();
	m_vTangents.clear();
	m_vUV1.clear();
	m_vUV2.clear();
	m_vColors.clear();
	m_vTriangles.clear();

	m_bLoaded = false;
}

Mesh::~Mesh(void)
{

}

QVector3& Mesh::GetVert(unsigned int _uiIndex) { return m_vVertices[_uiIndex];}
QVector3& Mesh::GetNormal(unsigned int _uiIndex) { return m_vNormals[_uiIndex];}
QVector4& Mesh::GetTangent(unsigned int _uiIndex) { return m_vTangents[_uiIndex];}
QVector2& Mesh::GetUV1(unsigned int _uiIndex) { return m_vUV1[_uiIndex];}
QVector2& Mesh::GetUV2(unsigned int _uiIndex) { return m_vUV2[_uiIndex];}
QVector4& Mesh::GetColor(unsigned int _uiIndex) { return m_vColors[_uiIndex];}
QVector3& Mesh::GetTriangle(unsigned int _uiIndex) { return m_vTriangles[_uiIndex];}

bool Mesh::LoadMesh(std::string strFile)
{
	// Make sure the length is greater than 
	// the smallest possible extension size (.x)
	if((std::strlen(strFile.c_str()) >= 2) == false)
		return false;

	int nIndex = strFile.find_last_of(".");

	// Check if there is an extension type
	if(nIndex == -1)
		return false;

	std::string strExtension = strFile.substr(nIndex + 1);

	if("3ds" == strExtension)
	{
		m_bLoaded = Load3DS(strFile);
	}
	else if("obj" == strExtension)
	{
		m_bLoaded = LoadObj(strFile);
	}

	return m_bLoaded;
}

bool Mesh::Load3DS(std::string strFile)
{
	int i; //Index variable

	FILE* l_file; //File pointer

	unsigned short l_chunk_id; //Chunk identifier
	unsigned int l_chunk_lenght; //Chunk length

	unsigned char l_char; //Char variable
	unsigned short l_qty; //Number of elements in each chunk

	unsigned short l_face_flags; //Flag that stores some face information

	fopen_s(&l_file, strFile.c_str(), "rb");

	if(l_file == NULL)
		return 0; //Open the file

	while (ftell(l_file) < _filelength(_fileno(l_file))) //Loop to scan the whole file 
	{
		//getche(); //Insert this command for debug (to wait for keypress for each chuck reading)

		fread (&l_chunk_id, 2, 1, l_file); //Read the chunk header
		fread (&l_chunk_lenght, 4, 1, l_file); //Read the length of the chunk

		switch (l_chunk_id)
		{
			//----------------- MAIN3DS -----------------
			// Description: Main chunk, contains all the other chunks
			// Chunk ID: 4d4d 
			// Chunk Length: 0 + sub chunks
			//-------------------------------------------
		case 0x4d4d: 
			break;    

			//----------------- EDIT3DS -----------------
			// Description: 3D Editor chunk, objects layout info 
			// Chunk ID: 3d3d (hex)
			// Chunk Length: 0 + sub chunks
			//-------------------------------------------
		case 0x3d3d:
			break;

			//--------------- EDIT_OBJECT ---------------
			// Description: Object block, info for each object
			// Chunk ID: 4000 (hex)
			// Chunk Length: len(object name) + sub chunks
			//-------------------------------------------
		case 0x4000: 
			{
				i = 0;

				do
				{

					fread (&l_char, 1, 1, l_file);
					m_strName[i] = l_char;
					++i;

				}while(l_char != '\0' && i < 20);

				break;
			}

			//--------------- OBJ_TRIMESH ---------------
			// Description: Triangular mesh, contains chunks for 3d mesh info
			// Chunk ID: 4100 (hex)
			// Chunk Length: 0 + sub chunks
			//-------------------------------------------
		case 0x4100:
			{
				break;
			}

			//--------------- TRI_VERTEXL ---------------
			// Description: Vertices list
			// Chunk ID: 4110 (hex)
			// Chunk Length: 1 x unsigned short (number of vertices) 
			//             + 3 x float (vertex coordinates) x (number of vertices)
			//             + sub chunks
			//-------------------------------------------
		case 0x4110: 
			{
				fread (&l_qty, sizeof (unsigned short), 1, l_file);

				m_nNumVertices = l_qty;

				m_vVertices.resize(m_nNumVertices);

				float fTemp = 0.0f;

				for (i = 0; i < l_qty; ++i)
				{
					fTemp = 0.0f;

					fread (&fTemp, sizeof(float), 1, l_file);
					m_vVertices[i].x = fTemp;

					fread (&fTemp, sizeof(float), 1, l_file);
					m_vVertices[i].y = fTemp;

					fread (&fTemp, sizeof(float), 1, l_file);
					m_vVertices[i].z = fTemp;
				}
				break;
			}

			//--------------- TRI_FACEL1 ----------------
			// Description: Polygons (faces) list
			// Chunk ID: 4120 (hex)
			// Chunk Length: 1 x unsigned short (number of polygons) 
			//             + 3 x unsigned short (polygon points) x (number of polygons)
			//             + sub chunks
			//-------------------------------------------
		case 0x4120:
			{
				fread (&l_qty, sizeof (unsigned short), 1, l_file);

				m_nNumTriangles = l_qty;

				m_vTriangles.resize(m_nNumTriangles);

				unsigned short nTemp = 0;

				for (i = 0; i < l_qty; ++i)
				{
					nTemp = 0;

					fread (&nTemp, sizeof (unsigned short), 1, l_file);
					m_vTriangles[i].x = (float)nTemp;

					fread (&nTemp, sizeof (unsigned short), 1, l_file);
					m_vTriangles[i].y = (float)nTemp;				

					fread (&nTemp, sizeof (unsigned short), 1, l_file);
					m_vTriangles[i].z = (float)nTemp;				

					fread (&l_face_flags, sizeof (unsigned short), 1, l_file);
				}
				break;
			}

			//------------- TRI_MAPPINGCOORS ------------
			// Description: Vertices list
			// Chunk ID: 4140 (hex)
			// Chunk Length: 1 x unsigned short (number of mapping points) 
			//             + 2 x float (mapping coordinates) x (number of mapping points)
			//             + sub chunks
			//-------------------------------------------
		case 0x4140:
			{
				fread (&l_qty, sizeof (unsigned short), 1, l_file);

				m_vUV1.resize(l_qty);

				float fTemp = 0.0f;

				for (i = 0; i < l_qty; ++i)
				{
					fread (&fTemp, sizeof (float), 1, l_file);
					m_vUV1[i].x = fTemp;

					fread (&fTemp, sizeof (float), 1, l_file);
					m_vUV1[i].x = fTemp;
				}
				break;
			}

			//----------- Skip unknown chunks ------------
			//We need to skip all the chunks that currently we don't use
			//We use the chunk length information to set the file pointer
			//to the same level next chunk
			//-------------------------------------------
		default:
			fseek(l_file, l_chunk_lenght-6, SEEK_CUR);
		} 
	}
	fclose (l_file); // Closes the file stream
	return (1); // Returns ok
}

bool Mesh::LoadObj(std::string strFile)
{
	return false;
}