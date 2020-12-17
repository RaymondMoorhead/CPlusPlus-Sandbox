// swap the values of the two integers
void SwapValues(int& x, int& y)
{
  int temp = x;
  x = y;
  y = temp;
}

// set all array values to 0
void SetZero(int* array, unsigned size)
{
  for (unsigned i = 0; i < size; ++i)
    array[i] = 0;
}

// find the first occurrence of the given
// character in the given string, and return
// the index, or -1 if you don't find it
int FindCharacterInString(const char* string, char c_to_find)
{
  for (int i = 0; string[i] != '\0'; ++i)
    if (string[i] == c_to_find)
      return i;
  return -1;
}