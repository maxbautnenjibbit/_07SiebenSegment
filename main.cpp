/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

int SEGMENTE [10] = {
                      0b00111111,
                      0b00000110,
                      0b01011011,
                      0b01001111,
                      0b01100110,
                      0b01101101,
                      0b01111101,
                      0b00000111,
                      0b01111111,
                      0b01101111
                    };

void vorEins() {
    DigitalOut einerstelle(PC_11);
    PortOut segment(PortC, 0xFF);
    PortIn dipIn(PortB, 0xFF);

    dipIn.mode(PullDown);

    einerstelle = 1;

    while (true) {
        segment = dipIn;
    }
}

void eins() {
    DigitalOut einerstelle(PC_11);
    PortOut segment(PortC, 0xFF);

    einerstelle = 1;

    while (true) {
        segment = SEGMENTE [0];

        ThisThread::sleep_for(500ms);

        //...
    }
}

void zwei() {
    DigitalOut einerstelle(PC_11);
    PortOut segment(PortC, 0xFF);

    einerstelle = 1;

    while (true) {
        for (int i = 0; i < 10; i++) {
            segment = SEGMENTE [i];

            ThisThread::sleep_for(500ms);
        }
    }
}

void drei() {
    DigitalOut einerstelle(PC_11);
    PortOut segment(PortC, 0xFF);

    DigitalIn taste(PA_10);
    taste.mode(PullDown);

    einerstelle = 1;

    int caze = 0;

    while (true) {
        if (taste) {
            caze++;

            if (caze >= 10) {
                caze = 0;
            }
            
            segment = SEGMENTE [caze];

            while (taste) {

            }
        }
    }
}


int main()
{
    drei();
}
