#include "TimerManager.h"

#include "../../Engine/Maps/Assets/Maps_Tilesets.h"

// Timer used for the game
Timer GameTimer;

// Create timer from a duration in seconds
Timer* TimerManager_CreateTimer(UINT8 _DurationSeconds)
{
    GameTimer.nbFrameElapsed = 0;
    GameTimer.durationSeconds = _DurationSeconds;
}

// Update number of frame elapsed on specified timer
void TimerManager_UpdateTimer(Timer* _Timer)
{
    if (_Timer != NULL)
    {
        // Ensure nb frame elapsed is reset
        if (_Timer->nbFrameElapsed > TIMER_SECONDTOFRAME - 1)
            _Timer->nbFrameElapsed = 0;

        // Update timer
        _Timer->nbFrameElapsed++;

        if (_Timer->nbFrameElapsed > TIMER_SECONDTOFRAME - 1)
        {
            if (_Timer->durationSeconds > 0)
            {
                _Timer->durationSeconds--;

                // Update feedback on map
                switch (_Timer->durationSeconds)
                {
                    case 0:
                        set_bkg_tiles(17, 8, 1, 1, MapsTileset0 + 125);
                        break;

                    case 1:
                        set_bkg_tiles(17, 9, 1, 1, MapsTileset0 + 125);
                        break;

                    case 2:
                        set_bkg_tiles(17, 10, 1, 1, MapsTileset0 + 125);
                        break;

                    case 3:
                        set_bkg_tiles(17, 11, 1, 1, MapsTileset0 + 125);
                        break;

                    case 4:
                        set_bkg_tiles(17, 12, 1, 1, MapsTileset0);
                        break;
                }
            }
        }
    }
}

// Reset number of frame elapsed on specified timer
void TimerManager_ResetTimer(Timer* _Timer)
{
    if (_Timer != NULL)
        _Timer->nbFrameElapsed = 0;
}

// Check if number of frame elapsed is greater (or equals) than duration on specified timer
UINT8 TimerManager_IsTimerReached(Timer* _Timer)
{
    if (_Timer != NULL)
        return _Timer->nbFrameElapsed > TIMER_SECONDTOFRAME - 1 && _Timer->durationSeconds < 1;

    return FALSE;
}