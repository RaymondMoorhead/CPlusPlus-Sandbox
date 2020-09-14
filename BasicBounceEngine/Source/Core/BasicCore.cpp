#include "BasicCore.h"
#include "../Debug/DebugLog.h"
#include <chrono>
#include "ImGui/imgui.h"

#define TIME_NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

BasicCore::BasicCore() : running_(true), delta_time_(0.0f), last_time_(0), current_time_(TIME_NOW)
{
  ERASE_LOG;
  LOG("BasicCore::BasicCore complete");
}

void BasicCore::Initialize()
{
  graphics.Initialize();
  LOG("BasicCore::Initialize complete");
}

void BasicCore::Update()
{
  last_time_ = current_time_;
  current_time_ = TIME_NOW;
  delta_time_ = float(float(current_time_ - last_time_) / 1000.0);

  for (auto it = objects.begin(); it != objects.end(); ++it)
    (*it)->Update(delta_time_);

  if (graphics.Draw(delta_time_, &objects))
    Shutdown();
}

void BasicCore::Shutdown()
{
  LOG("Shutdown called");
  running_ = false;
  graphics.Exit();
  LOG("BasicGraphics::Exit completed");
}

bool BasicCore::IsRunning()
{
  return running_;
}

float BasicCore::GetDeltaTime()
{
  return delta_time_;
}