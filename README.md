# CTAG Signature Guitar Amp

![ArduinoGuitarAmp (7)](https://user-images.githubusercontent.com/64489709/82821872-25408800-9ea5-11ea-9ca0-7bfcabd32c90.jpeg)


## Introduction
This is a small all in one digial amp projekt. This base is an Arduino Uno. The amp is programmeble and you are able to design a hole variety of effects. The hole system can run on batteries and can be includet in nearly every speaker. In my case I addet the amp into an old broken guitar amp but I also tested it with an hifi speaker. The amp features a lcd display and different buttons to choose the effects. The project was inspired by the guitar pedal from Electrosmash https://www.electrosmash.com/pedalshield-uno.

## Examples
Here are two example videos of the amp. The video shows the sound and basic effects of the amp.
* https://www.youtube.com/watch?v=WST0WDY9Kv4
* 

## Effects
* Volume
* Boost
* Overdrive
    * Hard clipping
    * Positive hard clipping
    * Positive soft clipping
    * Bias level soft clipping
    * Bias level hard clipping
    * Bias positive hard clipping
* Distorsion
    * Soft distorsion
    * Hard Distorsion
* Reverb
* Crazy sounds
* Waveform generator
   * Sine wave
   * Triangle wave
* Tremolo
   * Sine wave tremolo
   * triangle wave tremolo
   
## Circuit
![WhatsApp Image 2020-05-17 at 19 35 28 (1)](https://user-images.githubusercontent.com/64489709/82157798-e9de0200-9883-11ea-8f1e-8e1a597a70e9.jpeg)

This is the final circuit that I have used in the amp. The circuit has eight main components but you do not need all of them.
* Arduino Uno (needed)
* Power supply (needed)
* Input stage (needed)
* Output stage (needed)
* Class D amplifier (needed)
* Display (not needed)
* Buttons (not needed)
* Speaker (needed)


## Parts
![Verstaerker5](https://user-images.githubusercontent.com/64489709/80517029-b3981b80-8984-11ea-92c2-e7423980c42a.PNG)

* C1, C4, C8 = 100nf
* C2, C6, C5, C7 = 6.8nF
* C3 = 270pF
* C9, C10 = 4.7uF electrolytic capacitor
* R1, R4, R11 = 1MOhm
* R2, R3 = 4.5kOhm
* R5, R8, R7, R10, R12 = 4.7kOhm
* R6 = 100kOhm
* R9 = 220kOhm
* P1 = 500k Trimmer
* K1 = screw terminal block
* Arduino Prototype Shield
* Arduino Uno
* I'm using a adapter power supply. But you can use every 5v power supply with enough power.
* Class d amp for example XH-M177 PAM8403
* MCP6002

![WhatsApp Image 2020-05-11 at 16 51 32](https://user-images.githubusercontent.com/64489709/82157760-b0a59200-9883-11ea-808b-009db763e531.jpeg)

* R13, R14, R15, R16 = 10kOhm
* R17, R18, R19, R20 = 200Ohm
* R20 = 100Ohm
* R21 = 120Ohm
* P2 = 10k Trimmer

* red: Arduino power supply
* yellow: Class D Amp power supply
* green: Button 1-4
* lightBlue: Led 1-4 supply

## Used programs

* Arduino IDE
* Code Blocks
* Dia
* Igor Pro
* Physics Toolbox
* Overleaf
* fritzing
* Lochmaster
* Reaper
* VSDC Video Editor








