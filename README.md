# Orion Chassis Driver Mk. II

## Description

This is continuation of [the first version of chassis driver](https://gitlab.com/SteelPh0enix/orion-chassis-driver), adapted to new driver hardware

## Hardware

This driver is based on 4x BTS7960, half-bridges each for every wheel. Microcontroler of choice is ATMega2560 on Arduino Mega board. For this version, custom prototype board was created as an interface between Arduino board and BTS7960 drivers.

## Software

As much software and patterns from previous version of driver as possible will be used, because of it's modularity. However, some refactors will be made, as well as addition of some features.

### Planned additions (low-priority, good-to-have features)

* ~~Changing PWM frequency to eliminate driver noise~~ - not a thing, because of Arduino limitations
* [nanopb](https://jpa.kapsi.fi/nanopb/) support for communication

## BTS7960 characteristics

BTS7960 is half-bridge power driver. We are using COTS modules which have two of them, making it effectively H-bridge.

### Maximum ratings

Each BTS7960 has the following maximum ratings:

* Supply voltage: -0.3V to 45V
* Logic supply voltage: -0.3V to 5.3V
* Continuous drain current: +/- 40A
* Pulsed drain current: +/- 60A (tpulse = 10ms)
* Maximum junction temperature: 150°C
* Maximum PWM frequency: 25kHz