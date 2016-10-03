#pragma once

class Timer {
private:
    Uint32 startTicks;
    Uint32 pausedTicks;
    bool paused;
    bool started;
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    Uint32 get_ticks();

    bool is_started();
    bool is_paused();
};
