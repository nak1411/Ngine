#pragma once
#include "nepch.h"
#include "Block.h"

namespace Ngine {

	class Map
	{

	public:

		/*CONSTRUCTOR / DESTRUCTOR*/
		Map();
		virtual ~Map();

		/*FUNCTIONS*/
		void CreateBlock();

		virtual void Update(const float& dt);
		virtual void Render(sf::RenderTarget* target);

	protected:

		/*VARS*/
		sf::Texture texture;
		std::vector<std::vector<Block*>> blocks;

		int numOfBlocks;
		float r, g, b, a;
		int blockSize;

	private:

		/*VARS*/

		/*FUNCTIONS*/
		void InitVariables();

	};
}

