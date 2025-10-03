# Arduino Frequency Generator & STM32 Frequency Measurement

This project demonstrates generating a square wave of a desired frequency using an **Arduino Uno** and measuring it using an **STM32** microcontroller via **input capture**. The measured frequency is then displayed on the **STM32 serial monitor**.

---



## Connections

1. Connect **Arduino OUT_PIN (D6)** to **STM32 input capture pin** (e.g., TIM2_CH1--PA0).  
2. Connect **GND of Arduino** to **GND of STM32**.  

```

Arduino D6  ---->  STM32 TIMx_CHx PA6
Arduino GND ---->  STM32 GND

````

---

## Arduino Uno Code

The Arduino generates a square wave of a specified frequency.

```cpp
#define OUT_PIN 6   // output pin
float frequency = 12.00; // Desired frequency in Hz

void setup() {
  pinMode(OUT_PIN, OUTPUT);
}

void loop() {
  generateSquareWave(OUT_PIN, frequency);
}

// Function to generate square wave on a pin
void generateSquareWave(uint8_t pin, float freq) {
  float period_ms = 1000.0 / freq;   // Total period in milliseconds
  float half_period = period_ms / 2; // HIGH or LOW duration

  digitalWrite(pin, HIGH);
  delay((int)half_period);   
  digitalWrite(pin, LOW);
  delay((int)half_period);
}
````

---

## How It Works

1. **Arduino** generates a square wave at the desired frequency.
2. **STM32** input capture timer measures the time between consecutive rising edges of the waveform.
3. Frequency is calculated as:

```
Frequency (Hz) = Timer Clock / Timer Count
```

4. The measured frequency is printed on the **STM32 serial monitor**.

---
