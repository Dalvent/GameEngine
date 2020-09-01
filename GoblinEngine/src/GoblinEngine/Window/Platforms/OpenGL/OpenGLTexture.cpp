#include "pch.h"
#include "OpenGLTexture.h"
#include "GoblinEngine/Core/Image.h"

#include "GoblinEngine/Window/Window.h"

#include <GLAD/glad.h>

namespace GoblinEngine
{
	OpenGLTexture2D::OpenGLTexture2D(const Image& image)
	{
		_width = image.GetWidth();
		_height = image.GetHeight();

		glCreateTextures(GL_TEXTURE_2D, 1, &_id);
		glTextureStorage2D(_id, 1, 
			GE_RENDER_API.ConvertImageInternalFormat(image.GetInternalFormat()),
			_width, _height);

		glTextureParameteri(_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureSubImage2D(_id, 0, 0, 0, _width, _height,
			GE_RENDER_API.ConvertImageDataFormat(image.GetDataFormat()),
			GL_UNSIGNED_BYTE, image.GetData()
		);
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &_id);
	}
	void OpenGLTexture2D::Bind(unsigned int slot) const
	{
		glBindTextureUnit(slot, _id);
	}
}