#include "napi.h"
#include <iostream>

using namespace std;

Napi::Boolean run_addon(const Napi::CallbackInfo &info)
{
  // This is the `name`
  auto name = info[0].As<Napi::String>().Utf8Value();

  cout << "Running module. First arg is: " << name << "\n";

  Napi::Env env = info.Env();
  Napi::Object global = env.Global();
  // I can get a reference like this...
  // Ideally, I want to find out how to do everything
  // in C++ (no JS runtime or globals)
  Napi::Function greet = global.Get("doJs").As<Napi::Function>();

  greet.Call({ Napi::String::From(env, name) });
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  // Register exports.
  // In JS:
  // exports.Method = execute_runtime
  exports.Set(Napi::String::New(env, "method"),
              Napi::Function::New(env, run_addon));

  // Need to return the `exports` object.
  return exports;
}

NODE_API_MODULE(addon, Init)