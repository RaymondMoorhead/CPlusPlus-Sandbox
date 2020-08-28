// what's the difference between a struct and 
// a class? Almost none, except that in C++ the
// access specifiers are not per variable or
// function, but rather for huge blocks of code.
// And in structs the access defaults to 'public'
// and in classes it defaults to 'private'

class ExampleClass {
  // this is private, and cannot be accessed outside of the class
  int num;

  public:
    // non-default constructor
    ExampleClass(int num);
    // destructor, called when object is deleted or is out-of-scope
    ~ExampleClass();

    int getNum();
    void setNum(int number);
    void printNum();

  protected:
    // code you only want your children to see
  private:
    // code you want nobody to see
  
};

