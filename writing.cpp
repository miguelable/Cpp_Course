#include <fstream>
#include <iostream>

using namespace std;

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

int main() {
  // writeOutputFile();
  // readInputFile();
  appendToFile();
  return 0;
}