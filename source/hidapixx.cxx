#include "hidapixx.hxx"
#include <hidapi/hidapi.h>
#include <mutex>

namespace hw::hid {
std::mutex Context::_mutex;
std::atomic<int> Context::_refs{};

Context::Context() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (0 == _refs++) {
    if (!hid_init()) {
      _refs--;
      // errr
    }
  }
}

Context::~Context() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (0 == --_refs)
    hid_exit();
}

HidDevice::HidDevice() : _device{nullptr} {}

HidDevice::~HidDevice() {}

HidDevice::HidDevice(vid_t, pid_t) : HidDevice() {}

} // namespace hw::hid