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


# June 02: Im cooked lol

Today i cut banana plugs to exact dimensions (always wear protective gear guys!) and broke my PCBs.

Uhm... I ordered only 5 of them from JLC...

I wanted to heat them to 230 degress, solder plugs and a *a lot* of capacitor, wait a while and be happy. Something broke and now i have shortcircuit on battery lol.
![IMG1](journalMedia/06-02_01.jpg)
![IMG2](journalMedia/06-02_02.jpg)
![IMG3](journalMedia/06-02_03.jpg)

Also i forgor, but i made some research on the way to school, (about 1hr in the bus lol) about IR filters.
Halogen lamps may disturb work of IR TOF sensors, so i thought about adding them.
From my research i concluded, that i want narrowband filters at 850NM, which will cut every other spectrum of the light that i dont need - my lidars work with 850NM, and narrowband filter will cut everything below 850-30NM, and everyhing above 850+30NM.
Theye are not cheap but i think i will give them a try.

Lapse:
https://lapse.hackclub.com/timelapse/hRIpPztWr8to

**Total time spent: 2.5 hours**


# June 03: Solderingggg

Im coking with soldering main controller PCB.
I got scared of destroying motor drivers so im focusing on controller for now.

Tip for today: use flux for soldering, dont depend only on tip (soldering iron? soldering thing? idk how to call thing you solder with, im not talking about the tool, im talking about this usable thing on spools lol) - it makes life easier and soldering a looooot quicker and more precise. 
Also it gives nice look.

Unfortunetaly i have bought some wrong components which i have to buy...
Some zener diodes in wrong casing, some resistors which i forgor.

![front](journalMedia/06-03_01.jpg)
![back](journalMedia/06-03_02.jpg)

Lapse link:
https://lapse.hackclub.com/timelapse/dXYIZFRqisLL

Actually i soldered MCU (i started doing it at 22.00 o clock), beacuse i wanted to check if everyting was okay. It was not. I didnt start lapse bcoz i though it was quick 20min job lol.
So i have shortcircuit on my mainboard, so i took another one and solderem LDO and MCU into this...
I have 1v instead of 1.8v on Vcap and core. I will try to fix it next day.
At 01:00 AM i got finnaly to sleep with more issues than before lol.
**Total time spent: 7.5 hours**


# June 03: I should have bought PCBA lol

*Yea... I got camera working for lapse!*

After 4hrs of debuging i managed to connect to stm32cubeprog withg diffrent computer.
It comes out that i had too log USB cables and it didnt work lol.

IT FREAKIN CONNECTED HELLYE!
*Beacuze of all the mess i dont have any way to connect my camera lol, maybe i will find to change it into internet one, it is some xiao esp sense c3 that i won at some competition*


BRUUUUH...
my controller, which is based around stm32h5 works while beeing connected with like 3cm cables to voltage maker, but using proper cables with Crocodile connectors not works.

So today i managed to connect to the mcu. But nothing else lol.. *Kill me plyz stm32h is so complicateddd*
![cam](journalMedia/06-04_01.jpg)
![pcb](journalMedia/06-04_02.jpg)

Lapse link:
https://lapse.hackclub.com/timelapse/elWAS2NwqL74


We got another late nite session lol.
I managed to connect to PC propelly. It comed out that i had micro-short-circuit between 3.3 and boot0, which caused MCU to stuck on bootloader and never boot to programm...
It was hard to find out, beacuse this shortcircuit wasnt really short circuit, it had about 5kOhm resistance! Combined with 10K pulldon, there was about 2.2-2.6v on BOOT0, which is high state lol. 
**Total time spent: 11 hours**


# June 06: Evangelion Turbo edit incoming?

@Leo dmed me on slack, asking if he could use my proj for his edit... Im kinda curious what he will cook.
I added some filets, deleted few thing, made a few things more pretty and sent him step file of the project!

*Im looking forward for you edit leooo!!!*
![conv](journalMedia/06-06_01.jpg)
![step](journalMedia/06-06_02.jpg). 
**Total time spent: 0.5 hours**


# June 12: Comeback after short beake!

Parts from JLC finally arrived!
I opened box and carefully inspected for anything which may be wrong (this costed shitload of money)

Also i weighted everything for future use and writed it down into excel!
Disasembly of current prototype was also a thing, i weighted, like everyhing lol.

Why? Beacuse i want to be exacytly 990g - 990g in 1% accuracy weigh is exactly 1kg, which is maximum i wanted.

*My calculations from excel says that this robot will weight 890g for now, that is okay, thus not what i really wanted*

Imagesss!
![img1](journalMedia/06-12_01.jpg)
![img2](journalMedia/06-12_02.jpg)
![img3](journalMedia/06-12_03.jpg)
![img4](journalMedia/06-12_04.jpg)
**Total time spent: 2 hours**