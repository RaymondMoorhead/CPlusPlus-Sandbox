// safety to make sure file is included only once, never duplicated
#pragma once

#include "08_2_BaseDeclarations.h"

class Dog : public Animal {
  public:
    const char* Speak() override;
};