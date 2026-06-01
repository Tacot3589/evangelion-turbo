---
title: "Evangelion Turbo"
author: "Szymon Filipkowski"
description: "Evangelion Turbo is an SUMO robot of footprint 10x10cm and weighing less than 1kg. It is direct successor to my last robot, Evangelion. Evangelion have 4 distance sensors, 4 line sensors, IMU, oled, UI and maybe even enkoders (idk if i will fit them tho)"
created_at: "2026-03-16"
---


# June 01: Chamfering!

Okay, so today i designed and 3d printer very helpful thing for chamfering (first photo). Beacuse drilling anything by hand is very, very hard thing to do straight.
While it was printing on our schoold mashine i prepared and cleaned all of the fronts and back and the ceil. 
While i was chamfering got to know, that you should chamfer aluminium in veeery high speed! Beacuse it acts like bubble gum to you drill in lower speed, which results in bad and innacurate holes. 
I got like 60 holes to drill, chamfer, clear, chamfer again and then clean in alcohol that i lost my mind lol.

*I chamfer everything, to hide countersunk screw all the weay in - this way i can have more robot in my limited 10x10cm footprint*

I tried polishing to flat 3 of my parts, but beacuse of lack of proper sandpaper it comed out horrible. 
*Polished surfaces may or may not reflect and confuse distance sensors of the opponents*

As for the sensors, drilling mouting holes and cutting orginal mounting *arms* (idk how theye are called lol) was not hard, but a precise job.

Also one more quick tip!
When you drill use drillin oil (or just any oil, even water) - it helps to achieve clean cuts and clear holes!

Heres photos!
![IMG1](journalMedia/06-01_02.jpg)
![IMG2](journalMedia/06-01_03.jpg)
![IMG3](journalMedia/06-01_04.jpg)
![IMG4](journalMedia/06-01_05.jpg)
![IMG5](journalMedia/06-01_06.jpg)
![IMG6](journalMedia/06-01_07.jpg)
![IMG7](journalMedia/06-01_08.jpg)
![IMG8](journalMedia/06-01_09.jpg)


Also i found out that my MCU stm32g431 have been sold everywhere... as well as all of the normal replacement - so i have gone digging.
And to my suprise i have found something! stm32g491 will work lol.
*most important pins for compatibility arent gpio or any other connector but rather Vcc, Vss, clock, BOOT0 and nrst - with them wrongly connecter you will either kill your mcu or it wont work at all!*
![IMG8](journalMedia/06-01_10.jpg)

**Total time spent: 7.2 hours**