#!/bin/bash
rm app.out
g++ main.cpp main_window.cpp image.cpp -o app.out `Magick++-config --ldflags --libs` `pkg-config --libs --cflags gtkmm-3.0`
./app.out