/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <p2world.h>
#include <iostream>


p2World::p2World(p2Vec2 gravity) : m_Gravity(gravity)
{
	
}

void p2World::Step(float dt)
{
	for (auto body_it = m_bodies.begin(); body_it != m_bodies.end(); body_it++)
	{
		if (body_it->GetType() == p2BodyType::DYNAMIC)
		{
			body_it->SetPosition((body_it->GetLinearVelocity() * dt + m_Gravity * body_it->GetGravityScale() * dt));
		}

		for (auto body_it_second = m_bodies.begin(); body_it_second != m_bodies.end(); body_it_second++)
		{
			if (body_it != body_it_second)
			{
				//Verifier si ils se touchent
				if(body_it->CheckContact(&(*body_it_second)))
				{
					std::cout << "Sa touche !!!!!!!";
				}
				else
				{
					std::cout << "Pas touche !!!!!!";
				}
			}
		}
		
	}



}

p2Body * p2World::CreateBody(p2BodyDef* bodyDef)
{
	p2Body body(bodyDef);
	m_bodies.push_front(body);
	std::list<p2Body>::iterator it = m_bodies.begin();
	return &(*it);
}

void p2World::SetContactListener(p2ContactListener * contactListener)
{

}
