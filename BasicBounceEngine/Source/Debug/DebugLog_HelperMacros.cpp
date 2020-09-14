#include "DebugLog_HelperMacros.h"

namespace Debug
{
  // strips the Windows style path from a filename
  constexpr const char* FILENAME(const char* path) {
    const char* file = path;
    while (*path)
      if (*path++ == '\\')
        file = path;
    return file;
  }
}