# STM32F4 TMP102 Temperature Sensor Project

This project demonstrates how to interface the **TMP102 temperature sensor** with an **STM32F4 microcontroller** using the HAL library. The system reads temperature data in Celsius and Fahrenheit over I2C, then prints it through UART. Additional helper drivers are included for UART printing and I2C device scanning.

---

---

## 🧩 Included Drivers

### **1. I2C_Scan**

A small utility driver to scan all I2C addresses and print detected devices using UART.

* Helps confirm whether the TMP102 module is connected properly.

### **2. UART_Print**

A custom lightweight `printf` wrapper for HAL UART.

* Helps print formatted messages easily using:

  ```c
  uart_print(&huart1, "Value: %d", x);
  ```

### **3. TMP102 Driver**

Handles reading raw and converted temperature values from the TMP102 sensor.

* `TMP102_ReadRawTemp()` returns raw 12-bit sensor data.
* `TMP102_ReadTempC()` returns temperature in Celsius.
* `TMP102_ReadTempF()` returns temperature in Fahrenheit.

---



## 🔧 Hardware Connections

| TMP102 | STM32F4         |
| ------ | --------------- |
| SDA    | PB11 (I2C2_SDA) |
| SCL    | PB10 (I2C2_SCL) |
| GND    | GND             |
| VCC    | 3.3V            |

*The TMP102 **must** be powered with 3.3V because its I2C lines are not 5V tolerant.*

---

## ▶️ How It Works

1. Initializes HAL, GPIO, I2C2, and UART1.
2. Runs an I2C scan to detect connected devices.
3. Enters infinite loop:

   * Reads temperature in °C and °F from TMP102.
   * Prints result using UART.
   * Delays 500 ms.

---

## 📌 Example UART Output

```
I2C Device found at: 0x48
Temp: 26.75 C, 80.15 F
Temp: 26.81 C, 80.26 F
Temp: 26.88 C, 80.38 F
```

---

## 📦 TMP102 Address

Default I2C address for TMP102:

```
0x48 (7-bit)
Used in STM32 HAL as: 0x48 << 1
```

---

## 🧪 Testing Steps

1. Flash the code to your STM32 board.
2. Open UART serial terminal (115200 Baud).
3. Verify I2C scan output.
4. Observe live temperature readings.

---

## 📝 Notes

* Ensure pull-up resistors on SDA/SCL (most TMP102 modules include them).
* I2C speed recommended: **100 kHz**.
* If reading incorrect data, verify wiring and address.

---
