/**********************************************************
 * Quebec, April 12, 2020 - dth [at] dthlabs [dot] com    *
**********************************************************/

#include <iostream>

// ToDo
// check if the user is root
// help file
// alternative args (eg.: -h or --help)
// better layout


int main( int argc, char *argv[] ) {
  std::string input_interface, input_interface_ipcidr, output_interface;
  std::string clargs[7]; // command line arguments
  
  std::cout << "\n\n*** activating proxy\n\n";

  if(argc == 7) {
    for (int i = 0; i < argc; i++) {
      clargs[i] = argv[i];

      if (clargs[i] == "-input_interface") {
        input_interface = argv[i];
        std::cout << "input_interface is: "<< argv[++i] << "\n";
      }
      if (clargs[i] == "-input_interface_ipcidr") {
        input_interface_ipcidr = argv[i];
        std::cout << "input_interface_ipcidr is: "<< argv[++i] << "\n";
      }
      if (clargs[i] == "-output_interface") {
        output_interface = argv[i];
        std::cout << "output_interface is: "<< argv[++i] << "\n";
      }
    }
  }
  else if(argc > 1 && argc < 7 || argc > 7) {
    clargs[1] = argv[1];

    if (clargs[1] == "--help") {
      std::cout << "This is the help section. Bla bla bla.\n";
    } else {
      std::cout << "Please enter 3 arguments. Or try: dthproxy --help.\n";
    }
  }
  else {
    printf("No args expected. Will read from the config file.\n");
  }
}