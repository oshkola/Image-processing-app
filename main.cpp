#include "image.h"
#include "main_window.h"

#include <gtkmm/button.h>
#include <gtkmm/window.h>

#include <iostream>
#include <string>
#include <thread>



int main(int argc, char* argv[])
{

  Magick::InitializeMagick(*argv);
  auto app = Gtk::Application::create(argc, argv, "Image processing app");

  MainWindow window;

  Image img;
 // std::thread th1(img, rotate);
//  th1.detach();
  return app->run(window);
}

//TODO
/*

Implement threads - one for UI, another for Magick++s

Add watermark

*/
