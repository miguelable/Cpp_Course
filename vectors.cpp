/**
 * @file vectors.cpp
 * @author Miguel Ferrer (mferrer@inbiot.es)
 * @brief  Demonstrates various operations on a std::vector such as resizing,
 * reserving, and shrinking.It also shows how to use iterators to access and
 * modify elements in a vector.
 * @version 0.1
 * @date 2025-02-07
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Demonstrates basic initialization and usage of a std::vector of
 strings.
 *
 * This function performs the following operations:
 * - Creates an empty vector of strings.
 * - Adds three strings ("one", "two", "three") to the vector.
 * - Prints the size and capacity of the vector.
 * - Iterates over the vector and prints each string using a range-based for
 loop.
 * - Iterates over the vector and prints each string using an iterator.
 * - Iterates over the vector and prints each string using a reverse iterator.
 *  @note Capacity is the number of elements that can be stored in the vector
 without having to allocate more memory It's not the same as size, because size
 is the number of elements currently in the vector If you add more elements to
 the vector, it will automatically allocate more memory if it needs to, but it
 will only be able to do this if it has enough capacity to store the new
 elements If it doesn't have enough capacity, it will have to allocate more
 memory, which can be an expensive operation So, it's generally a good idea to
 reserve enough capacity for the vector when you create it, if you know how many
 elements you're going to store in it.
 */
void basic_vector_init() {
  // Create a vector of strings
  vector<string> strings;

  // Add some strings to the vector
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");

  // Print out the size of the vector
  cout << "Size of strings: " << strings.size() << '\n';
  cout << "Capacity of strings: " << strings.capacity() << '\n';
  // Iterate over the vector and print each string
  cout << "\nIteration over strings using range-based for loop:" << '\n';
  for (const auto &str : strings) {
    cout << str << '\n';
  }

  // Iterate over the vector using an iterator
  cout << "\nIteration over strings using iterator:" << '\n';
  for (vector<string>::iterator it = strings.begin(); it != strings.end();
       ++it) {
    cout << *it << '\n';
  }

  // Iterate over the vector using a reverse iterator
  cout << "\nIteration over strings using reverse iterator:" << '\n';
  for (vector<string>::reverse_iterator it = strings.rbegin();
       it != strings.rend(); ++it) {
    cout << *it << '\n';
  }
}

/**
 * @brief Demonstrates various operations on a std::vector such as resizing,
 * reserving, and shrinking.
 *
 * This function performs the following operations on a std::vector<int>:
 * - Displays the initial size and capacity of an empty vector.
 * - Adds 1500 elements to the vector, displaying the capacity each time it
 * changes.
 * - Clears the vector and displays its size and capacity.
 * - Resizes the vector to 100 elements and displays its size and capacity.
 * - Reserves memory for 100000 elements and displays its size and capacity.
 * - Shrinks the vector to fit its size and displays its size and capacity.
 */
void basic_vector_resize() {
  vector<int> numbers;
  vector<int>::size_type capacity = numbers.capacity();

  cout << "\nSize and Capacity of an empty vector" << '\n';
  cout << "Size: " << numbers.size() << '\n';
  cout << "Capacity: " << capacity << '\n';

  for (int i = 0; i < 1500; ++i) {
    numbers.push_back(i);
    if (capacity != numbers.capacity()) {
      capacity = numbers.capacity();
      cout << "Capacity: " << capacity << '\n';
    }
  }

  // Clear the vector
  cout << "\nClear the vector" << '\n';
  numbers.clear();
  cout << "Size: " << numbers.size() << '\n';
  cout << "Capacity: " << numbers.capacity() << '\n';

  // Resize the vector to 100 elements
  cout << "\nResize the vector to 100 elements" << '\n';
  numbers.resize(100);
  cout << "Size: " << numbers.size() << '\n';
  cout << "Capacity: " << numbers.capacity() << '\n';

  // Reserve memory for 100000 elements
  cout << "\nReserve memory for 100000 elements" << '\n';
  numbers.reserve(100000);
  cout << "Size: " << numbers.size() << '\n';
  cout << "Capacity: " << numbers.capacity() << '\n';

  // Shrink the vector
  cout << "\nShrink the vector" << '\n';
  numbers.shrink_to_fit();
  cout << "Size: " << numbers.size() << '\n';
  cout << "Capacity: " << numbers.capacity() << '\n';
}

/**
 * @brief Entry point of the program.
 * 
 * This function initializes and resizes a basic vector by calling
 * the functions `basic_vector_init` and `basic_vector_resize`.
 * It then waits for the user to press ENTER before exiting.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
  basic_vector_init();
  basic_vector_resize();

  // Wait for user to press ENTER
  system("pause");

  return 0;
}