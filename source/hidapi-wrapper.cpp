#include "hidapi-wrapper.hpp"

#include <hidapi/hidapi.h>

#include <boost/log/trivial.hpp>

namespace HW::hid {
HIDapi::HIDapi() {
  if (0 > hid_init()) {
  }
  //   throw std::runtime_error("Не вдалося ініціалізувати
  //   hidapi  ");
}

HIDapi::~HIDapi() { hid_exit(); }

HIDapi& HIDapi::Instance() {
  static HIDapi theInstance{};
  return theInstance;
}

hidDevice::hidDevice() : device{nullptr} {}

hidDevice::hidDevice(char const* path) : hidDevice() {
  device = hid_open_path(path);
}

int hidDevice::read(unsigned char* data, size_t length) {
  return hid_read(device, data, length);
}

hidDevice::~hidDevice() {}

}  // namespace HW::hid
// #include <hidapi/hidapi.h>
// #include <mutex>

// namespace hw::hid {
// std::mutex Context::_mutex;
// std::atomic<int> Context::_refs{};

// Context::Context() {
//   std::lock_guard<std::mutex> lock(_mutex);
//   if (0 == _refs++) {
//     if (!hid_init()) {
//       _refs--;
//       // errr
//     }
//   }
// }

// Context::~Context() {
//   std::lock_guard<std::mutex> lock(_mutex);
//   if (0 == --_refs)
//     hid_exit();
// }

// HidDevice::HidDevice() : _device{nullptr} {}

// HidDevice::HidDevice(vid_t, pid_t) : HidDevice() {}

// } // namespace hw::hid