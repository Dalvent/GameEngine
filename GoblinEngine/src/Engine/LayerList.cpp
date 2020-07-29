#include "pch.h"
#include "LayerList.h"

namespace GoblinEngine
{
	LayerList::~LayerList()
	{
		for (Layer* layer : _layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerList::Add(Layer* layer)
	{
		std::cout << _layers.size();
		_layers.emplace_back(layer);
		std::cout << _layers.size();
	}

	void LayerList::Remove(Layer* layer)
	{
		auto findLayerIndex = std::find(_layers.begin(), _layers.end(), layer);
		_layers.erase(findLayerIndex);
	}
}