# STM32 I2C Scanner (NUCLEO-G071RB)

This project scans all possible I²C addresses (1–126) on the I²C bus using the **NUCLEO-G071RB** board and displays the detected device addresses via **UART**.

---

## 🧰 Hardware Connections

| Signal | Pin on NUCLEO-G071RB | Description                |
| :----- | :------------------- | :------------------------- |
| SDA    | **PA10**             | I²C Data Line              |
| SCL    | **PA9**              | I²C Clock Line             |
| GND    | Common Ground        | Connect to all I²C devices |

---

## ⚙️ Project Overview

The firmware initializes:

* **I²C1** (on PA9/PA10)
* **USART2** (for serial output)
* **GPIO** (for LED)

Then it continuously scans the I²C bus for connected devices and reports their addresses to the UART terminal.

---

## 🧾 Output Example

When a device is connected:

```
Starting I2C Scan...
Scanning I2C bus...
I2C device at address: 0x3C
Scan complete.
```

When no device is found:

```
Starting I2C Scan...
Scanning I2C bus...
No I2C Device is Found ?...
```

---

## 🖥️ UART Configuration

| Parameter | Value      |
| --------- | ---------- |
| Baud Rate | **115200** |
| Data Bits | **8**      |
| Stop Bits | **1**      |
| Parity    | **None**   |
| Mode      | **TX/RX**  |

Open a serial terminal (like PuTTY or TeraTerm) to view the output.

---

## 🔁 Scan Delay

* The scan repeats every **2 seconds** (`HAL_Delay(2000)`).

---