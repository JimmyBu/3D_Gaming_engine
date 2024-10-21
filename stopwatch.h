//
// Created by Jimmy on 10/9/2024.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include<chrono>

class stopwatch {
    public:
        stopwatch() {

        };
        ~stopwatch() {}

    public:
        void start() {
            begin_time_ = std::chrono::system_clock::now();
        }
        void stop() {
            end_time_ = std::chrono::system_clock::now();
        }
        void restart() {
            start();
        }
        std::int64_t nanoseconds() {
            return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_ - begin_time_).count();
        }
        std::int64_t microseconds() {
            return std::chrono::duration_cast<std::chrono::microseconds>(end_time_ - begin_time_).count();
        }
        std::int64_t milliseconds() {
                return std::chrono::duration_cast<std::chrono::milliseconds>(end_time_ - begin_time_).count();
        }
        std::int64_t seconds() {
                return std::chrono::duration_cast<std::chrono::seconds>(end_time_ - begin_time_).count();
        }
    private:
        std::chrono::system_clock::time_point begin_time_;
        std::chrono::system_clock::time_point end_time_;
};

#endif //STOPWATCH_H
