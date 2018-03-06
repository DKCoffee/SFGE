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

#ifndef SFGE_PYCOMPONENT_H_
#define SFGE_PYCOMPONENT_H_

#include <engine/component.h>
#include <utility/python_utility.h>
//STL
#include <memory>

namespace sfge
{

/**
 * \brief Python abstraction of Component, used to be overloaded by a python script
 */
class PyComponent : public Component
{
public:
	using Component::Component;
	~PyComponent();
	/**
	* \brief Initialize the PyComponent to avoid crash because of overrided constructor
	*/
	void Init() override;
	/**
	* \brief Called each frame
	*/
	void Update(float dt) override;
	/**
	* \brief Factory method to import a python script 
	*/
	static PyComponent* LoadPythonScript(Engine& engine, json& componentJson, GameObject* gameObject);
	/**
	* \brief Can call the python script to receive the Collision Enter event
	*/
	void OnCollisionEnter(Collider* collider) override;
	/**
	* \brief Can call the python script to receive the Trigger Enter event
	*/
	void OnTriggerEnter(Collider * collider) override;
	/**
	* \brief Can call the python script to receive the Collision Exit event
	*/
	void OnCollisionExit(Collider* collider) override;
	/**
	* \brief Can call the python script to receive the Trigger Exit event
	*/
	void OnTriggerExit(Collider * collider) override;
	/**
	* \brief Getter of the Python Script Instance Id
	*/
	unsigned int GetInstanceId() const;
	/**
	* \brief Setter of the Python Script Instance Id
	*/
	void SetInstanceId(unsigned int instanceId = 0U);

private:
	unsigned int instanceId = 0U;
};

}


#endif /* INCLUDE_PYTHON_PYCOMPONENT_H_ */
