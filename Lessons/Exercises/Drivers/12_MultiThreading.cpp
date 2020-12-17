#include <iostream>

unsigned SumBufferContents(unsigned* buffer, unsigned size, unsigned num_threads);

int main(int argc, char* argv[])
{
  const unsigned buffer_size = 500;
  unsigned buffer[buffer_size];
  unsigned result;
  for (unsigned i = 0; i < buffer_size; ++i)
    buffer[i] = i + 1;

#define RUN_TEST(START, SIZE, EXPECTED, NUM_THREADS)\
    result = SumBufferContents(&buffer[0] + START, SIZE, NUM_THREADS);\
    if(result != EXPECTED)\
    {\
      std::cout << "Error in test at line " << __LINE__ << ", result was " << result << " (expected " << EXPECTED << ")" << std::endl;\
      return -1;\
    }

  // whole buffer tests
  RUN_TEST(0, buffer_size, 125250, 1);
  RUN_TEST(0, buffer_size, 125250, 10);
  RUN_TEST(0, buffer_size, 125250, 100);
  RUN_TEST(0, buffer_size, 125250, 500);

  // partial buffer start at 0
  RUN_TEST(0, buffer_size / 2, 31375, 1);
  RUN_TEST(0, buffer_size / 2, 31375, buffer_size / 2);
  RUN_TEST(0, 1, 1, 1);

  // partial buffer starts halfway
  RUN_TEST(buffer_size / 2, buffer_size / 2, 93875, 1);
  RUN_TEST(buffer_size / 2, buffer_size / 2, 93875, buffer_size / 50);
  RUN_TEST(buffer_size / 2, buffer_size / 2, 93875, buffer_size / 2);

  std::cout << "All Tests Completed Successfully" << std::endl;
}