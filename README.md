# Orion Chassis Driver Mk. II

## Description

This is continuation of [the first version of chassis driver](https://gitlab.com/SteelPh0enix/orion-chassis-driver), adapted to new driver hardware

## Hardware

This driver is based on 4x BTS7960, half-bridges each for every wheel. Microcontroler of choice is ATMega2560 on Arduino Mega board. For this version, custom prototype board was created as an interface between Arduino board and BTS7960 drivers.

## Software

As much software and patterns from previous version of driver as possible will be used, because of it's modularity. However, some refactors will be made, as well as addition of some features.

### Planned additions (low-priority, good-to-have features)

* Changing PWM frequency to eliminate driver noise
* [nanopb](https://jpa.kapsi.fi/nanopb/) support for communication