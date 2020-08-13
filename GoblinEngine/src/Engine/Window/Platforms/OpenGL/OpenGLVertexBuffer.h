#pragma once

namespace GoblinEngine
{
	class OpenGLVertexBuffer : public IVertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* data, unsigned int count);
		~OpenGLVertexBuffer();

		void Bind() override;
		void Unbind() override;
	private:
		unsigned int _id;
	};
}