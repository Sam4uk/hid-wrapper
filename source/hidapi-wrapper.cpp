#include "hidapi-wrapper.hpp"

#include <hidapi/hidapi.h>

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

hidDevice::hidDevice(const char* path) : device{hid_open_path(path)} {
  // if (!device) throw std::runtime_error("NO DIVICE");
}

hid_device* hidDevice::open(const char* path) {
  return device = hid_open_path(path);
}

hid_device_info* hidDevice::getInfo() { return hid_get_device_info(device); }

int hidDevice::read(uint8_t* data, size_t length) {
  return hid_read(device, data, length);
}

int hidDevice::read(uint8_t* data, size_t length, int time) {
  return hid_read_timeout(device, data, length, time);
}

hidDevice::~hidDevice() { hid_close(device); }

}  // namespace HW::hid