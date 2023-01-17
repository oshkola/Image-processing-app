#pragma once

#include <Magick++.h>

#include <string>


class Image
{

	Magick::Image _image;

public:
	
	Image() = default;

	//Don't need object to be copied or moved within this task
	//Also we don't need the parametrized constructor, 
	//as object is always created before we know the filename

	Image(const std::string& filename) = delete;

	Image(const Magick::Image&) = delete;
	Magick::Image& operator=(const Magick::Image&) = delete;

	Image(Magick::Image&&) = delete;
	Magick::Image& operator=(Magick::Image&&) = delete;

	~Image() = default;

	void load(const std::string& filename);
	void rotate(int degrees);
	void resize(unsigned int width, unsigned int height);
};