#if 0

#include <iostream> // cout, endl

#define RETURN(Message, ReturnVal) \
  std::cout << Message << std::endl; \
  return ReturnVal;


// swap the values of the two integers
void SwapValues(int& x, int& y)
{
}

// set all array values to 0
void SetZero(int* array, unsigned size)
{
}

// find the first occurrence of the given
// character in the given string, and return
// the index, or -1 if you don't find it
int FindCharacterInString(const char* string, char c_to_find)
{
  return -1;
}

int main(int argc, char* argv[])
{
  // SwapValues test
  int x1, x2;
  for(int i = 0; i < 50; ++i)
    for (int j = 25; j < 75; ++j)
    {
      x1 = i;
      x2 = j;
      SwapValues(x1, x2);
      if (!(x1 == j && x2 == i))
      {
        RETURN("Failure in SwapValues", -1);
      }
    }

  // SetZero tests
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  SetZero(array, 1);
  if (array[0] != 0 || array[1] == 0)
  {
    RETURN("Failure in SetZero", -1)
  }

  SetZero(array, 9);
  if (array[8] != 0 || array[9] == 0)
  {
    RETURN("Failure in SetZero", -1)
  }

  SetZero(array, 10);
  for(int i = 0; i < 10; ++i)
  if (array[i] != 0)
  {
    RETURN("Failure in SetZero", -1)
  }

  // FindCharacterInString tests
  if (FindCharacterInString("Hello", 'H') != 0)
  {
    RETURN("Failure in FindCharacterInString", -1)
  }

  if (FindCharacterInString("", 'H') != -1)
  {
    RETURN("Failure in FindCharacterInString", -1)
  }

  if (FindCharacterInString("Hello", 'w') != -1)
  {
    RETURN("Failure in FindCharacterInString", -1)
  }
  if (FindCharacterInString("Hello", 'o') != 4)
  {
    RETURN("Failure in FindCharacterInString", -1)
  }

  RETURN("All tests finished successfully", 0)
}
#endif