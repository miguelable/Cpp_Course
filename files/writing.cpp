/**
 * @file writing.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief  Writing to a file in C++
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
 * @brief Writes a test message to an output file.
 *
 * This function creates an output file stream and writes two lines of text
 * ("Hello, world!" and "This is a test file.") to a file named "file.txt".
 * If the file cannot be opened, it outputs an error message to the console.
 * If the file is written successfully, it outputs a success message to the
 * console.
 */
void writeOutputFile() {
  ofstream file; // Create an output file stream
  file.open("file.txt");
  if (!file.is_open()) {
    cout << "Unable to open file";
  } else {
    file << "Hello, world!" << endl;
    file << "This is a test file." << endl;
    file.close();
    cout << "File written successfully" << endl;
  }
}

/**
 * @brief Appends a new line of text to a file named "file.txt".
 *
 * This function opens the file "file.txt" in append mode. If the file cannot be
 * opened, it prints an error message to the console. If the file is
 * successfully opened, it writes a new line of text to the file, closes the
 * file, and prints a success message to the console.
 */
void appendToFile() {
  ofstream file;                   // Create an output file stream
  file.open("file.txt", ios::app); // Open the file in append mode
  if (!file.is_open()) {
    cout << "Unable to open file" << endl;
  } else {
    file << "This is a new line." << endl;
    file.close();
    cout << "File written successfully" << endl;
  }
}

/**
 * @brief Entry point of the program.
 *
 * This function calls writeOutputFile() to write data to an output file
 * and appendToFile() to append data to the same file.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  writeOutputFile();
  appendToFile();
  return 0;
}