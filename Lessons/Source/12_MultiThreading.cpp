// FOR THOSE WHO UNDERSTAND HOW THREADS WORK, SKIP TO THE INCLUDE STATEMENT

// Writing multithreaded code means writing code which
// can be run by multiple cores at the same time, the
// EXACT same time. The primary issues in multithreading
// are called 'data races' and are due to non-atomic
// operations occurring simultaneously. In Layman's terms
// this means that it may take 4 steps to do something simple,
// and threads will interfere with each other as a result.
// Consider this example:

// Assume it takes 3 steps to increment a value
//  1: Read value from memory
//  2: Increment value
//  3: Write value back to memory

// Now assume you have two threads incrementing something,
// they will only work 'as expected' when their operation
// order is something like this:

// | THREAD 1 | THREAD 2 | VALUE IN MEMORY |
// |----------|----------|-----------------|
// | read     |          | 0               |
// | inc      |          | 0               |
// | write    |          | 1               |
// |          | read     | 1               |
// |          | inc      | 1               |
// |          | write    | 2               |

// So our final value is 2. However, the moment they try to
// act at the same time, issues arise:

// | THREAD 1 | THREAD 2 | VALUE IN MEMORY |
// |----------|----------|-----------------|
// | read     |          | 0               |
// | inc      |          | 0               |
// |          | read     | 0               |
// |          | inc      | 0               |
// |          | write    | 1               |
// | write    |          | 1               |

// And our final value is 1. This is because one thread read the
// value from memory, then was stopped by the operating system
// (so the OS could let Discord, Visual Studio, or some other
// program run a few cycles), and during that time the other
// thread read in data from memory, performed some operations, and
// write out again. During that whole time the first thread was
// still holding on to the data it originally received.

// This issue can be resolved with mutexes and semaphores. A Mutex
// is a lock-and-key solution where one thread can 'lock' a resource,
// perform some operation with it, and then 'unlock' it so another
// thread can use it. A semaphore is similar, but allows for a resource
// to be split up into sections that can be independently operated on.
// In other words, for a 4 kilobyte buffer:
//    A mutex locks the whole buffer so one thread can use it
//    A semaphore can lock 1 kilobyte sections which have up to one thread each

// So that is more or less how threads work, and their primary issue.
// Now let's look at a C++ implementation. Specifically we'll be using
// Posix threads because they have more cross-platform support. There
// are also Windows threads which work pretty much the same way

#ifdef _MSC_VER // Visual Studio Version
  // Visual Studio doesn't come with pthread support,
  // so it has been included in a modified form as a
  // project dependency
  #include "pthread/pthread.h"
#elif
  // Other compilers, such as g++, should be able to
  // include it as a fundamental library
  #include <pthread.h>
#endif

#include <iostream>

// the mutex, it must be in a scope the thread function can see
pthread_mutex_t mutex;

// a global variable our thread function will use
unsigned total_sum = 0;

// Posix thread functions must take and return a void pointer,
// and cannot be a non-static member function. This is because
// class/struct member functions have an implicit 'this' variable
// which would not be filled.
void* CalculateSumsUpTo(void* data)
{
  // Do something the thread can do on it's own without interferance
  unsigned sum_max = *reinterpret_cast<unsigned*>(data);
  unsigned* sum = new unsigned(0);
  for (unsigned i = 1; i <= sum_max; ++i)
    *sum += i;

  // Now lock the mutex to do something with a resource other threads
  // may use
  pthread_mutex_lock(&mutex);

  // In this case we're simply adding our calculation to total_sum
  total_sum += *sum;

  // Now unlock the mutex
  pthread_mutex_unlock(&mutex);

  // Here we return the calculated sum as a heap allocated int,
  // but you could return just about anything as long as it's cast
  // to a void pointer and the receiving code knows what to do with it.
  return sum;
}

// Windows threads use windows specific macros which obfuscate the types.
//
// You would format your function like this:
//    DWORD WINAPI MyThreadFunction( LPVOID lpParam );
//
// Which effectively resolves to this:
//    unsigned __stdcall MyThreadFunction( void* lpParam );

#if 0
int main(int argc, char* argv[])
{
  const unsigned num_threads = 10;
  int error;
  void* return_value;

  // structs which will contain the thread's
  // identifying information
  pthread_t threads[num_threads];

  // initialize the mutex
  pthread_mutex_init(&mutex, nullptr);

  // the data we'll pass into the threads for this demo,
  // it could be anything as long as it's cast correctly
  unsigned data[num_threads] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
  };

  // loop for creating threads
  for (unsigned i = 0; i < num_threads; ++i)
  {
    std::cout << "Creating thread " << i << std::endl;

    // pthread_create takes in the following:
    //    pthread_t*      => the pointer to the data for a particular thread, pthread_create fills it
    //    pthread_attr_t  => a set of attributes we can pass into a thread (optional)
    //    void*(*)(void*) => a pointer to a function that takes and returns a void pointer
    //    void*           => the data we want to use in the function, passed in as a void pointer
    error = pthread_create(&threads[i], nullptr, CalculateSumsUpTo, (void*)(data + i));

    if (error)
    {
      std::cout << "Unable to create thread " << i << ", " << error << std::endl;
      return -1;
    }
  }

  // loop for collecting threads afterwards
  for (unsigned i = 0; i < num_threads; i++) {

    // pthread_join takes in the following:
    //    pthread_t => the data for the particular thread that was set by pthread_create
    //    void**    => a pointer to a void pointer, used to get the return value for the trhead's function
    error = pthread_join(threads[i], &return_value);

    if (error) {
      std::cout << "Error:unable to join thread " << i << ", " << error << std::endl;
      return -1;
    }

    pthread_mutex_lock(&mutex);
    std::cout << "Joined thread " << i
              << " which exited with return value :"
              << *reinterpret_cast<unsigned*>(return_value)
              << std::endl;
    pthread_mutex_unlock(&mutex);

    delete return_value;
  }

  std::cout << "At the end, total_sum is " << total_sum << std::endl;

  // destroy the mutex
  pthread_mutex_destroy(&mutex);

  // ********** IN SUMMARY **********

  // create a pthread_t which will contain the id
  pthread_t someThread;

  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // prepare some kind of data
  unsigned someData = 20;

  // create the thread, giving it a function to use with some data
  error = pthread_create(&someThread, nullptr, CalculateSumsUpTo, (void*)&someData);

  // check the error
  if (error)
    return -1;

  // join the thread, and get it's return value
  void* someReturnValue;
  error = pthread_join(someThread, &someReturnValue);

  // check the error again
  if (error)
    return -1;

  // do something with the return value
  std::cout << "The thread at the end of the lesson returned: " << *reinterpret_cast<unsigned*>(someReturnValue) << std::endl;
  delete someReturnValue;
  
  // destroy the mutex
  pthread_mutex_destroy(&mutex);
}
#endif