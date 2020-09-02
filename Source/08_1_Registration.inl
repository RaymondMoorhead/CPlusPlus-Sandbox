// this file exists almost purely for the pre-processor

#ifndef INCLUDES
REGISTER(Cat)
REGISTER(Dog)
REGISTER(Mouse)
REGISTER(Snake)
#else
#include "08_3_Cat.h"
#include "08_4_Dog.h"
#include "08_5_Mouse.h"
#include "08_6_Snake.h"
#endif

// doing stuff like this, where a file is included in multiple places
// and will be completely different depending on what is defined where,
// will seriously confuse the compiler. It may be telling you there are
// errors anywhere and everywhere in this file, maybe even the comments
// depending on its mood. These 'Phantom Erors' can change second-by-second