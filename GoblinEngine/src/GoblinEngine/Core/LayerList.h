#pragma once

#include "GoblinEngine/Core/Layer.h"

namespace GoblinEngine
{
	class LayerList
	{
	public:
		LayerList() = default;
		~LayerList();

		void Add(Layer* layer);
		void Remove(Layer* layer);

		std::vector<Layer*>::iterator Begin() { return _layers.begin(); }
		std::vector<Layer*>::iterator End() { return _layers.end(); }
	private:
		std::vector<Layer*> _layers;
	};
}