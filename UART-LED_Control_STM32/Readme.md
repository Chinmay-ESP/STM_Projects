# STM32 UART LED Control

Control three LEDs on an STM32 board using UART commands from a PC.

---

**LED Connections:**

| LED  | Pin        |
|------|-----------|
| LED1 | `LED1_Pin` |
| LED2 | `LED2_Pin` |
| LED3 | `LED3_Pin` |

---


## Setup & Usage

1. Flash the code to your STM32 board.
2. Connect UART4 to your PC via USB-to-Serial.
3. Open the terminal with settings:  
   **Baud rate:** 115200, **Data bits:** 8, **Parity:** None, **Stop bits:** 1
4. You will see the menu:

```

Enter Your Options to Control LED's -
->LED1
->LED2
->LED3

```

5. Type a command (e.g., `LED1`) and press Enter.
6. The corresponding LED will turn on, others will turn off.
7. Invalid commands will turn off all LEDs.

---

## How it Works

- The MCU receives UART characters one by one and stores them in a buffer.
- When Enter is pressed, the input is compared with `"LED1"`, `"LED2"`, or `"LED3"`.
- The corresponding LED pin is set high, and others are set low.
- A message is sent back to the terminal confirming the action.

---

## Example

**Input:** `LED2`  
**Output in Terminal:** `LED2 is ON`  
**LED State:** LED2 ON, LED1 and LED3 OFF
```
