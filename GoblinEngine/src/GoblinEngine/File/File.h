#pragma once

#include <fstream>
#include <string>

namespace GoblinEngine
{
	// Abstract class, parrent to all file classes.
	// In ctor get filepath to use it in Load().
	// To use object you need at first use metod load.
	// Load() gets data from file and set it in object.
	// To update data use Load() again.
	class File
	{
	public:
		File(std::string path) : _path(path)
		{
		}

		std::string GetFilePath() const { return _path; }

		virtual void Load() = 0;
		bool IsExist() const
		{
			struct stat buffer;
			return (stat(_path.c_str(), &buffer) == 0);
		}
	private:
		std::string _path;
	};
}