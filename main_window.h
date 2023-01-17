#pragma once

#include <gtkmm.h>


class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_button_file_clicked();
  void on_file_dialog_response();
  void on_button_resize_clicked();

  //Child widgets:
  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_File;
  Gtk::Button m_Rotate_File;
  Gtk::Button m_Resize_File;
};