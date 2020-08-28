// safety to make sure file is included only once, never duplicated
#pragma once

#include "08_2_BaseDeclarations.h"

class Cat : public Animal {
  public:
    Cat();

    const char* Personality() override;
    const char* Speak() override;
};