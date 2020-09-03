#include <IronCat.h>
#include <IronCat/Core/EnteryPoint.h>

#include "SandBox.h"
#include "RenderCellLayer.h"
#include "ColorChooseLayer.h"

void IronCat::SetupAppSettings(IronCat::GameApplication& app)
{
	auto* gameMode = new SandBox(); 
	auto* colorLayer = new ColorChooseLayer();
	app.SetGameMod(gameMode);
	app.AddLayer(colorLayer);
	app.AddLayer(new RenderCellLayer(gameMode->GetCamera(), *colorLayer));
}