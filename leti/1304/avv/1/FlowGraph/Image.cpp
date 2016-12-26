#include "Image.h"
#include <ctime>
#include<iostream>

Image::Image(const int size)
{
	
	img = new int[size*size];
	this->size = size;
	
	for (int i = 0; i < size*size; i++)
	{
		img[i] = rand() % 256;

	}
	
}

void  Image::highliting(int index)
{
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << img[getI(i, j)] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<std::endl;*/
	img[index] = 0;
	if(index+size<=size*size) img[index + size] = 0;
	if (index  > size) img[index - size] = 0;
	if (index%size != 0) img[index + 1] = 0;
	if (index%size != 1) img[index - 1] = 0;
	if ((index + size <= size*size)&&(index%size != 0)) img[index + size+1] = 0;
	if ((index + size <= size*size) && (index%size != 1)) img[index + size - 1] = 0;
	if ((index  > size) && (index%size != 0)) img[index -size + 1] = 0;
	if ((index  > size) && (index%size != 1)) img[index - size - 1] = 0;
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << img[getI(i, j)] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" << std::endl;*/
}
int Image::getV(int i, int j)
{
	return img[i + j*size];
}

int Image::getI(int i, int j)
{
	return j + i*size;
}
void Image::set(int val, int i, int j)
{
	 img[getI(i, j)]=val;
}
Image::~Image()
{
	
	delete[] img; 
}