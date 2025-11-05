# 🚀 STM32 HAL Practice Programs

Welcome to my **STM32 HAL Hands-on Practice Repository** 🎉
This repo is a progressive set of exercises designed to take you from **beginner** ➝ **industry-ready embedded engineer** using **STM32 HAL (Hardware Abstraction Layer)**.

---

## 📌 Roadmap

### 🔹 Level 1: Beginner (GPIO + Basics)

* Blink LED with delay (polling)
* Blink LED using `HAL_Delay()` with different speeds
* Push button input → toggle LED
* LED ON when button pressed, OFF when released
* 7-Segment Interfacing with STM32
* Debounce push button using software
* External interrupt (EXTI) → toggle LED

### 🔹 Level 2: Intermediate (Timers + Interrupts)

* LED blink using Timer interrupt (instead of HAL_Delay)
*	Generate PWM signal on GPIO pin
*	Control LED brightness with PWM (dimming)
*	Servo motor control with PWM
*	Use Input Capture to measure external pulse width
*	Create a simple stopwatch using timer interrupt

### 🔹 Level 3: Communication (UART, I2C, SPI)

* Send "Hello STM32" via UART to PC terminal.
*	UART echo program (receiver + send back).
*	Control LED's Using UART Commands.
*	UART with interrrupt (HAL_UART_RxCpltCallback).
*	I2C → Scan for connected devices.
*	I2C → Read data from temperature sensor.
*	I2C → Display text on OLED.
  


---


