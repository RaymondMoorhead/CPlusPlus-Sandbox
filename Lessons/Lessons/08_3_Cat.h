// safety to make sure file is included only once, never duplicated
#pragma once

#include "08_2_BaseDeclarations.h"

class Cat : public Animal {
  public:
    // override clarifies your intention to override
    // a function of the same name from the base class
    const char* Personality() override;
    const char* Speak() override;
};