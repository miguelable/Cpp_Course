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
 * @brief Prints the elements of a vector of integers.
 *
 * This function takes a constant reference to a vector of integers and prints
 * each element followed by a space. After printing all elements, it outputs a
 * newline character.
 *
 * @param v The vector of integers to be printed.
 */
void print_vector(const vector<int>& v)
{
  cout << '\n';
  for (const auto& elem : v) {
    cout << elem << ' ';
  }
  cout << '\n';
}

/**
 * @brief Prints the elements of a vector of strings to the standard output.
 *
 * This function takes a constant reference to a vector of strings and prints
 * each element followed by a space. After printing all elements, it outputs
 * a newline character.
 *
 * @param v A constant reference to a vector of strings to be printed.
 */
void print_vector(const vector<string>& v)
{
  cout << '\n';
  for (const auto& elem : v) {
    cout << elem << ' ';
  }
  cout << '\n';
}

/**
 * @brief Prints the contents of a vector of pairs.
 *
 * This function takes a constant reference to a vector of pairs, where each
 * pair consists of an integer and a string. It iterates through the vector and
 * prints each pair's integer and string to the standard output.
 *
 * @param v A constant reference to a vector of pairs (int, string) to be
 * printed.
 */
void print_vector(const vector<pair<int, string>>& v)
{
  cout << '\n';
  for (const auto& elem : v) {
    cout << elem.first << ": " << elem.second << '\n';
  }
}

/**
 * @brief Prints a 2D vector of integers to the standard output.
 *
 * This function takes a constant reference to a 2D vector of integers and
 * prints its elements to the standard output. Each inner vector's elements
 * are printed on a single line, separated by spaces. Each inner vector is
 * printed on a new line.
 *
 * @param v A constant reference to a 2D vector of integers to be printed.
 */
void print_vector(const vector<vector<int>>& v)
{
  cout << '\n';
  for (const auto& elem : v) {
    for (const auto& inner_elem : elem) {
      cout << inner_elem << ' ';
    }
    cout << '\n';
  }
}

/**
 * @brief Demonstrates basic vector creation and initialization in C++.
 *
 * This function showcases various ways to create and initialize vectors:
 * - Creating a vector of integers and printing it.
 * - Creating a vector of strings and printing it.
 * - Creating a vector of pairs (int, string) and printing it.
 * - Creating a vector of vectors of integers and printing it.
 * - Creating a vector of integers with 10 elements, all initialized to 0, and
 * printing it.
 * - Creating a vector of integers with 10 elements, all initialized to 1, and
 * printing it.
 * - Initializing a vector of integers with the elements of another vector and
 * printing it.
 * - Initializing a vector of integers with the elements of an array and
 * printing it.
 */
void basic_vector_creation()
{
  // Create a vector of integers
  vector<int> numbers = {1, 2, 3, 4, 5};
  print_vector(numbers);
  // create a vector of strings
  vector<string> strings = {"one", "two", "three"};
  print_vector(strings);
  // Create a vector of pairs
  vector<pair<int, string>> pairs = {{1, "one"}, {2, "two"}, {3, "three"}};
  print_vector(pairs);
  // Create a vector of vectors
  vector<vector<int>> vectors = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print_vector(vectors);

  // Create a vector of integers with 10 elements, all initialized to 0
  vector<int> zeros(10);
  print_vector(zeros);
  // Create a vector of integers with 10 elements, all initialized to 1
  vector<int> ones(10, 1);
  print_vector(ones);

  // Initialize a vector of integers with the elements of another vector
  vector<int> copy(numbers);
  print_vector(copy);
  // Initialize a vector of integers with the elements of an array
  int         arr[] = {1, 2, 3, 4, 5};
  vector<int> from_array(arr, arr + 5);
  print_vector(from_array);
}

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
void basic_vector_init()
{
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
  for (const auto& str : strings) {
    cout << str << '\n';
  }

  // Iterate over the vector using an iterator
  cout << "\nIteration over strings using iterator:" << '\n';
  for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
    cout << *it << '\n';
  }

  // Iterate over the vector using a reverse iterator
  cout << "\nIteration over strings using reverse iterator:" << '\n';
  for (vector<string>::reverse_iterator it = strings.rbegin(); it != strings.rend(); ++it) {
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
void basic_vector_resize()
{
  vector<int>            numbers;
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
 * @brief Creates and prints a 2D vector with predefined values.
 *
 * This function initializes a 2D vector (3x4) with all elements set to 5
 * and then prints the vector using the print_vector function.
 */
void basic_two_dimension_vectors()
{
  vector<vector<int>> grid(3, vector<int>(4, 5));
  print_vector(grid);
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
int main()
{
  basic_vector_init();
  basic_vector_resize();
  basic_vector_creation();
  basic_two_dimension_vectors();

  // Wait for user to press ENTER
  system("pause");

  return 0;
}