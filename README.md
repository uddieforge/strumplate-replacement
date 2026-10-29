# strumplate-replacement
Omnichord Replacement

Hi!

If you've ended up here, it's probably because you're having trouble with the strumplate on your Omnichord.

I had to repair an OM-300 whose strumplate was damaged.

Here's the approach I took.

**How the original strumplate works**

The original strumplate relies on a system of layered electrical contacts. One layer features conductive carbon tracks, while a second conductive layer brings them into contact when pressure is applied with a finger. The component acts as a membrane switch.

The layer containing the conductive tracks includes both individual tracks for each playable note on the strumplate and ground-connected tracks. When a "note track" is connected to ground, it triggers a note on the Omnichord.

My replacement solution

Reproducing an identical strumplate from scratch was practically impossible. I therefore decided to find a way to recreate an experience similar to that of the original strumplate, without attempting to reproduce the original component itself.

**Here's the solution I came up with.**

I had a PCB manufactured to match the shape of the original strumplate. This PCB features 12 conductive pads.

Each pad is connected to an HW-017 module for Arduino, a capacitive touch-sensing module (often based on the MPR121 chip).

The module is itself connected to an Arduino Nano.

The Arduino Nano's digital outputs then drive the gates of 12 MOSFETs. The source of each MOSFET is connected to ground, and each drain is connected to one of the original strumplate's tracks. When the Arduino triggers a MOSFET's gate, the corresponding original strumplate track is connected to ground, producing a sound.

**To summarize the connections:**

Strumplate PCB → HW-017 module → Arduino Nano → MOSFETs → Original strumplate connectors

To power the Arduino, you can connect it directly to the Omnichord's 12 V power supply rail.

**Project limitations**

There are a few limitations to this approach.

First, the original strumplate actually has 13 note-triggering tracks, rather than 12. Given the limited number of inputs available on both the Arduino and the capacitive sensing module, incorporating a thirteenth track would have been difficult. I therefore had to sacrifice one of the notes at the end of the strumplate's range.

Another limitation is that I'm not a professional PCB designer. I did my best to reproduce the shape of the original strumplate, but I had to make some minor adjustments with a file to get the PCB to fit perfectly inside the Omnichord.

I'm not a C++ developer, so I wrote the code using AI-assisted coding (vibe coding) with Claude. The code probably isn't very well written, but it works and gets the Omnichord up and running.

If you'd like to contribute alternative, better-written versions of the code, I'd be happy to see them!
