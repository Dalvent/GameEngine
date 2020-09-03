#include "pch.h"
#include "Image.h"

#include <stb_image/stb_image.h>

namespace IronCat
{
	Image::Image(std::string filePath)
	{
		_data = stbi_load(filePath.c_str(), &_width, &_height, &_channels, 0);

		if (_channels == 3)
		{
			_internalFormat = ImageInternalFormat::RGB8;
			_dataFormat = ImageDataFormat::RGB;
		}
		else if (_channels == 4)
		{
			_internalFormat = ImageInternalFormat::RGBA8;
			_dataFormat = ImageDataFormat::RGBA;
		}
		else
		{
			IC_LOG_CORE_ERROR("Unown image format!");
		}
	}
	Image::~Image()
	{
		stbi_image_free(_data);
	}
}