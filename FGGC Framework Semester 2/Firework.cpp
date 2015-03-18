//#include "Firework.h"
//
//Firework::Firework(string type, Geometry geometry, Material material, RealValue mass) : GameObject(type, geometry, material, mass)
//{
//}
//
//Firework::~Firework()
//{
//}
//
//bool Firework::Update(float t)
//{
//	GameObject::Update(t);
//
//	_mAge -= t;
//
//	return (_mAge < 0) || (GameObject::GetParticleModel()->GetTransform()->GetPosition().y < 1.0f);
//}//