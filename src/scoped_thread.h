#ifndef BNTL_SCOPED_THREAD
#define BNTL_SCOPED_THREAD
#include <thread>
#include <utility>
#include <iostream>

namespace bntl
{
class scoped_thread
{
public:
    template <typename... Arg>
    scoped_thread(Arg &&... arg) : thread_(std::forward<Arg>(arg)...) {}
    scoped_thread(scoped_thread &&other) : thread_(std::move(other.thread_)) {}
    scoped_thread(const scoped_thread &) = delete;
    ~scoped_thread()
    {
        if (thread_.joinable())
        {
            thread_.join();
        }
    }

private:
    std::thread thread_;
};
} // namespace bntl

#endif // BNTL_SCOPED_THREAD
