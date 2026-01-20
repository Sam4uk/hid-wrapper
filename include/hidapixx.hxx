#pragma once

#include <atomic>
#include <hidapi/hidapi.h>
#include <mutex>
namespace hw::hid {
class Context {
public:
  Context();
  ~Context();

  Context(const Context &) = delete;
  Context &operator=(const Context &) = delete;

private:
  static std::mutex _mutex;
  static std::atomic<int> _refs;
};

class HidDevice {
private:
  Context _context;
  hid_device *_device;
  HidDevice();

public:
  typedef uint16_t vid_t;
  typedef uint16_t pid_t;
  struct vid_pid_t {
    vid_t vid;
    pid_t pid;
  };
  HidDevice(vid_t, pid_t);
  HidDevice(vid_pid_t);
  ~HidDevice();

  HidDevice(const HidDevice &) = delete;
  HidDevice &operator=(const HidDevice &) = delete;

  HidDevice(HidDevice &&) = delete;
  HidDevice &operator=(HidDevice &&) = delete;

  void write();
  void read();
  void stop();
  bool isOpen();
};

}; // namespace hw::hid