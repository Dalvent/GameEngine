#pragma once

#include "GoblinEngine/File/File.h"

namespace GoblinEngine
{
	class TextFile : public File
	{
	public:
		TextFile(std::string path) : File(path)
		{
		}

		std::string GetData() const { return _data; }

		void Load() override;
	private:
		std::string _data;
	};
}