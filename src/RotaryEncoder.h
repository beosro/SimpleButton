#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Button.h"
#include "ButtonPullup.h"
#include "PCF8574.h"
#include "PCF8575.h"
#include "ButtonPCF.h"
#include "ButtonPullupPCF.h"

namespace simpleButton {
    class RotaryEncoder {
        public:
            Button* clockwise     = NULL;
            Button* anticlockwise = NULL;
            Button* button        = NULL;

            RotaryEncoder();
            RotaryEncoder(uint8_t channelA, uint8_t channelB);
            RotaryEncoder(uint8_t channelA, uint8_t channelB, uint8_t button);
            RotaryEncoder(PCF857x* pcf, uint8_t channelA, uint8_t channelB);
            RotaryEncoder(PCF857x* pcf, uint8_t channelA, uint8_t channelB, uint8_t button);
            RotaryEncoder(Button* clockwise, Button* anticlockwise, Button* button);
            ~RotaryEncoder();

            void update();
            void update(bool stateA, bool stateB, bool buttonState);

            void reset();

            int32_t getPos();

            void setButtons(Button* clockwise, Button* anticlockwise, Button* button);
            void setPos(int32_t pos);
            void setSteps(uint8_t steps);

        private:
            int32_t pos = 0;

            bool prevA = false;
            bool prevB = false;

            enum State { STILL = 0, CLOCKWISE = 1, ANTICLOCKWISE = 2 };
            State curState  = State::STILL;
            State prevState = State::STILL;

            uint8_t button_steps = 1; // how many steps per turn
            uint8_t steps        = 0; // tmp counter
    };
}

#endif // ifndef RotaryEncoder_h