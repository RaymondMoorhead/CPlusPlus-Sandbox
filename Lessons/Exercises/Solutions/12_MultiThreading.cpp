#include <pthread.h>
#include <iostream> // use printouts to find bugs

// your goal here is to sum the contents of the given buffer using threads,
// and return the result. You can, and in fact are expected, to create
// additional functions and variables in the global scope to accomplish
// this task

// here I create a struct which I can pass instances of to the thread function
struct SumThreadData
{
  pthread_t thread;
  unsigned* start;
  unsigned size;
};

// for my implementation I use a mutex and global unsiged integer to sum
// the data, but it's also quite possible to sum the threads individually
// and return that sum to the main thread, where those values are summed
// during the joining process.

//globals for all threads
pthread_mutex_t MUTEX;
unsigned THREAD_SUM;

// this is the thread function itself, most of the hard work is done in the
// function which creates the threads and determines which one is working
// with which part of the buffer
void* Sum(void* data)
{
  SumThreadData* true_data = reinterpret_cast<SumThreadData*>(data);
  unsigned local_sum = 0;
  for (unsigned i = 0; i < true_data->size; ++i)
    local_sum += true_data->start[i];

  pthread_mutex_lock(&MUTEX);
  THREAD_SUM += local_sum;
  pthread_mutex_unlock(&MUTEX);
  return nullptr;
}

// for the purposes of this exercise, 'size' will always be divisible by num_threads
unsigned SumBufferContents(unsigned* buffer, unsigned size, unsigned num_threads)
{
  int error;
  SumThreadData* data;
  data = new SumThreadData[num_threads];
  THREAD_SUM = 0;

  // set the thread data
  unsigned long thread_calc_size = size / num_threads;
  for (unsigned i = 0; i < num_threads; ++i)
  {
    data[i].size = thread_calc_size;
    data[i].start = buffer + (thread_calc_size * i);
  }

  // initialize the mutex
  pthread_mutex_init(&MUTEX, nullptr);

  // create the threads
  for (unsigned i = 0; i < num_threads; ++i)
  {
    error = pthread_create(&data[i].thread, nullptr, Sum, (void*)(data + i));
    if (error) {
      std::cout << "Unable to create thread " << i << ", " << error << std::endl;
      return -1;
    }
  }

  // join the threads
  for (unsigned i = 0; i < num_threads; ++i)
  {
    error = pthread_join(data[i].thread, nullptr);
    if (error) {
      std::cout << "Error:unable to join thread " << i << ", " << error << std::endl;
      return -1;
    }
  }

  // destroy the mutex
  pthread_mutex_destroy(&MUTEX);

  delete [] data;
  return THREAD_SUM;
}