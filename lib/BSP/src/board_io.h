// #pragma once
#ifndef _board_io_h_
#define _board_io_h_

#include "Arduino.h"
#include "Arduino_FreeRTOS.h"
#include "SoftwareSerial.h"
#include "EEPROM.h"
#include "CRC32.h"

#ifndef ENABLE
    #define ENABLE  HIGH
#endif

#ifndef DISABLE
    #define DISABLE LOW
#endif

#define S1_tentacles_pin    6
#define S0_tentacles_pin    7

#define E1_tentacles_pin    5
#define E2_tentacles_pin    4

#define SET_PIN(pin)        digitalWrite(pin, HIGH)
#define CLEAR_PIN(pin)      digitalWrite(pin, LOW)



#define EZO_TX_PIN          10
#define EZO_RX_PIN          11

#define SERIAL_BAUD         9600

#define UniqueIDsize        9

struct timeDateParam{
    uint8_t date, month, year;
};
struct calibrationParam{
    float slope, offset;
};
struct deviceParam{

    float elevation;

    timeDateParam pH_timedate_calibration;
    timeDateParam DO_timedate_calibration;
    timeDateParam EC_timedate_calibration;

    calibrationParam pH_calibration_parameter;
    calibrationParam DO_calibration_parameter;
    calibrationParam EC_calibration_parameter;

    float pH_precision,
          DO_precision,
          EC_precision,
          water_temperature_precision;
};

const char boardKey[][4] = {"pH", "DO", "EC", "RTD"};

extern deviceParam deviceParameter;

extern char serialDevice[UniqueIDsize+1];

void reset_device_parameter(void);
void setup_bsp(void);

void tentacles_open_channel(uint8_t ch);


//=========== eeprom buffer
#define EEPROM_START_ADDR   1


bool initializeMemory(void);
bool backUpMemory(void);
bool resetMemory(void);



#endif