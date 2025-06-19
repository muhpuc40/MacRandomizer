#ifndef MAC_RANDOMIZER_H
#define MAC_RANDOMIZER_H

#include <Arduino.h>

class MacRandomizer {
public:
    MacRandomizer();
    void begin();
    void randomizeMAC();
    String getMACString() const;
private:
    uint8_t newMAC[6];
    void generateRandomMAC();
};

#endif
