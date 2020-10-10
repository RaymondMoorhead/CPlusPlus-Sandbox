#if 0

#include <iostream>
#include <fstream>
#include <string>

// clear all data within the given file and fill it with
// the given data
void ReplaceFileContents(const char* filename, const char* data)
{
  std::ofstream file(filename, std::fstream::trunc);
  if (file.is_open())
  {
    file << data;
    file.close();
  }
}

// append the given data to the existing contents of the
// given file
void AddToFile(const char* filename, const char* data)
{
  std::ofstream file(filename, std::ofstream::app);
  if (file.is_open())
  {
    file << data;
    file.close();
  }
}

// clear all data from within the given file
void ClearFile(const char* filename)
{
  std::ofstream file(filename, std::fstream::trunc);
  if (file.is_open())
    file.close();
}

// fill the string 'data' with the file's complete contents
void GetFileContents(const char* filename, std::string& data)
{
  std::ifstream infile(filename);
  if (infile.is_open())
  {
    data.assign((std::istreambuf_iterator<char>(infile)),
                (std::istreambuf_iterator<char>()));
    infile.close();
  }
}

int main(int argc, char* argv[])
{
  // error macro
  #define ERROR_CHECK(CONDITION, MESSAGE) \
    if(CONDITION)                         \
    {                                     \
      std::cout << MESSAGE << std::endl;  \
      return -1;                          \
    }

  // test data
  std::string data;
  const char* filename = "Lesson_11_Test_File.txt";
  const unsigned sample_data_size = 10;
  const char* sample_data[] = {
    "Hello File!",
    "Goodbye File!",
    "Karrejahl Jigneison",
    "Brückungshlygnifil Jigneison",
    "Sephicus Brunel",
    "Scipio",
    "1234567890",
    "Multiple\nLines\nIn\nThis\nFile!",
    "words words words words words words words words words words",
    "This!\b one|\b has*\b backspace&\b characters!\b in_\b it^\b!"
  };

  // test ReplaceFileContents and GetFileContents
  for (unsigned i = 0; i < sample_data_size; ++i)
  {
    ReplaceFileContents(filename, sample_data[i]);
    GetFileContents(filename, data);
    ERROR_CHECK(data.compare(sample_data[i]) != 0, "Either ReplaceFileContents or GetFileContents failed");
  }

  // test ClearFile
  ClearFile(filename);
  GetFileContents(filename, data);
  ERROR_CHECK(!data.empty(), "ClearFile failed");

  // test AddToFile
  std::string all_data;
  for (unsigned i = 0; i < sample_data_size; ++i)
  {
    AddToFile(filename, sample_data[i]);
    all_data.append(sample_data[i]);
  }
  GetFileContents(filename, data);
  ERROR_CHECK(data.compare(all_data) != 0, "AddToFile failed");

  std::cout << "All tests completed successfully" << std::endl;
  return 0;
}

#endif