#pragma once
#include <vector>
#include <map>
#include "d3dUtil.h"

__declspec(align(16)) struct Bone {
	XMFLOAT4X4									offset;
	XMFLOAT4X4									localTransform;
	std::vector<Bone*>	children;
	int											idx;
	int											parentIdx;
	std::string									name;
};

class Skeleton {
public:
	Skeleton();
	~Skeleton();
	void SetRootTransform( XMFLOAT4X4A& transform );
	XMFLOAT4X4A* GetFinalTransforms();
	Bone* GetBoneByIndex( int index );
	Bone* GetBoneByName( std::string name );
	void AddBone( Bone* newBone );
	int BoneCount();
private:
	void UpdateTransforms( Bone* bone );
	const XMFLOAT4X4*					rootTransform;
	int									numBones;
	std::map<int, Bone*>				idxBones;
	std::map<std::string, Bone*>		nameBones;
	std::vector<XMFLOAT4X4>				toRoot;
	XMFLOAT4X4							finalTransformData[64];
	//AnimationController*				animationController;
};
