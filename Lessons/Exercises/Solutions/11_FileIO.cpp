#include <fstream>
#include <string>

// clear all data within the given file and fill it with
// the given data. Do not add any additional data (such as newlines).
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
// given file. Do not add any additional data (such as newlines).
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