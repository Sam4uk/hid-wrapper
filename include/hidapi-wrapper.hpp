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
  hidDevice(const char* path);  //: device{hid_open_path(path)} {
  //   // if (!device) throw std::runtime_error("NO DIVICE");
  // }
  hid_device* open(
      const char* path);  //{ return device = hid_open_path(path); }

  int read(uint8_t* data, size_t length);  // {
  //   return hid_read(device, data, length);
  // }
  ~hidDevice();  //{ hid_close(device); }
};

}  // namespace HW::hid
