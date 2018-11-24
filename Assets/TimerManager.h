#ifndef DEF_TIMERMANAGER

#define DEF_TIMERMANAGER

#include <gb/gb.h>

#define TIMER_SECONDTOFRAME 1

/** Structs **/

// Struct used to define timer data
struct Timer
{
    // Number of frames elapsed
    UINT8 nbFrameElapsed;

    // Duration of timer in seconds
    UINT8 durationSeconds;
};
typedef struct Timer Timer;

/** Exposed function **/

// Create timer from a duration in seconds
Timer* TimerManager_CreateTimer(UINT8 _DurationSeconds);

// Update number of frame elapsed on specified timer
void TimerManager_UpdateTimer(Timer* _Timer);

// Reset number of frame elapsed on specified timer
void TimerManager_ResetTimer(Timer* _Timer);

// Check if number of frame elapsed is greater (or equals) than duration on specified timer
UINT8 TimerManager_IsTimerReached(Timer* _Timer);

/** Exposed Variables **/

// Timer used for the game
extern Timer GameTimer;

#endif