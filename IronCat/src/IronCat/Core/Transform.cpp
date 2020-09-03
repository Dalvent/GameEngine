#include "pch.h"
#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace IronCat
{
	Transform::Transform() : 
		_position(0), _rotation(0), _scale(1), _owner(nullptr)
	{
		RecalculateWorldMatrix();
	}

	glm::mat4 Transform::GetLocalMatrix() const
	{
		glm::mat4 _localMatrix = glm::mat4(1.0f);

		_localMatrix = glm::translate(_localMatrix, GetWorldPosition());
		_localMatrix = glm::scale(_localMatrix, GetWorldScale());
		_localMatrix = glm::rotate(_localMatrix, glm::radians(1.0f), _rotation);

		return _localMatrix;
	}

	glm::vec3 Transform::GetWorldPosition() const
	{
		glm::vec3 worldPosition = _position;
		if (_owner != nullptr)
		{
			worldPosition += _owner->GetWorldPosition();
		}
		return worldPosition;
	}

	glm::vec3 Transform::GetWorldRotation() const
	{
		glm::vec3 worldRotation = _rotation;
		if (_owner != nullptr)
		{
			worldRotation += _owner->GetWorldRotation();
		}
		return worldRotation;
	}

	glm::vec3 Transform::GetWorldScale() const
	{
		glm::vec3 worldScale = _scale;
		if (_owner != nullptr)
		{
			worldScale += _owner->GetWorldScale();
		}
		return worldScale;
	}

	void Transform::RecalculateWorldMatrix()
	{
		glm::mat4 _recalcMatrix = glm::mat4(1.0f);

		_recalcMatrix = glm::translate(_recalcMatrix, GetWorldPosition());
		_recalcMatrix = glm::scale(_recalcMatrix, GetWorldScale());
		_recalcMatrix = glm::rotate(_recalcMatrix, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
			glm::rotate(_recalcMatrix, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::rotate(_recalcMatrix, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		_worldMatrix = _recalcMatrix;
	}
}