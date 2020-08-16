#include "pch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &_id);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(_id);
	}

	void OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<IVertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(_id);
		vertexBuffer->Bind();
		unsigned int index = 0;
		
		BufferLayout layout = vertexBuffer->GetLayout();

		for (const auto& element : layout.GetElemnets())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.get;
		}
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IIndexBuffer>& vartexBuffer)
	{
	}

	void OpenGLVertexArray::SetLayout(const BufferLayout& layout)
	{
	}


}