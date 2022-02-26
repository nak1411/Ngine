#include "nepch.h"
#include "Map.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Map::Map()
	{
		this->InitVariables();
		this->blockSize = 64;
		
	}

	Map::~Map()
	{
		for (auto& i : blocks) {
			for (auto& j : i) {
				delete j;
			}
		}
	}

#pragma endregion

#pragma region INITIALIZERS

	void Map::InitVariables()
	{

	}

#pragma endregion

#pragma region FUNCTIONS

	void Map::CreateBlock()
	{
		this->numOfBlocks = 50;
		if (this->texture.loadFromFile("res/images/grass_01.png"))
		{
			NE_CORE_INFO("Loader");
		}
		for (auto i = 0; i < numOfBlocks; ++i)
		{
			this->blocks.push_back(std::vector<Block*>());
			for (auto j = 0; j < numOfBlocks; ++j)
			{
				this->blocks[i].push_back(new Block(sf::Vector2f(i * blockSize, j * blockSize), sf::Vector2f(blockSize, blockSize), this->texture));
			}
		}
	}

	void Map::Update(const float& dt)
	{
		
		for (auto& i : blocks) {
			for (auto& j : i) { 
				j->Update(dt);
			}
		}
	}	

	void Map::Render(sf::RenderTarget* target)
	{
		for (auto &i : blocks) {
			for (auto &j : i) {
				j->Render(target);
			}
		}	
	}

#pragma endregion

}
