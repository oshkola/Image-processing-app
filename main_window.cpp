#include "main_window.h"
#include <iostream>


MainWindow::MainWindow()
: m_ButtonBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_File("Choose File"),
  m_Rotate_File("Rotate"),
  m_Resize_File("Resize")
{
    set_title("Simple Image Processor");
    set_default_size(800, 400);

    add(m_ButtonBox);

    m_ButtonBox.pack_start(m_Button_File);
    m_Button_File.signal_clicked().connect(sigc::mem_fun(*this,
                &MainWindow::on_button_file_clicked) );
    m_Rotate_File.signal_clicked().connect(sigc::mem_fun(*this,
                &MainWindow::on_button_resize_clicked) );

    show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_file_clicked()
{

    Gtk::FileChooserDialog dialog("Choose a file",
            Gtk::FILE_CHOOSER_ACTION_OPEN);
  
    dialog.set_transient_for(*this);
    //Add response buttons:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    //Add filter for image types:
    auto filter_images = Gtk::FileFilter::create();
    filter_images->set_name("Images");
    filter_images->add_mime_type("image/png");
    dialog.add_filter(filter_images);

    //Show the dialog and wait for a user response:
    int result = dialog.run();

    /**********
    This doesn't work for me
    dialog.signal_response().connect(sigc::mem_fun(
                  *this, &MainWindow::on_file_dialog_response), dialog);
    ***********/

    //Handle the response:
    switch(result)
    {
      case(Gtk::RESPONSE_OK):
      {
          std::cout << "Open clicked." << std::endl;

          std::string filename = dialog.get_filename();
          std::cout << "File selected: " <<  filename << std::endl;

          //I realize this is not a good option, but 
          //I can't do it within signal_response()
          this->on_file_dialog_response();
          break;
      }
      case(Gtk::RESPONSE_CANCEL):
      {
          std::cout << "Cancel clicked." << std::endl;
          break;
      }
      default:
      {
          std::cout << "Unexpected button clicked." << std::endl;
          break;
      }
    }
}

void MainWindow::on_file_dialog_response()
{
  std::cout << "on_file_dialog_response()" << std::endl; 
    Gtk::FileChooserDialog dialog("Save file",
          Gtk::FILE_CHOOSER_ACTION_SAVE);

    dialog.add_button("_Save", Gtk::RESPONSE_ACCEPT);

    int result = dialog.run();


    switch(result)
    {
        case(Gtk::RESPONSE_ACCEPT):
        {
            std::cout << "Open clicked." << std::endl;

            std::string filename = dialog.get_filename();

            //Can't find proper method in documantation
            //dialog.save_to_file(modified_filename)

            break;
        }
        case(Gtk::RESPONSE_CANCEL):
        {
            std::cout << "Cancel clicked." << std::endl;
            break;
        }
        default:
        {
            std::cout << "Unexpected button clicked." << std::endl;
            break;
        }
    }

}

void MainWindow::on_button_resize_clicked()
{
  
}