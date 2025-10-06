# STM32 UART Hello Project

This project demonstrates **UART communication using STM32** with a **USB-to-TTL adapter**. The STM32 sends the message `"Hello From STM32"` to a PC terminal continuously while toggling an LED.

---

## 📌 Project Name
**STM32_UART_Hello**

---

## ⚙️ Hardware Requirements

- STM32 microcontroller board (e.g., STM32F103C8T6 / Blue Pill)
- USB-to-TTL adapter
- Jumper wires
- PC with serial terminal software (Tera Term, PuTTY, RealTerm, etc.)

---

## 🔌 Connections (STM32 → USB-TTL)

| STM32 Pin | Function | USB-TTL Pin |
|-----------|----------|-------------|
| PA0 (or chosen TX) | UART TX | RX |
| PA1 (or chosen RX) | UART RX | TX |
| GND | Ground | GND |
| PA6 | LED | - (optional, on-board LED) |

> **Note:** TX on STM32 connects to RX on USB-TTL, and RX on STM32 connects to TX on USB-TTL.

---

## 📝 Software Configuration

- **UART Peripheral:** UART4
- **Baud Rate:** 115200
- **Data Bits:** 8
- **Stop Bits:** 1
- **Parity:** None
- **Flow Control:** None
- **Mode:** TX/RX

---

## 💻 Usage

1. Connect STM32 board to USB-to-TTL adapter and then to PC.
2. Open a serial terminal (Tera Term / PuTTY / RealTerm).
3. Set serial parameters: **115200 8N1 No Flow Control**.
4. Power up the STM32 board.
5. You should see the following repeated message in the terminal:
```

Hello From STM32
Hello From STM32

```
6. The on-board LED on **PA6** will toggle every 1 second.

---

## 🛠️ Code Overview

- `HAL_UART_Transmit()` is used to send data from STM32 to PC.
- `HAL_GPIO_TogglePin()` toggles the LED to indicate program running.
- A delay of 1000 ms is added between transmissions to avoid flooding the terminal.



