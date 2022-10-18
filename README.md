# On-demand-traffic-light-control-system
Introduction

Traffic lights are signaling devices positioned at road intersections, pedestrian crossings, and other locations to control the flow of traffic.
Traffic lights normally consist of three signals, transmitting meaning to drivers and riders through colors and symbols including arrows and bicycles.
The regular traffic light colors are red, yellow, and green arranged vertically or horizontally in that order.
Although this is internationally standardized, variations exist on national and local scales as to traffic light sequences and laws.

System Description

On-demand traffic light control system contains and on-demand cross walk button let the signal operations know that someone is planning to cross the street, so the light adjusts, giving the pedestrian enough time to get across.
Full system consists of the following...
1- Three leds for car signals (Green, Yellow, Red)
2- Three leds for Pedestrian signals (Green, Yellow, Red)
3- On-demand cross walk button
On-demand traffic light control system has two modes of operation they are normal mode and pedestrian mode, lets discuss them in the following lines…
First normal mode, in this mode car leds changed each five seconds as following order…
1- Green led will be on for five seconds mean car can cross the road
2- Yellow led will start blinking for five seconds
3- Red led will turn on for five seconds
4- Yellow led will start blinking for five second again
5- repeat the above four steps
second is pedestrian mode, switch to this mode when the pedestrian button is pressed, in this mode we have 2 state of operations depends on when the pedestrian pressed the on-demand cross walk button.
1- If the pedestrian pressed the button when the car red led is on
a. The pedestrian green led and car red led will be on for five seconds
b. The pedestrian yellow led and car yellow led will start blinking for five seconds while the pedestrian green led still on and car red led turned off
c. After five second blinking the pedestrian yellow and green led and car yellow led will turned off and the pedestrian red led and car green led will be turned on and back to normal mode operation
If the pedestrian pressed the button while the car green led is on or yellow led is blinking
a. Pedestrian red led will be on and pedestrian yellow led and car yellow led will start blinking for five seconds
b. Then the pedestrian green led and car red led will be on for five seconds
c. After that pedestrian yellow led and car yellow led will start blinking for five seconds while pedestrian green led still on
d. Finally pedestrian red led and car green led will be on and system back to normal mode
The above is a brief description about how on-demand traffic light control system works which each mode and state explained.

Hardware requirements:

ATmega32 microcontroller
One push button connected to INT0 pin for pedestrian
Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
