// The pre-processor is what runs before compilation of code even
// begins, it doesn't care about data types or values or anything
// else that would be considered normal code, and it will only
// pass over each file once, no recursion here- though there are
// some caveats we'll get to eventually. What's important is that
// there are certain commands you can use to either enhance or
// completely restructure code before compilation, allowing for
// amazing things

// this is a macro/define, in this case it is declaring the
// existence of the define HELLO_WORLD
#define HELLO_WORLD

// now I can do pre-processor 'if checks' like this:

#ifdef HELLO_WORLD
  // code that executes if HELLO_WORLD has been defined
#else
  // else is optional, but if it's there...
#endif // end the conditional blocks, this is mandatory

// you can also do something if it's not defined
#ifndef HELLO_WORLD
  // code that executes if HELLO_WORLD wasn't defined
#endif

// you can also assign a value to a define, and at the pre-processing
// stage it will replace the define with its value, so it's as if
// it was always just the value
#define GREETINGS "Greetings!"
#define PI 3.14159
#define PI_FLOAT 3.14159f

// now defines start to get really interesting and really weird
// when you start using their more particular functionalities

// inside of a define, using '#' before something puts '"' around it,
// which turns it into a string for compilation
#define GREETINGS_STRINGEFY #Greetings!
// same as "Greetings!"

// inside of a define, using two '#' between items will glue them
// together, turning them into a single identifier for compilation
#define MAKE_HELLO_WORLD Hello ## World
// this would result in the identifier HelloWorld

// defines can also be used as functions which don't care about type,
// be careful when doing this because the compiler will have no idea
// where the error is coming from if one arises
#define ADD(X, Y) X + Y
#define STRINGEFY(X) #X
#define CONCATENATE(X, Y) X ## Y

// if you want to stretch defined functions over multiple lines, use
// the '\' character at the end
#define LOOP_UNTIL_X(X) \
  for(int i = 0; i < X; ++i)
    // oh yes, you can leave this loop open, remember that with defines
    // it's as if you did a find-and-replace for every instance

// the following is defined out to prevent compiler
// erors due to code in the global scope
#if 0 // basically an 'if(false)'
  // for these purposes assume you have a function called 'print'

  // consider this:
  LOOP_UNTIL_X(5)
  print("Hello"); // print 'Hello' 5 times

  // and yes, this would also work
  LOOP_UNTIL_X(5)
  print(i); // where is i declared? Well, in the define of course

  // prints "HelloWorld"
  print(STRINGEFY(CONCATENATE(Hello, World)));

  // prints 15
  print(STRINGEFY(ADD(10, 5)))

  // compiler error, but if you're unlucky it
  // will tell you the error is on the line
  // where the macro ADD was created
  print(STRINGEFY(ADD(10, SomeObject)))

#endif

// there is more, but it would require delving into tangential topics
