#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include "GoblinEngine\Core\Log.h"

namespace GoblinEngine
{
	class File
	{
	public:
		File(std::string& path) : _path(path)
		{
		}
		virtual ~File()
		{
		}

		std::string& GetFilePath() { return _path; }
		std::string& GetStringData() { return _data; }

		virtual void Load()
		{
			std::ifstream fileStream;
			fileStream.open(_path);
			
			if (fileStream.is_open())
			{
				GE_LOG_ERROR("Can't open file.");
				return;
			}
			
			std::stringstream stringStream;
			stringStream << fileStream.rdbuf();
			fileStream.close();
			
			_data = stringStream.str().c_str();
		}
		bool IsExist()
		{
			struct stat buffer;
			return (stat(_path.c_str(), &buffer) == 0);
		}
	private:
		std::string _path;
		unsigned char* _data;
	};
}