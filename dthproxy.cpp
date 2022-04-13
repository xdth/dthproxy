/**********************************************************
 * Quebec, April 12, 2020 - dth [at] dthlabs [dot] com    *
**********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>

// ToDo
// - check if the user is root
// - help file
// - alternative args (eg.: -h or --help)
// - better layout
// - add exceptions
// - refactor readConfigFile()
//   - it's opening and closing the file at every iteration
//   - it should ignore lines starting with #
//   - throw error if config file does not exist
// - refactor stringExplode(), add delimiter as parameter

char *stringExplode(char* stringToBeExploded){
  // char *str = stringToBeExploded;
  const char string_delimiter[2] = " ";
  char *token;

  while((token = strtok(stringToBeExploded, string_delimiter)) != NULL){
    std::cout << "The token is: " << token << "\n";
    return token;
  }

  return 0;
}

void readConfigFile() {
  char *textFromConfigFile;
  std::string stringFromConfigFile;
  stringFromConfigFile = textFromConfigFile; // casting char* to string
  std::ifstream readFromConfigFile("dthproxy_config.cfg");

  int tmp_counter = 0;
  while (getline (readFromConfigFile, stringFromConfigFile)) {
    char *arg_output = stringExplode(textFromConfigFile);
    std::cout << arg_output << tmp_counter << "\n";
    tmp_counter++;
  }

  readFromConfigFile.close();   
}

int main(int argc, char *argv[]) {
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
    // No args entered. Will read from the config file.
    readConfigFile();
  }
}