#include "pch.h"
#include "LayerList.h"

namespace IronCat
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
		_layers.emplace_back(layer);
	}

	void LayerList::Remove(Layer* layer)
	{
		auto findLayerIndex = std::find(_layers.begin(), _layers.end(), layer);
		_layers.erase(findLayerIndex);
	}
}