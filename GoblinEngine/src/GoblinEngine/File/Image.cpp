#include "pch.h"
#include "Image.h"

#include <stb_image/stb_image.h>

namespace GoblinEngine
{
	Image::~Image()
	{
		if (_data) stbi_image_free(_data);
	}
	void Image::Load()
	{
		_data = stbi_load(GetFilePath().c_str(), &_width, &_height, &_channels, 0);

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
			GE_LOG_CORE_ERROR("Unown image format!");
		}
	}
}