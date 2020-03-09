#include <iostream>
#include <controller.h>
#include "version_lib.h"

 

 
int main(int argc, char *argv[]) 
{
    
  if ( argc > 1)
  {
    const std::string ver = "-version";
    if (argv[1] == ver)     std::cout << "version: " << version_major()<< '.'<< version_minor() << '.' << version_patch() << std::endl;
    else                    std::cout << "Type: -version, if you want to known proramm version" << std::endl;    
  }

try
{
    std::shared_ptr<Figure> figure = nullptr;
    std::shared_ptr<View> view(new View());
    Controller editor(figure,view);

    editor.create("Line");
    editor.clean();
    editor.create("Square");
    editor.clean();
    editor.create("Triangle");
    editor.create("Trololol");
    editor.clean();

    Document doc1("My picture");
    editor.openDocument(&doc1);
    editor.create("Square");
    editor.saveDocument(&doc1);
    editor.clean();
    editor.create("Line");
    editor.openDocument(&doc1);
    editor.create("Triangle");
    editor.openDocument(&doc1);
}

catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

    return 0;
}