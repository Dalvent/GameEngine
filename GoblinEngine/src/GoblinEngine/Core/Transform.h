#pragma once

#include <glm/glm.hpp>

namespace GoblinEngine
{
	class Transform
	{
	public:
		Transform();

		glm::mat4 GetWorldMatrix() const { return _worldMatrix; }
		glm::mat4 GetLocalMatrix() const;

		Ref<Transform> GetOwner() const { return _owner; }
		glm::vec3 GetLocalPosition() const { return _position; }
		glm::vec3 GetLocalRotation() const { return _rotation; }
		glm::vec3 GetLocalScale() const { return _scale; }
		glm::vec3 GetWorldPosition() const;
		glm::vec3 GetWorldRotation() const;
		glm::vec3 GetWorldScale() const;

		void SetOwner(Ref<Transform>& owner)
		{
			_owner = owner;
			RecalculateWorldMatrix();
		}
		void SetPosition(glm::vec3 position)
		{
			_position = position;
			RecalculateWorldMatrix();
		}
		void SetRotation(glm::vec3 rotation)
		{
			_rotation = rotation;
			RecalculateWorldMatrix();
		}
		void SetScale(glm::vec3 scale)
		{
			_scale = scale;
			RecalculateWorldMatrix();
		}

	private:
		void RecalculateWorldMatrix();

		glm::mat4 _worldMatrix;
		glm::vec3 _position;
		glm::vec3 _rotation;
		glm::vec3 _scale;
		Ref<Transform> _owner;
	};
}