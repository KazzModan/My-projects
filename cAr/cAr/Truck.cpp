#include "Truck.h"

void Truck::setWeightofLoad(size_t weight)
{
	if (weight > MIN && weight < MAX_WEIGHT)
		this->weightOfLoad = weight;
}

Truck::Truck(size_t weightOfLoad, size_t weight, string brand, string model, size_t year, size_t volume)
{
	
	setWeight(weight);
	setBrand(brand);
	setModel(model);
	setYear(year);
	setVolume(volume);
	setWeightofLoad(weightOfLoad);
}
