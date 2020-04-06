# Wilson
Wilson is a sock puppet chat buddy - a wearable interface which embodies hygge.

Created by Katie Tieu for CPSC 599.88: Physical & Tangible HCI Final Project, April 2020.

# Instructions
To be used in conjunction with P5.js

1. Download this repo and upload code to Arduino

2. Download P5.js GUI from https://github.com/p5-serial/p5.serialcontrol/releases . Extract .zip and open "p5.serialcontrol" executable file

3. In P5.js GUI, connect to Arduino port (COM3 for Uno on Windows)

4. Open https://editor.p5js.org/ktieu/sketches/oLdjZ5iiJ in browser (ensure line 32: serial.open('COM3'); is set to the right port)

5. Run code in P5.js editor and watch output in the preview

# Use

Whether you want to chat, vent to someone, or just hang out, Wilson is here for you!
- Squeeze his right hand for a statement (joke, compliment, fun fact)
- Squeeze his left hand for a reply ("Yes", "No", "Are you sure?")
- Squeeze his left ear to have him play a song based on your heart rate
  - Under 100 bpm (relaxed state): plays a 'chill' song
  - Under 120 bpm (excited state): plays a 'hype' song
  - Over 120 bpm (overexcited/distressed): plays a calming song
