#include <iostream>

// print your name using std::cout,
// and use std::endl to end the line
void PrintName();

// print a given number using std::cout,
// and use std::endl to end the line
void PrintNumber(int number);

int main(int argc, char* argv[])
{
  std::cout << "Hello there, ";
  PrintName();
  
  std::cout << "Let's make sure this number is what we expect." << std::endl;
  
  for(int i = 0; i < 10; ++i)
  {
    std::cout << "We expect " << i << ", and you have ";
    PrintNumber(i);
  }
}