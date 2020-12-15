#include <iostream>
#include <chrono>

// _DEBUG and _NDEBUG are defined by Visual Studio
// for Debug builds and Non-Debug (aka: Release)
// builds respectively

#ifdef _DEBUG // When in Debug

// do debug stuff, we would rather have the info
// for testing than the raw speed

#define START_LOGGING() unsigned _log_messages = 0;
#define LOG(MESSAGE) { std::cout << MESSAGE << std::endl; ++_log_messages; }
#define END_LOGGING() std::cout << "Program ended with " << _log_messages << " logged messages" << std::endl;

#else // When in Release

// don't do anything, we want those extra cycles for
// running our finished application

#define START_LOGGING()
#define LOG(MESSAGE)
#define END_LOGGING()

#endif

// try running the following program in Debug and Release mode,
// check the speed difference. In a program this small it won't
// be as important, but the difference should already be quite
// noticable.

int main(int argc, char* argv[])
{
  START_LOGGING();

  // get the starting time in milliseconds
  long start_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

  LOG("Beginning Fibonacci");
  unsigned prev_1 = 0;
  unsigned prev_2 = 1;
  unsigned next = 0;
  while (next < 1000000)
  {
    next = prev_1 + prev_2;
    LOG(next);
    prev_1 = prev_2;
    prev_2 = next;

  }
  LOG("Fibonacci Completed");

  // get the ending time in milliseconds
  long end_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  
  // check the time taken in milliseconds
  std::cout << "Program took " << end_time - start_time << " milliseconds" << std::endl;
  END_LOGGING();
}