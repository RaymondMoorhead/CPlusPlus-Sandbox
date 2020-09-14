#pragma once

#include <vector>
#include "BasicObject.h"
#include "../Graphics/BasicGraphics.h"

class BasicCore
{
  bool running_;
  float delta_time_;
  long long last_time_;
  long long current_time_;

  public:
    BasicCore();
    void Initialize();
    void Update();
    void Shutdown();
    bool IsRunning();
    float GetDeltaTime();

    std::vector<BasicObject*> objects;
    BasicGraphics graphics;
};