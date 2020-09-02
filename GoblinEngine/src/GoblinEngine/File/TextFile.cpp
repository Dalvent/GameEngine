#include "pch.h"
#include "TextFile.h"

namespace GoblinEngine
{
	void TextFile::Load()
	{
		std::ifstream fileStream;
		fileStream.open(GetFilePath());
		GE_LOG_CORE_ASSERT(fileStream.is_open(), "Can't open file with path {0}.", GetFilePath());

		std::stringstream stringStream;
		stringStream << fileStream.rdbuf();
		fileStream.close();

		_data = stringStream.str();
	}
}