#include <iostream>

// A flag is essentially a thing representing a true or
// false state, and multiple ones are grouped together
// in an object or function input as a way to select
// options or store data

// As function input you might pass it to say:
// use bold text, use italic text, outline something,
// use reverse iterator, log the result, etc.

// In an object you might use flags to track the state of an
// object: if it has been initialized, if it's serializable,
// has it been serialized, is it a player, is it an enemy,
// is it displaying debug menus, etc.

// by default you may think to use bool values, like in the
// example below

struct BoolFlagTracker
{
  enum BOOL_FLAG
  {
    FLAG_ONE,   // 0
    FLAG_TWO,   // 1
    FLAG_THREE, // 2
    FLAG_FOUR,  // 3
    FLAG_FIVE,  // 4
    FLAG_SIX,   // 5
    FLAG_SEVEN, // 6
    FLAG_EIGHT, // 7
    NUM_FLAGS   // 8
  };

  void SetFlag(BOOL_FLAG flag, bool state) { flags_[flag] = state; }
  bool GetFlag(BOOL_FLAG flag) { return flags_[flag]; }

private:
  bool flags_[NUM_FLAGS] = { false };
};

// ...but you may wish to consider bitwise flags. They
// are more awkward to use, but can use up to 8 times less
// memory. This is because a bool is one byte in size, but
// a true/false state can be tracked with one bit (0 or 1).

struct BitFlagTracker
{
  enum BIT_FLAG
  {
    // NAME     HEX VALUE   BINARY VALUE
    FLAG_ONE =    0x01,   // 00000001
    FLAG_TWO =    0x02,   // 00000010
    FLAG_THREE =  0x04,   // 00000100
    FLAG_FOUR =   0x08,   // 00001000
    FLAG_FIVE =   0x10,   // 00010000
    FLAG_SIX =    0x20,   // 00100000
    FLAG_SEVEN =  0x40,   // 01000000
    FLAG_EIGHT =  0x80    // 10000000

    // there's no point using the NUM_FLAGS trick, with
    // our manual value setting it, it would default to
    // 129, or 10000001 in binary
  };

  // these functions use bitwise versions of the AND and OR
  // operands you are familiar with, this means that instead
  // of taking the type as a whole (1 byte here), it does
  // comparisons with individual bits, and outputs the result
  // of those bits as the resulting bit.
  //
  // so for two bit variables:
  //
  // 00 | 01 = 01
  // 01 | 01 = 01
  // 10 | 01 = 11
  //
  // 00 & 01 = 00
  // 01 & 01 = 01
  // 10 & 01 = 00
  void SetFlag(BIT_FLAG flag)       { flags_ = flags_ | flag; } // uses bitwise OR
  void UnsetFlag(BIT_FLAG flag)     { flags_ = flags_ & ~flag; }// uses bitwise AND and FLIP (0->1 and 1->0)
  bool GetFlag(BIT_FLAG flag)       { return flags_ & flag; }   // uses bitwise AND

  private:
    // with the size of char, this can only support 8 flags.
    // You could use a larger type, or allocate the needed bytes
    char flags_ = 0x00;
};

// it's also much easier to pass data into a function this way,
// allowing for many options per variable

// here we define our flags with english names
typedef char INPUT_FLAG;
INPUT_FLAG INDENT             = 0x01;
INPUT_FLAG PRINT_5            = 0x02;
INPUT_FLAG PRINT_PI           = 0x04;
INPUT_FLAG ADD_HELLO          = 0x08;

// and here is a function which takes one INPUT_FLAG variable,
// instead of 4 separate bool inputs
void PrintWithFlags(const char* to_say, INPUT_FLAG flags = 0)
{
  if (flags & INDENT)
    std::cout << '\t';

  std::cout << to_say;

  if (flags & PRINT_5)
    std::cout << " | 5";

  if (flags & PRINT_PI)
  {
    bool uninitialized_bool;
    std::cout << " | 3.14159";
  }

  if (flags & ADD_HELLO)
    std::cout << " | Hello";

  std::cout << std::endl;
}

// Flags are not C++ specific, but they are much more
// common in it. The principles here can be used in
// Java as well, and in fact are by classes such as
// java.util.regex.Pattern, where you can pass flags
// into the Pattern.compile method, and call
// Pattern.flags() to get back what flags you set.

// macro used to exit with a failure state,
// used in testing here
#define FAILURE \
    {\
      std::cout << "Flag comparison did not match on " << i << std::endl; \
      return -1; \
    }

#if 0

int main(int argc, char* argv[])
{
  BoolFlagTracker bool_tracker;
  BitFlagTracker bit_tracker;

  // print sizes in bytes of each type
  std::cout << "BoolFlagTracker object is " << sizeof(bool_tracker) << " byte(s) in size" << std::endl;
  std::cout << "BitFlagTracker object is " << sizeof(bit_tracker) << " byte(s) in size" << std::endl;

  // used so we only have to cast the
  // looping variable once
  BoolFlagTracker::BOOL_FLAG bool_flag;
  BitFlagTracker::BIT_FLAG bit_flag;

  for (int i = 0; i < BoolFlagTracker::NUM_FLAGS; ++i)
  {
    // cast looping variable into our two different
    // types and numbering systems
    bool_flag = BoolFlagTracker::BOOL_FLAG(i);
    bit_flag = BitFlagTracker::BIT_FLAG(int(std::pow(2, i)));

    // check default setting, should be false
    if (bool_tracker.GetFlag(bool_flag) || bit_tracker.GetFlag(bit_flag))
      FAILURE;

    // check the flag after setting to true
    bool_tracker.SetFlag(bool_flag, true);
    bit_tracker.SetFlag(bit_flag);
    if (!(bool_tracker.GetFlag(bool_flag) && bit_tracker.GetFlag(bit_flag)))
      FAILURE;

    // check the flag after setting to false
    bool_tracker.SetFlag(bool_flag, false);
    bit_tracker.UnsetFlag(bit_flag);
    if (bool_tracker.GetFlag(bool_flag) || bit_tracker.GetFlag(bit_flag))
      FAILURE;

    // set the flag to true, to check for cross-flag pollution
    // in the following loops
    bool_tracker.SetFlag(bool_flag, true);
    bit_tracker.SetFlag(bit_flag);
  }

  std::cout << "The two flag trackers have identical behavior" << std::endl;

  PrintWithFlags("PrintWithFlags where no flags are set");
  PrintWithFlags("PrintWithFlags where INDENT is set", INDENT);
  PrintWithFlags("PrintWithFlags where INDENT and ADD_HELLO are set", INDENT | ADD_HELLO);
  PrintWithFlags("PrintWithFlags where INDENT and PRINT_5 are set", INDENT | PRINT_5);
  PrintWithFlags("PrintWithFlags where everything is set manually", INDENT | PRINT_5 | PRINT_PI | ADD_HELLO);
  PrintWithFlags("PrintWithFlags where everything is set via shortcut", 0xFF);
  return 0;
}
#endif