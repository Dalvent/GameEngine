#pragma once

#include <glm/glm.hpp>

class Transform
{
public:
	glm::mat4 GetMatrix() const { return _transformMatrix; }
	Transform* GetOwner() const { return _owner; }
	glm::vec3 GetLocalPosition() const { return _position; }
	glm::vec3 GetLocalRotation() const { return _rotation; }
	glm::vec3 GetLocalScale() const { return _scale; }
	glm::vec3 GetWorldPosition() const
	{
		glm::vec3 worldPosition = _position;
		if (_owner != nullptr)
		{
			worldPosition += _owner->GetWorldPosition();
		}
		return worldPosition;
	}
	glm::vec3 GetWorldRotation() const
	{
		glm::vec3 worldRotation = _rotation;
		if (_owner != nullptr)
		{
			worldRotation += _owner->GetWorldRotation();
		}
		return worldRotation;
	}
	glm::vec3 GetWorldScale() const
	{
		glm::vec3 worldScale = _scale;
		if (_owner != nullptr)
		{
			worldScale += _owner->GetWorldScale();
		}
		return worldScale;
	}

	void SetOwner(Transform* owner)
	{
		_owner = owner;
		RecalculateMatrix();
	}
	void SetPosition(glm::vec3 position)
	{
		_position = position;
		RecalculateMatrix();
	}
	void SetRotation(glm::vec3 rotation)
	{
		_rotation = rotation;
		RecalculateMatrix();
	}
	void SetScale(glm::vec3 scale)
	{
		_scale = scale;
		RecalculateMatrix();
	}

private:
	void RecalculateMatrix()
	{
		glm::mat4 trans = glm::mat4(1.0f);

	}

	glm::mat4 _transformMatrix;
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;
	Transform* _owner;
};