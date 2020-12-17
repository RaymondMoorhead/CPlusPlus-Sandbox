// The biggest difference between writing code in Java and C++ is
// arguably the pre-processor.

// The pre-processor is what runs before compilation of code even
// begins, it doesn't care about data types or values or anything
// else that would be considered normal code, and it will only
// pass over each file once, no recursion here- though there are
// some caveats we'll get to eventually. For all intents and
// purposes, you can think of the pre-processor as a fancy
// find and replace feature which modifies your code before
// compilation.

// What's important is that there are certain commands you can
// use to either enhance or completely restructure code before
// compilation, allowing for amazing things

// this is a macro, in this case it is declaring the
// existence (and nothing else) of the macro HELLO_WORLD
#define HELLO_WORLD

// now I can do pre-processor 'if checks' like this:

#ifdef HELLO_WORLD
  // code that executes if HELLO_WORLD has been defined
#else
  // else is optional, but if it's there...
  // code that executes if HELLO_WORLD has not been defined
#endif // end the conditional blocks, this is mandatory

// you can also do something if it's not defined
#ifndef HELLO_WORLD
  // code that executes if HELLO_WORLD wasn't defined
#endif

// Note:  Code in an un-triggered pre-processor if-check isn't even
//        compiled, it's as if it was never part of the code base.
//        This can be used to easily enable debug features for one
//        compiled build, and remove them later with minimal manual
//        code modification.

// you can also assign a value to a macro, and at the pre-processing
// stage it will replace the macro with its value, so it's as if
// it was always just the value
#define GREETINGS "Greetings!"
#define PI 3.14159
#define PI_FLOAT 3.14159f

// now macros start to get really interesting and really weird
// when you start using their more particular functionalities

// inside of a macro, using '#' before something puts '"' around it,
// which turns it into a string for compilation
#define GREETINGS_STRING #Greetings!
// same as "Greetings!"

// inside of a macro, using two '#' between items will glue them
// together, turning them into a single identifier for compilation
#define MAKE_HELLO_WORLD Hello ## World
// this would result in the identifier HelloWorld

// macros can also be used as functions which don't care about type,
// be careful when doing this because the compiler will have no idea
// where the error is coming from if one arises
#define ADD(X, Y) X + Y
#define STRINGEFY(X) #X
#define CONCATENATE(X, Y) X ## Y

// if you want to stretch defined macros over multiple lines, use
// the '\' character at the end
#define MULTIPLE_LINE_MACRO \
  someCodeHere;             \
  moreCodeHere;             \
  lastLine;

// this isn't advisable in actual code, but know you can do this:
#define LOOP_UNTIL_X(X) \
  for(int i = 0; i < X; ++i)
    // oh yes, you can leave this loop open, remember that with defines
    // it's as if you did a find-and-replace for every instance

// the following is defined out to prevent compiler
// erors due to code in the global scope
#if 0 // basically an 'if(false)'

  // for these purposes assume you have a function called 'print'

  // print "Greetings!"
  print(GREETINGS);
  
  // math also works as expected with macros
  PI + (PI * 2);

  // prints "HelloWorld"
  print(STRINGEFY(CONCATENATE(Hello, World)));

  // prints 15
  print(STRINGEFY(ADD(10, 5)));

  // compiler error, but if you're unlucky it
  // will tell you the error is on the line
  // where the macro ADD was created
  print(STRINGEFY(ADD(10, SomeObject)));
  
  // consider this:
  LOOP_UNTIL_X(5)
    print("Hello"); // print "Hello" 5 times

  // and yes, this would also work
  LOOP_UNTIL_X(5)
    print(i); // where is i declared? Well, in the macro of course

#endif

// the following is also defined out to prevent
// compiler erors due to code in the global scope
#if false // this works too

  // Here is an example of when macros go wrong,
  // assume you have a function called 'rand'
  // which gives a random number each time it's
  // called

  // this macro should give the maximum of two
  // given values, but will not work as expected
  #define MAX(A, B) (A < B ? B : A)
  
  // NOTE: the above macro uses the ternary operator,
  //       which is also used in Java. If you don't
  //       know what it is, it checks a condition
  //       and gives back one of two values, such as:
  //       (CONDITION ? VALUE_IF_TRUE : VALUE_IF_FALSE)

  // it does work for these...
  MAX(1, 5);
  MAX(1.0, 5.0);

  // ...but for any changing value it won't
  MAX(1, rand());

  // this is because macros *really are* just
  // a find-and-replace mechanism

  // when the macro is expanded it becomes...
  (1 < rand() ? rand() : 1);

  // ...which can be written as...
  if (1 < rand())
    return rand();
  else
    return 1;

  // see the issue? We expect it to compare and
  // return based on the same randomly generated
  // number, but it actually generates two different
  // numbers. It checks the condition with one, and
  // returns the other if the former is higher.

#endif

// there is more to the preprocessor, but it would require delving into tangential topics

// those new to programming should see the function below,
// those used to java can move on to Lesson 01

// functions are blocks of code that are invoked by calling
// their identifier (their name). These functions can take
// in arguments, things to operate on or with. They can also
// return a value back to where they were called from. If
// you don't want to input or output anything, set the values
// as 'void'

// 'main' is special, because it is implicitly called when
// the program is run. It is the entry point for your program.
// it must take in and return the values show here, we'll get
// into what they actually are later.
int main(int argc, char* argv[])
{
  // program will do nothing, it will start
  // and then promptly end
  return 0;
}