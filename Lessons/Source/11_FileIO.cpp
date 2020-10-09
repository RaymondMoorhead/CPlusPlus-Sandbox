#include <fstream>  // ofstream, ifstream
#include <iostream> // cout
#include <string>   // string, getline

#if 0

int main(int argc, char* argv[])
{
  // the search for the file starts from where the
  // executable is called. When running from visual
  // studio it's the solution (*.sln) file, when
  // running independantly it's the from the
  // executable itself
  const char* filename = "SomeFile.txt";

  // a File Stream object, for reading/writing
  // http://www.cplusplus.com/reference/fstream/fstream/
  std::fstream file;

  // there are also 'ofstream' and 'ifstream' objects which
  // are used only for writing/reading accordingly

  // when opening the file you can pass in a number of flags
  // accessible through the nested access: 'std::fstream::FLAGNAME'
  // here are the most important ones, though there are more:
  //
  // | FLAG NAME | STANDS FOR | ACCESS                                  |
  // |-----------|------------|-----------------------------------------|
  // | in        | input      | read-only access                        |
  // | out       | output     | write-only access                       |
  // | trunc     | truncate   | contents in file are deleted on opening |
  //
  // referenced from:
  // http://www.cplusplus.com/reference/fstream/fstream/open/

  // ********** FILE WRITING EXAMPLE **********

  // set up flags to:
  //  write out data
  //  remove existing data in file
  int file_io_flags = std::fstream::out | std::fstream::trunc;

  // now open the file (it will be created if it doesn't exist)
  file.open(filename, file_io_flags);

  // check if the file is open
  if (file.is_open())
  {
    // write out the data
    file << "Hello File!" << std::endl;

    // close the file
    file.close();
  }

  // ********** FILE READING EXAMPLE **********

  // now open again for reading back, feel
  // free to directly add in flags
  file.open(filename, std::fstream::in);

  // NOTE: you don't actually need the in/out flags,
  //       they're just a best practice

  // here we use a string to get the data
  std::string line;

  // check if the file is open
  if (file.is_open())
  {
    // read the data back

    // get up to the next '\n' character (exclusive)
    std::getline(file, line);

    // you can also add a third argument: delimination_character
    //
    // std::getline(file, line, delimination_character);
    //
    // where 'delimination_character' is the character which
    // marks the end of each line. It could be anything, such
    // as '\n', '\r', 'o', 'T', etc.

    // print it to the console
    std::cout << line << std::endl;

    // at any point you can call 'eof' which stands
    // for 'End Of File.' If it returns 'true' then
    // we're done
    if(file.eof())
      std::cout << "At the end of the file" << std::endl;

    // for this example we know the if-check will fail,
    // because there is still a blank line in the stream

    // so the standard way to read a file is
    while (!file.eof())
    {
      std::getline(file, line);
      std::cout << line << std::endl;
    }

    // close the file
    file.close();
  }

  // ********** ONE FINAL READING DEMO **********

  file.open(filename);
  if (file.is_open())
  {
    while (!file.eof())
    {
      // this time denoting 'e' as the end of a line
      std::getline(file, line, 'e');
      std::cout << line << std::endl;
    }

    file.close();
  }
}

#endif