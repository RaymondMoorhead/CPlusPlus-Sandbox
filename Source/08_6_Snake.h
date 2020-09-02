#pragma once

#include "08_2_BaseDeclarations.h"

class Snake : public Animal
{
  public:
    const char* Speak() override;
    const char* Features() override;
};