import keyboard
import json
import copy
import serial

CHASSIS_SERIAL_PORT = "COM7"
CHASSIS_SERIAL_BAUD = 115200

CHASSIS_SERIAL = serial.Serial()
CHASSIS_SERIAL.baudrate = CHASSIS_SERIAL_BAUD
CHASSIS_SERIAL.port = CHASSIS_SERIAL_PORT

CHASSIS_DATA_JSON = {
    "X": 0,
    "Y": 0,
}

POWER_STEP = 10


def sendDataToChassis(data):
    data_to_send = (json.dumps(data, separators=(',', ':')) +
                    '\r\n').encode('ascii')
    print(data_to_send)
    CHASSIS_SERIAL.write(data_to_send)
    print(CHASSIS_SERIAL.readline())


def setFieldAndSend(field, value):
    CHASSIS_DATA_JSON[field] = value
    sendDataToChassis(CHASSIS_DATA_JSON)


def stopChassis():
    CHASSIS_DATA_JSON["X"] = 0
    CHASSIS_DATA_JSON["Y"] = 0
    sendDataToChassis(CHASSIS_DATA_JSON)


if __name__ == "__main__":
    CHASSIS_SERIAL.open()

    keyboard.add_hotkey("w", lambda: setFieldAndSend(
        "Y", CHASSIS_DATA_JSON["Y"] + POWER_STEP))
    keyboard.add_hotkey("x", lambda: setFieldAndSend(
        "Y", CHASSIS_DATA_JSON["Y"] - POWER_STEP))
    keyboard.add_hotkey("a", lambda: setFieldAndSend(
        "X", CHASSIS_DATA_JSON["X"] + POWER_STEP))
    keyboard.add_hotkey("d", lambda: setFieldAndSend(
        "X", CHASSIS_DATA_JSON["X"] - POWER_STEP))
    keyboard.add_hotkey("s", lambda: stopChassis())

    keyboard.wait()
