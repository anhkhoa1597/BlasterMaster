
#include "SceneMain.h"

SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{
}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	//d3ddv->StretchRect(
	//	Background,			// from 
	//	NULL,				// which portion?
	//	G_BackBuffer,		// to 
	//	NULL,				// which portion?
	//	D3DTEXF_NONE);

	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	//Do??
	_AspBlasterMaster->Render(t, 350, 420, 2.5, 50, 1);

	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	// init animation sprite
	_AspBlasterMaster = new AnimationSprite(d3ddv);
	_AspBlasterMaster->Init();
	// load sprite
	if (!_AspBlasterMaster->Load(SPRITE_TITLE_BLASTERMASTER, SPRITE_TITLE_BLASTERMASTER_XML, D3DCOLOR_XRGB(255, 0, 255)))
	{
		PostQuitMessage(WM_QUIT);
	}
}

void SceneMain::OnKeyDown(int KeyCode)
{

}

SceneMain::~SceneMain(void)
{
	delete _AspBlasterMaster;
}
