 #include "..\include\p2collider.h"

p2Collider::p2Collider(p2ColliderDef * colliderDef)
{
	this->userData = colliderDef->userData;
	isSensor = colliderDef->isSensor;
}

bool p2Collider::IsSensor()
{
	return this->isSensor;
}

void * p2Collider::GetUserData()
{
	return userData;
}
