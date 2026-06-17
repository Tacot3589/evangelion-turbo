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

I also made little 3d printed thing for chamfering, beacuse last one didnt work well lol

Imagesss!
![img1](journalMedia/06-12_01.jpg)
![img2](journalMedia/06-12_02.jpg)
![img3](journalMedia/06-12_03.jpg)
![img4](journalMedia/06-12_04.jpg)
![img5](journalMedia/06-12_05.jpg)
**Total time spent: 2.5 hours**


# June 13: lock the heck in

Okay so today i locked in onto making metal parts usable and accurate, beacuse dimensional accuracy in SLM parts is pretty poor!
I sanded everything that i didnt want by hand (photos before and after), chamfered according to proj.
Also i rechamfered my front and back plates, beacuse theye were not straight lol.

My front plow is made from #45 steel CNCed which is pretty hard! *Guess, who said "yeee, its only half of the milimiter, i will sand it by hand, no problem" and cant sand it now, even with sanding mashine...*

I wanted to tap everyhing but i broke like 4 taps... *I had hard, very hard, time removing broken bits from holes*
Thankfully i managed to tap all plastic parts before!

*Quick tip for today!
Tapping, sanding, drilling, always use oil! It sound weird to use something slicky, but trust me it works lol. It helps to keep your tools be cool and live longer and it is a loot easier to drill!*

Imagesss!
![img1](journalMedia/06-13_01.jpg)
![img2](journalMedia/06-13_02.jpg)
![img3](journalMedia/06-13_03.jpg)
![img4](journalMedia/06-13_04.jpg)
![img5](journalMedia/06-13_05.jpg)
![img6](journalMedia/06-13_06.jpg)
![img7](journalMedia/06-13_07.jpg)
![img8](journalMedia/06-13_08.jpg)
![img9](journalMedia/06-13_09.jpg)
**Total time spent: 9.8 hours**

# June 14: W grandpa

He found M3 tap for me! *I broke it like 40min salet :sob-emoji:*
Also my brother found M2 tap for me! *Yup, also broke it, 10min later :skull-emoji:*

I tapped all M2.5 on all metal parts, and all M3 on front mount... Then i felt that this is easy and i understand it now LOL

Additionally i broke like 4 drills on these 1mm holessss... Using new HSS drill bit was the key. *One bit stuck inside, and i had bad time taking it out xD*

So the key for doing geat taps and dont braking them inside your part, is actually PID tuning. You have to tune yourself to be gentle and dont feel to good.
Go little, like quater of a turn, then go back same quater turn... Go and back... Stop and go. You will learn this someday!
*AND OFCOURSE A LOT OF LUBRICATION OR OLI!*

Imagesss!
![img1](journalMedia/06-14_01.jpg)
![img2](journalMedia/06-14_02.jpg)
![img3](journalMedia/06-14_03.jpg)
![img4](journalMedia/06-14_04.jpg)
![img5](journalMedia/06-14_05.jpg)
![img6](journalMedia/06-14_06.jpg)
![img7](journalMedia/06-14_07.jpg)
**Total time spent: 5.7 hours**


# June 15: Again in school robotics club!

Hellyeeee! In the morning i bought M3 taps kit, with 3 stages. First stage was easy, i could do it even with hard dril... I broke all of the 3 of them.
Fourtunetaly i managed do tap all of the m3 holes in hearboxes befora that lol. I also borrowed (i knowrrr, agaainnn) M3 tap from frien... WHICH I ALSO BROKE LOL

I should be laughing but... These shish material is so freakin harddd.

Also i tried sanding front wedges on the mashine, which shjould be easy. Guys it is only .5mm... right?
Is is not "only" .5mm. It is .5mm of frakin hard steel! I burned my fingers like three times.

After all of this i tried to get tap out from hole, from the other side with screw.. You wont believe it. i broke it also LOL

Imagesss!
![img1](journalMedia/06-15_01.jpg)
![img2](journalMedia/06-15_02.jpg)
![img3](journalMedia/06-15_03.jpg)
![img4](journalMedia/06-15_04.jpg)
![img5](journalMedia/06-15_05.jpg)
![img6](journalMedia/06-15_06.jpg)
**Total time spent: 5.2 hours**

# June 16: Parts!

Second batch, last one, of electronics parts finally came!
It was MCUs, drivers, mosfets and other similiar parts, so this was more expensive one...

Alsoo i just wanted to share how comediacilly smally are these connector lol
I ordered 30 of them (i need about 17 for one robot, but yk, i can broke while soldering, theye are small and hard to solder), so i ordered 30.
Chinesee guy only sent me 10... Hope they will arrive until competition, or im cooked.

Imagesss!
*.6mm jst connector next to m4 screw*
![img1](journalMedia/06-16_01.jpg)
![img2](journalMedia/06-16_02.jpg)
**Total time spent: 0.2 hours**

# June 17: Lock in again day.

It was funny and a lot of work today.

In the morning i cleared silicone form (in our robotics club), made silicone and poured it into. I wanted to go for nice purple color, by mixing pink with black, but they came up grayish...
Later i started working on assembly but... It wasnt quite rigt. My screw i got were .1mm to large (i used longer ones from diffrent batch, with right tolerances), bearing were broken (i had to hammer them out, and hammer good ones in).
A few days ago i broke screw inside, so i tryed cut it in half to get it out with "-" screwdriwer... I countld so i just sanded it flat. I also had to sand my SUPERHARD CNC MILLED FRONT WEDGE WHICH WAS SUPER HARD AND TEDIOUS BEACUSE IT IS FREAKIN SUPER HARD... *thankfully it fit*
And ye, i nearly broken my electric screwdriver, which i got fo christmasss...

After all of this, finnaly gearboxes were done. One was spiinning okayich but other one was not. Thats bad, it is only 7.5:1 so it should spin like butter. I think it if bearings fault, but i had to go home so i could fix it then.
Also pretty suprising, but tolerances on SLM on right gearbox and left one are pretty driffrent. Like left one is loose and right one - i had to drill a lot of holes beacuse it didnt fit.

*Now as i got home and ate dinner i can go back to soldering!*


When i was trying to force gearboxes to run normally, it started to smoke from somewhere... I think i have burned out motors :skulk:

Imagesss!
![img1](journalMedia/06-17_01.jpg)
![img2](journalMedia/06-17_02.jpg)
![img3](journalMedia/06-17_03.jpg)
![img4](journalMedia/06-17_04.jpg)
![img5](journalMedia/06-17_05.jpg)
![img6](journalMedia/06-17_06.jpg)
![img7](journalMedia/06-17_07.jpg)
![img8](journalMedia/06-17_08.jpg)
![img9](journalMedia/06-17_09.jpg)
**Total time spent: 6.2 hours**