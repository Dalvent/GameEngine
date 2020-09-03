#pragma once

#include <glm/glm.hpp>

namespace IronCat
{
	class OrthogriphicCamera
	{
	public:
		OrthogriphicCamera(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() const { return _position; }
		float GetRotation() const { return _rotation; }
		
		void SetPosition(const glm::vec3& position) { _position = position; RecalculateViewMatrix(); }
		void SetRotaion(float rotation) { _rotation = rotation; RecalculateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
		const glm::mat4& GeViewMatrix() const { return _viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _viewProjectionMatrix;

		glm::vec3 _position;
		float _rotation = 0.0f; 
	};
}