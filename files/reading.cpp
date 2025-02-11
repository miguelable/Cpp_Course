/**
 * @file reading.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief  Reading from a file in C++
 * @version 0.1
 * @date 2025-02-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Reads and prints the contents of a file named "file.txt".
 *
 * This function attempts to open a file named "file.txt" for reading. If the
 * file cannot be opened, it prints an error message to the standard output. If
 * the file is successfully opened, it reads the file line by line and prints
 * each line to the standard output. After reading the file, it closes the file
 * stream.
 */
void readInputFile() {
  ifstream file; // Create an input file stream
  file.open("file.txt");
  if (!file.is_open()) {
    cout << "Unable to open file";
  } else {
    string line;
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  }
}

/**
 * @brief Entry point of the program.
 *
 * This function calls the readInputFile function to read data from an input
 * file.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  readInputFile();
  return 0;
}