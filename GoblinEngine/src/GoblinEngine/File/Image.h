#pragma once

#include <string>
#include "GoblinEngine/File/File.h"

namespace GoblinEngine
{
	enum class ImageInternalFormat
	{
		RGB8, RGBA8
	};

	enum class ImageDataFormat 
	{
		RGB, RGBA
	};

	class Image : public File
	{
	public:
		Image(std::string filePath) : File(filePath) {};
		virtual ~Image() {}

		int GetWidth() const { return _width; }
		int GetHeight() const { return _height; }
		int GetChannels() const { return _channels; }
		unsigned char* GetData() const { return _data; }
		ImageInternalFormat GetInternalFormat() const { return _internalFormat; }
		ImageDataFormat GetDataFormat() const { return _dataFormat; }
	
		void Load() override;
	private:
		int _width;
		int _height;
		int _channels;
		unsigned char* _data;
		ImageInternalFormat _internalFormat;
		ImageDataFormat _dataFormat;
	};
}