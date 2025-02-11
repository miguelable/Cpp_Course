/**
 * @file binary.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief Writing and reading binary files in C++
 * @version 0.1
 * @date 2025-02-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <fstream>
#include <iostream>

using namespace std;

#pragma pack(push, 1) // Disable padding

/**
 * @brief  Structure to represent a binary file
 *
 * This structure represents a person with a name, age, and height. The
 * structure is packed to ensure that there is no padding between the members.
 *
 */
struct Person {
  char name[40];
  int age;
  double height;
};

#pragma pack(pop) // Restore padding

/**
 * @brief Writes binary data of several Person objects to a file.
 *
 * This function opens a binary file named "test.bin" for writing. It then
 * creates several Person objects and writes their binary data to the file. If
 * the file cannot be opened, an error message is printed to the console.
 *
 * The Person objects written to the file are:
 * - Frodo, age 220, height 0.8
 * - Sam, age 210, height 0.7
 * - Gandalf, age 1000, height 1.8
 * - Aragorn, age 300, height 1.9
 *
 * The function closes the file after writing the data.
 */
void writeBinaryFile() {
  // Open the file in binary write mode
  string fileName = "test.bin";
  ofstream fileOut(fileName, ios::binary);

  if (!fileOut.is_open()) {
    cout << "Could not open file " << fileName << endl;
    return;
  }
  Person someone = {"Frodo", 220, 0.8};
  Person another = {"Sam", 210, 0.7};
  Person third = {"Gandalf", 1000, 1.8};
  Person fourth = {"Aragorn", 300, 1.9};

  fileOut.write(reinterpret_cast<char *>(&someone), sizeof(Person));
  fileOut.write(reinterpret_cast<char *>(&another), sizeof(Person));
  fileOut.write(reinterpret_cast<char *>(&third), sizeof(Person));
  fileOut.write(reinterpret_cast<char *>(&fourth), sizeof(Person));
  fileOut.close();
}

/**
 * @brief Reads a binary file and prints the contents of each Person object.
 *
 * This function opens a binary file named "test.bin" in read mode. It reads the
 * file and interprets the data as Person objects. For each Person object read
 * from the file, it prints the name, age, and height to the standard output.
 *
 * If the file cannot be opened, an error message is printed to the standard
 * output.
 *
 * @note The Person structure must be defined elsewhere in the code.
 */
void readBinaryFile() {
  // Open the file in binary read mode
  string fileName = "test.bin";
  ifstream fileIn(fileName, ios::binary);

  if (!fileIn.is_open()) {
    cout << "Could not open file " << fileName << endl;
    return;
  }
  Person someone;
  while (fileIn.read(reinterpret_cast<char *>(&someone), sizeof(Person))) {
    cout << "Name: " << someone.name << endl;
    cout << "Age: " << someone.age << endl;
    cout << "Height: " << someone.height << endl;
    cout << endl;
  }
  fileIn.close();
}

/**
 * @brief Entry point of the program.
 *
 * This function calls writeBinaryFile() to write data to a binary file
 * and readBinaryFile() to read data from the binary file.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  writeBinaryFile();
  readBinaryFile();
  return 0;
}