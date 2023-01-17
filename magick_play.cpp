#include <gtkmm.h>
#include <Magick++.h>

#include <iostream>

Magik::Image load_image(string filename)
{
	Magick::Image image("pinguin.jpeg");
	return image;
}

void rotate(Magick::Image img, double angle)
{
	img.rotate(angle);
}
void resize(Magick::Image img, int width, int height)
{
	img.resize(Magick::Geometry(width, height));
}


int main(int argc, char* argv[])
{
	Magick::InitializeMagick(*argv);
	Magick::Image image("pinguin.jpeg");
	image.rotate(90);
	image.write("pinguin_rotated.jpeg");

	int columns = image.columns();
	int rows = image.rows();
	std::cout << columns << " " << rows << std::endl;

	image.resize(Magick::Geometry(1024, 1024));
	image.write("pinguin_resized.jpeg");
}