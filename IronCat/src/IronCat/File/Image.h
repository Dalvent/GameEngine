#pragma once

#include <string>

namespace IronCat
{
	enum class ImageInternalFormat
	{
		RGB8, RGBA8
	};

	enum class ImageDataFormat 
	{
		RGB, RGBA
	};

	class Image
	{
	public:
		Image(std::string filePath);
		virtual ~Image();

		int GetWidth() const { return _width; }
		int GetHeight() const { return _height; }
		int GetChannels() const { return _channels; }
		unsigned char* GetData() const { return _data; }
		ImageInternalFormat GetInternalFormat() const { return _internalFormat; }
		ImageDataFormat GetDataFormat() const { return _dataFormat; }
	private:
		int _width;
		int _height;
		int _channels;
		unsigned char* _data;
		ImageInternalFormat _internalFormat;
		ImageDataFormat _dataFormat;
	};
}