# UART Communication with STM32

This project demonstrates basic UART (Universal Asynchronous Receiver/Transmitter) communication using an STM32 microcontroller.  
It sends a string message through UART4 and echoes back any received data.

---



## ⚙️ Functionality

1. The STM32 initializes system clock, GPIO, and UART4 peripherals.
2. It transmits a message:  
```

UART Program From STM32....

```
3. It continuously waits for UART data.
4. When data is received, it echoes the same data back to the sender.

---

## 🧩 Main Code Explanation

### `main.c`
- **`MX_UART4_Init()`**  
Configures UART4 with 115200 baud rate, 8 data bits, 1 stop bit, and no parity.

- **`HAL_UART_Transmit()`**  
Sends the startup message over UART.

- **`HAL_UART_Receive()`**  
Waits to receive 4 bytes of data (blocking mode).  

- **Echo Back:**  
When data is received, it transmits the same bytes back to the sender.

---

## 🔌 Connections

| STM32 Pin | UART4 Function | Description      |
|------------|----------------|------------------|
| TX Pin     | UART4_TX       | Data transmit    |
| RX Pin     | UART4_RX       | Data receive     |
| GND        | —              | Common ground    |

> Ensure the TX of STM32 is connected to RX of your USB-to-Serial module and vice versa.

---

## 🖥️ Testing

1. Flash the program to your STM32 board.
2. Open a serial terminal (e.g., PuTTY, Tera Term, or Arduino Serial Monitor).
3. Set the baud rate to **115200**.
4. Observe:
- On reset, the message `UART Program From STM32....` is displayed.
- Any data you type will be echoed back.

---



