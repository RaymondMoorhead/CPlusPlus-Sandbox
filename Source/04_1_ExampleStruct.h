// so structs and classes are both very much
// like java classes, they contain variables
// and functions, have a constructor, and so
// forth
struct ExampleStruct {

  int num;
  void SetNum(int number);
  void SubtractTwoFromNum();
  void printNum();
};

// this one inherits from the last one,
// which is exactly like extending- except
// you have to set the access specifier
struct InheritingExampleStruct : public ExampleStruct {


  int another_num;
};