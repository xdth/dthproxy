/********************************************************************
 * Quebec, April 12, 2020                                           *
 * https://dthlabs.com                                              *
 * dth [at] dthlabs [dot] com                                       *
*********************************************************************/


//--------------------------------------------------------------------
// ToDo
//
// - help file
// - better layout
// - add exceptions
// - refactor readConfigFile()
//   - it's opening and closing the file at every iteration
//   - it should ignore lines starting with #
//   - throw error if config file does not exist
// - refactor explodeString()
//   - add delimiter as parameter
//   - hash maps for reading the config file


//--------------------------------------------------------------------
// Includes

#include <iostream>
#include <fstream>
#include <unistd.h>


//--------------------------------------------------------------------
// Config variables

std::string input_interface;
std::string input_interface_ipcidr;
std::string output_interface;


//--------------------------------------------------------------------
// Function prototypes

bool amIroot();
std::string* explodeString(const char* string_to_be_exploded);
void readConfigFile();
int help();


//--------------------------------------------------------------------
// Main

int main(int argc, char *argv[]) {
  // if(!amIroot()) {
  //   std::cout << "Only root can run this program. \n";
  //   // return 0;
  // }

  std::string clargs[7]; // command line arguments
  
  // if there are command line arguments
  if(argc == 7) {
    for (int i = 0; i < argc; i++) {
      clargs[i] = argv[i];

      if (clargs[i] == "--input_interface" || clargs[i] == "-i") {
        input_interface = argv[++i];
      }
      else if (clargs[i] == "--input_interface_ipcidr" || clargs[i] == "-c") {
        input_interface_ipcidr = argv[++i];
      }
      else if (clargs[i] == "--output_interface" || clargs[i] == "-o") {
        output_interface = argv[++i];
      }
      else {
        // if (clargs[i] != clargs[0]) { // if wrong argument is not the executable's name
        //   std::cout << "Invalid option: " << clargs[i] << "\n";
        //   return 1;
        // }
      }
    }
  }
  else if(argc > 1 && argc < 7 || argc > 7) {
    // clargs[1] = argv[1];

    // if (clargs[1] == "--help" || clargs[1] == "-h") {
    //   help();
    // } else {
    //   std::cout << "Please enter 3 arguments. Or try: dthproxy --help.\n";
    // }
  }
  else {
    // No args entered. Will read from the config file.
    readConfigFile();
  }

  // proceed if all arguments are there
  // if(input_interface != "" && input_interface_ipcidr != "" && output_interface != "" ){
  //   std::cout << "\n\n*** activating proxy\n\n";
  //   std::cout << "input_interface: " << input_interface << "\n";
  //   std::cout << "input_interface_ipcidr: " << input_interface_ipcidr << "\n";
  //   std::cout << "output_interface: " << output_interface << "\n";     
  // }
  
  return 0;
}


//--------------------------------------------------------------------
// Function amIroot()
// Return true if root, false if otherwise

bool amIroot() {
  bool is_root = getuid() ? false : true;
  return is_root;
}


//--------------------------------------------------------------------
// Function explodeString()
// Return an array containing the exploded strings

std::string* explodeString(const char* string_to_be_exploded){
  std::string str = string_to_be_exploded;
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
  char *text_from_config_file;
  std::string string_from_config_file = std::string(text_from_config_file); // casting char* to string
  std::ifstream read_from_config_file("dthproxy_config.cfg");

  int counter = 0;
  // while (getline (read_from_config_file, string_from_config_file)) {
  //   std::string* result_array = explodeString(string_from_config_file.c_str());

  //   switch (counter) {
  //     case 0:
  //       input_interface = result_array[1];
  //       break;
  //     case 1:
  //       input_interface_ipcidr = result_array[1];
  //       break;
  //     case 2:
  //       output_interface = result_array[1];
  //       break;
  //     default:
  //       break;
  //   }
    
  //   counter++;
  // }

  read_from_config_file.close();
}


//--------------------------------------------------------------------
// Function help()
// Provides help on how to use the program

int help() {
  std::cout << "Welcome to dthproxy.\n";
  std::cout << "You need to input 3 arguments: etc, etc, etc.\n";
  return 0;
}