#include "pch.h"

Component::Component(ActorBase* _owner)
	: mOwner(_owner)
{
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}