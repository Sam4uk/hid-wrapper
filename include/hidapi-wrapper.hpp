#pragma once

#include <hidapi/hidapi.h>

#include <cstdint>

// #include <atomic>
// #include <hidapi/hidapi.h>

// #include <map>
// #include <string>
// #include <thread>
// #include <atomic>
// // #include <mutex>
namespace HW::hid {
class HIDapi final {
 private:
  HIDapi();

  ~HIDapi();
  HIDapi(const HIDapi&) = delete;
  HIDapi(HIDapi&&) = delete;
  HIDapi& operator=(const HIDapi&) = delete;
  HIDapi& operator=(HIDapi&&) = delete;

 public:
  static HIDapi& Instance();
};

class hidDevice {
  hid_device* device;

 public:
  hidDevice();
  hidDevice(const char* path);
  hid_device* open(const char* path);

  int read(uint8_t* data, size_t length);
  int read(uint8_t* data, size_t length, int time);
  ~hidDevice();
};

}  // namespace HW::hid
