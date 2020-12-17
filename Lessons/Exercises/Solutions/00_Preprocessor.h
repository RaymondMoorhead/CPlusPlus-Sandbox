// write a loop that will execute
// a statement X number of times
#define DO_X_TIMES(Statement, X) \
  for(unsigned i = 0; i < X; ++i) \
    Statement;
