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

<<<<<<< HEAD
// HidDevice::HidDevice(vid_t, pid_t) : HidDevice() {}

// } // namespace hw::hid
=======
hidDevice::~hidDevice() { hid_close(device); }

}  // namespace HW::hid
>>>>>>> a824571d75287eecb66a5a4e1cc1685cf0fda255
