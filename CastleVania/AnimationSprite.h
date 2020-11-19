#pragma once
#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <list>

// include lib extend
#include "tinyxml.h"
using namespace std;

class Tile;

class AnimationSprite
{
public:
	AnimationSprite(LPDIRECT3DDEVICE9);
	~AnimationSprite();

	bool Init();

	bool Load(const char* ImagePath, const char* XMLPath, D3DCOLOR Transcolor);

	// DeltaTime; X; Y; Scale; AnimationRate; FlipX
	void Render(float DeltaTime, float X, float Y, float Scale, float AnimationRate, float FlipX = 1);

	void Release();

	// read file XML store list tile
	bool ReadXML(const char* XMLPath);
private:
	list<Tile>		_ListTile;			  // lưu tất cả các tile trong sprite sheet
	int				_IndexTile;			  // chỉ số hiển thị tile theo vòng lặp
	float			_AnimationRate_Index; // chỉ số thời gian deplay cho việc chuyển tile

	// texture store sprite sheet
	LPDIRECT3DTEXTURE9		_Texture;
	// handler to sprite
	LPD3DXSPRITE			_SpriteHandler;
	// store device
	LPDIRECT3DDEVICE9		_d3ddv;
	// sotre infomation sprite
	D3DXIMAGE_INFO			_Info;
};

class Tile
{
public:
	Tile();
	~Tile();

	void SetTile(const char* Name, int X, int Y, int Width, int Height);
	Tile GetTile();

	RECT GETLocaTionTile();
private:
	RECT		_RectTile;
	const char* _NameTile;
};