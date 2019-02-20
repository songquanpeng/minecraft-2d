#include "Organism.h"



Organism::Organism()
{
	name = "Organism";
	srand(static_cast<unsigned int>(time(0)));
	positionRelativeToScreen.row = rand() % SCREEN_ROW;
	positionRelativeToScreen.col = rand() % SCREEN_COL;
}


Organism::~Organism()
{

}

int Organism::desiredDirection()
{
	return rand() % 4;
}
