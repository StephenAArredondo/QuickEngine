#ifndef __COMPONENT_TYPE_H__
#define __COMPONENT_TYPE_H__

namespace EComponentType
{
	enum eComponentType
	{
		CT_TRANSFORM = 0, 
		CT_RENDERING, 
		CT_INPUT,
		CT_SFX, 
		CT_COLLISION, 
		CT_MESH,
		CT_PLAYER, 
		CT_AI,
		CT_CAMERA,
		CT_PHYSICS, 
		CT_SPATIAL, 
		CT_VFX, 
		CT_ANIMATION, 
		CT_HEALTH,
		CT_DEBUG,

		CT_LAST
	};

	const unsigned int CT_TRANSFORM_BIT = 1 << CT_TRANSFORM;
	const unsigned int CT_RENDERING_BIT = 1 << CT_RENDERING;
	const unsigned int CT_INPUT_BIT		= 1 << CT_INPUT;
	const unsigned int CT_SFX_BIT		= 1 << CT_SFX;
	const unsigned int CT_COLLISION_BIT = 1 << CT_COLLISION;
	const unsigned int CT_MESH_BIT		= 1 << CT_MESH;
	const unsigned int CT_PLAYER_BIT	= 1 << CT_PLAYER;
	const unsigned int CT_AI_BIT		= 1 << CT_AI;
	const unsigned int CT_CAMERA_BIT	= 1 << CT_CAMERA;
	const unsigned int CT_PHYSICS_BIT	= 1 << CT_PHYSICS;
	const unsigned int CT_SPATIAL_BIT	= 1 << CT_SPATIAL;
	const unsigned int CT_VFX_BIT		= 1 << CT_VFX;
	const unsigned int CT_ANIMATION_BIT = 1 << CT_ANIMATION;
	const unsigned int CT_HEALTH_BIT	= 1 << CT_HEALTH;
	const unsigned int CT_DEBUG_BIT		= 1 << CT_DEBUG;

	static unsigned int GetBit(eComponentType _eType) { return (1 << _eType); }
}

#endif