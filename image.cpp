#include "image.h"
#include <iostream>


void Image::load(const std::string& filename)
{
	try
	{
		_image.read(filename);
	}
	catch(Magick::Error& read_error)
	{
		std::cout << "Error while loading image: " << read_error.what() << std::endl;
		exit(1);
	}
}

void Image::rotate(int angle)
{
	try
	{
	_image.rotate(angle);
	}
	catch(Magick::Error& read_error)
	{
		std::cout << "error while rotating image: " << read_error.what() << std::endl;
	}
}

void Image::resize(unsigned int width, unsigned int height)
{
	try
	{
	_image.resize(Magick::Geometry(width, height));
	}
	catch(Magick::Error& read_error)
	{
		std::cout << "error while resizing image: " << read_error.what() << std::endl;
	}
}