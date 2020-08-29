// safety to make sure file is included only once, never duplicated
#pragma once

#include "08_2_BaseDeclarations.h"

class Mouse : public Animal {
  public:
    // 'override' is actually optional,
    // but it's a best practice to use it
    // when you intend to override something
    const char* Features();
    const char* Speak() override;
};