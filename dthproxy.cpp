/**********************************************************
 * Quebec, April 12, 2020 - dth [at] dthlabs [dot] com    *
**********************************************************/


//--------------------------------------------------------------------
// ToDo
//
// - check if the user is root
// - help file
// - alternative args (eg.: -h or --help)
// - better layout
// - add exceptions
// - refactor readConfigFile()
//   - it's opening and closing the file at every iteration
//   - it should ignore lines starting with #
//   - throw error if config file does not exist
// - refactor stringExplode()
//   - add delimiter as parameter
//   - hash maps for reading the config file


//--------------------------------------------------------------------
// Includes
#include <iostream>
#include <fstream>


//--------------------------------------------------------------------
// Config variables
std::string input_interface, input_interface_ipcidr, output_interface;


//--------------------------------------------------------------------
// Function prototypes
std::string* stringExplode(const char* stringToBeExploded);
void readConfigFile();


//--------------------------------------------------------------------
// Main
int main(int argc, char *argv[]) {
  std::string clargs[7]; // command line arguments
  
  std::cout << "\n\n*** activating proxy\n\n";

  // if there are command line arguments
  if(argc == 7) {
    for (int i = 0; i < argc; i++) {
      clargs[i] = argv[i];

      if (clargs[i] == "-input_interface") {
        input_interface = argv[++i];
      }
      if (clargs[i] == "-input_interface_ipcidr") {
        input_interface_ipcidr = argv[++i];
      }
      if (clargs[i] == "-output_interface") {
        output_interface = argv[++i];
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

  // test to see if the config variables were setup correctly from the file or from the commandline args
  std::cout << "input_interface: " << input_interface << "\n";
  std::cout << "input_interface_ipcidr: " << input_interface_ipcidr << "\n";
  std::cout << "output_interface: " << output_interface << "\n"; 
  
  return 0;
}


//--------------------------------------------------------------------
// Function stringExplode()
// Return an array containing the exploded strings
std::string* stringExplode(const char* stringToBeExploded){
  std::string str = stringToBeExploded;
  std::string word = "";

  // first loop to get the array size
  int array_size = 0;
  for (auto x : str) {
    if (x == ' ') {
      word = "";
      array_size++;
    } else {
      word = word + x;
    }
  }
  word = "";
  array_size = ++array_size;

  // declaring the result array
  std::string* result = new std::string[array_size];

  // second loop to build the result array
  int array_index = 0;
  for (auto x : str) {
    if (x == ' ') {
      result[array_index] = word;
      array_index++;
      word = "";
    } else {
      word = word + x;
    }
  }

  result[array_index] = word;

  return result;
}


//--------------------------------------------------------------------
// Function readConfigFile()
// Read the config file and set the config variables
void readConfigFile() {
  char *textFromConfigFile;
  std::string stringFromConfigFile = textFromConfigFile; // casting char* to string
  std::ifstream readFromConfigFile("dthproxy_config.cfg");

  int counter = 0;
  while (getline (readFromConfigFile, stringFromConfigFile)) {
    std::string* result_array = stringExplode(stringFromConfigFile.c_str());

    switch (counter) {
      case 0:
        input_interface = result_array[1];
        break;
      case 1:
        input_interface_ipcidr = result_array[1];
        break;
      case 2:
        output_interface = result_array[1];
        break;
      default:
        break;
    }
    
    counter++;
  }

  readFromConfigFile.close();   
}
