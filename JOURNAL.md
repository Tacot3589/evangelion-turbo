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

When i was trying to force gearboxes to run normally, it started to smoke from somewhere... I think i have burned out motors :skulk:

*Additionally i emailed some local filament resselers to see if they would sent me some free samples. Aaand cutified readme :)*


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
**Total time spent: 7.3 hours**


# June 18: I just want it to work already >.<

I started day with getting wheels out of the forms (wait, actually i checked, theye are called mold in english lol, sorry). It was messy, but after clearing, they comed out nicely.

I soldered everythin what was left (ye, small .6mm raster connectors too) to the maincontroll. Eveything worked... To the point. After soldering eeevyrhing but bullet plugs... It just borked itself. I got 0.23ohms of resistance beetween 3.3v and GND.
FREAKING AGAIN! I didnt do much. It was only soldering bullet plugsss. When i apply current it heats up under MCU, but it i think is okay... This shish hars is.

I got one board left, idk what to do to be honest. I can solder it but i dont have these small connectors on hand, beacuse chinese guy sent only 10pcs, not orginal quantity. And i need about 17teen for this board lol. Not funny, nevermind. Cryout.
I didnt even ate dinner beacuse of that.

Wait i got one idea while returning by bus home. I can use some smaller connector and one electrolyte cappacitor, insteal of two chunky bullets plugs (may this be the problem in destroying eveyrhing inside pcb, we well see).

So yea. I actually started lapse in the morning, about 8AM, but it got totally borked while i made 1hr break for my sanity and qucik ice cream (GOD I FREAKIN LOVE ICE CREAM). ye, it sucks.


Imagesss!
![img1](journalMedia/06-18_01.jpg)
![img2](journalMedia/06-18_02.jpg)
![img3](journalMedia/06-18_03.jpg)
![img4](journalMedia/06-18_04.jpg)
![img5](journalMedia/06-18_05.jpg)
![img6](journalMedia/06-18_06.jpg)
![img7](journalMedia/06-18_07.jpg)
![img8](journalMedia/06-18_08.jpg)
![img9](journalMedia/06-18_09.jpg)
**Total time spent: 8.4 hours**


# June 19: Physicz in like magic

I asked for help my robotics coach, Patryk, via messenger. Next day (which is today) he took his warm-camera (idk how to call it lol).
I soldered directly into 3.3v line, beacuse short cicruit was on this like (about 0.22Ohm from 3.3 to GND, about 20K 5v to GND, about 100K VCC to GND -> shortcircuit somewhere on 3.3v line).
Current limiter on bench power supply to 2 Amp and here we go. After some searching one line lit up clearly. In altium i search and it was 3.3v line, so there was something bad happening *at the end* of this trace.
After mooore searching and *crying* we found a little too much of solder under my 'lil connector.
AND THAT WAS IT! IT WORKED AFTER I REMOVED CONNECTOR AND THE PROBLEM! SCIENCE IS OUR MAGIC GUYS!


Also i emailed PCBWay if they could machine front wedge for me, beacouse one i got from JLC is far from perfect...


*Im spending my time, workign at our robotics club at school, and i have my camera set up at home, so no lapse :sob:*

Imagesss!
![img1](journalMedia/06-19_01.jpg)
**Total time spent: 1 hours**



# June 22: Work work work work work

PCBWay said that they will partially fund me my front wedge! Succes!

Today i soldered more components, and checked again for any FREAKIN SHORT CIRCUIT. There were none, so it is okay :)
It work like a bliss. AND IT LOOKS SO FREAKIN COOL BABBYYYYYYYYYY!!!
*Soldering these small zener diodes beetween MOSFETS was so freaking hard lol.*

After cooking with main controller (it looks so freakin cool!) i started working on one motor driver.
Why only one? Beacuse im worried about breaking it or cooking it on solded plate. So ye, cookin cookin cookin!
I have done most of A side, tommorrow next side and shitty connectors which i hate <3

Imagesss!
![img1](journalMedia/06-22_01.jpg)
![img2](journalMedia/06-22_02.jpg)
![img3](journalMedia/06-22_03.jpg)
![img4](journalMedia/06-22_04.jpg)
**Total time spent: 7.6 hours**


# June 23: 10.00 to 19.00 with two half hour breakes. Nice. One hour spend on troubleshooting my younger robotics collegue robot lol.

Today i fully soldered one motor driver! It was tedious but here we are! I had some problems with random shortcircuit, but i hotaired a few things, desoldered mosfets and DRV motor driver, soldered new ones and now it is all okay!
I didnt have time to connect it to PC and test it, but all of the status leds are on so i praise to be okay and workin.

Next i soldered silicone wires to motors (silicone is better at disspating heat and more heat resistant than PVC or other wires. Also It is easier to manage and SO SATYSFYING TO TOUCH. And easier to solder).
And sanded by hand motor mounts, beacuse cad i okay, irl is sanding :)

For tommorof i plan mostly assembly, silicon insulating eveyrhing around motors and soldering two more motors drivers.


*these small connecotr are PAIN IN THE FREAKING ASS to solder*

Imagesss!
![img1](journalMedia/06-23_01.jpg)
![img2](journalMedia/06-23_02.jpg)
![img3](journalMedia/06-23_03.jpg)
![img4](journalMedia/06-23_04.jpg)
![img5](journalMedia/06-23_05.jpg)
![img6](journalMedia/06-23_06.jpg)
![img7](journalMedia/06-23_07.jpg)
**Total time spent: 7.0 hours**


# June 24: Batch work(out)!

As of yesterdas "one motor driver is working", today i have done two more motor drivers, but i didnt test them(yet)!

Most chellenging thing was little connectors and diodes.

After soldering i tried assembling robot a bit and it looks so freakin cooooool!

Imagesss!
![img1](journalMedia/06-24_01.jpg)
![img2](journalMedia/06-24_02.jpg)
![img3](journalMedia/06-24_03.jpg)
![img4](journalMedia/06-24_04.jpg)
![img5](journalMedia/06-24_05.jpg)
![img6](journalMedia/06-24_06.jpg)
**Total time spent: 6.1 hours**


# June 25: I start to burnoout

So ye... One motor driver is working! While other one not. I resoldered mosfets and mcu, drv driver and CAN, nothing worked, i soldered new mosfets and new mcu, new drv and new can - still no good. So i just ditched it into "i will take a look later box".

AND FINNALY I ASSEMBLED WHOLE ROBOT FOR THE FIRST TIME! It looks SOO FREAKIKNG COOL!
Also our robotics coach told me it loock good :D

After going back home from long work i got aliexpress package with taps! I started tapping my M2 holes for distance sensors, but like 3 of them broke ;-;
A lof of cutting, sanding, cutting, getting burned i recovered one broken tap tip, and other one i just sanded dlat and a lil bit more. I want to put some PETG here and melt heat-set insert into this.
We well see about that.

Also i feel very burned out today...

Imagesss!
![img1](journalMedia/06-25_01.jpg)
![img2](journalMedia/06-25_02.jpg)
![img3](journalMedia/06-25_03.jpg)
![img4](journalMedia/06-25_04.jpg)
![img5](journalMedia/06-25_05.jpg)
**Total time spent: 8.9hours**


# June 26: Helpdesk

Today i spent most of our robotics club day at helping other with their robots and eating pizza! Thats why this is such low timestamp here.

I assembled whole thing again and soldered tiny tiny cables into all of the front sensors. I added some hot glue to act as a strain reliefe, so i would snap pads or cables by mistake! Additonally hot glue is somewhat good insulator,
so i wont short anything on metal parts. After that i started programming and checking configuration (.ioc) file, but i could get anything to work!

*shortie shorie, not so long, we had end-of-year ceremony today. We celebrated with big pizzas!*

*Tommorow im going to lake nearby, to help rescuers as a volunter (no money for me unfortunetaly :( ), but im going to chill out there a looooot!*

Imagesss!
![img1](journalMedia/06-26_01.jpg)
![img2](journalMedia/06-26_02.jpg)
**Total time spent: 2.7 hours**


# June 27: Quick!

I wanted to get more wheels, so i had to 3d print rims! Model i designed before was perfect for SLS, but terrible for FDM so i changed it a bit.
I deleted all of bumbs and other thing that would cause problems for my brothers ender 3.

If you are casting you wheels by yourself (like you got your silicone part A, silicone part B, mold, mix them, wait, etc), then you have to have one thing in mind:
 - Silicone dont stick to any glue well, so you have to add bumb/hold yo your rims. Anything will help. On smooth surface silicone will just spinn. Most of the time it is grippier than rubber.
 - Rubber stick to glue well! You can skip anything uneccesaryy here! You can print flat/smooth rim and glue it later! It is easer to pour and grippier in *some* scenarios than silicone.

Imagesss!
![img1](journalMedia/06-27_01.jpg)
![img2](journalMedia/06-27_02.jpg)
**Total time spent: 0.5 hours**


# July 04: Comeback!

Comeback in breaking taps! I broke 4 today. This metal SLM from jlc is pretty hard lol. Beacuse of that i designen plastic bracked to hold back distance sensors.
Ah yeas, i would forgot, my connector arrived, i soldered them, and started assembly, as well as lubricated gearboxes :)

More assembly, soldering, wire cutting and soldering. Im cooked with wires, they dont fully fit :skulker:

*I was tapping in my grapnda workshop, so no lapse for that*

Lapse: 
https://lapse.hackclub.com/timelapse/Wfvlu2ybgLXT

Imagesss!
![img1](journalMedia/07-04_01.jpg)
![img2](journalMedia/07-04_02.jpg)
![img3](journalMedia/07-04_03.jpg)
![img4](journalMedia/07-04_04.jpg)
![img5](journalMedia/07-04_05.jpg)
![img6](journalMedia/07-04_06.jpg)
![img7](journalMedia/07-04_07.jpg)
![img8](journalMedia/07-04_08.jpg)
**Total time spent: 9.5 hours**


# July 05: 3dp!

I designed and 3d printed hold for drivers, beacuse i coudnt fit wires yesterday!

Imagesss!
![img1](journalMedia/07-05_01.jpg)
![img2](journalMedia/07-05_02.jpg)
**Total time spent: 0.9 hours**


# July 06: Works!?!?

Today i rewired everething that would eat more than some power (battery, motors) with smaller AWG cables, beacuse i could fit orginal ones lol

Later i actually started it! And nothing broke! Controller and one motor driver connected to stm32cubeprog like a charm, but one looks like to be dead...

After trying to code something, while nothing worked, i found out that i have some problem with external crystal... I just bypassed it and decided to use high speed internal one. For now nofith more broke!

Lapse: 
https://lapse.hackclub.com/timelapse/XehMPpMb8ODr

Imagesss!
![img1](journalMedia/07-06_01.jpg)
![img2](journalMedia/07-06_02.jpg)
![img3](journalMedia/07-06_03.jpg)
![img4](journalMedia/07-06_04.jpg)
**Total time spent: 4 hours**


# July 07: Programming

Helloooo

Today i started seriously programming. I could resolve problem with clock but idk why i have 3.3 on 5v line lol, still, i did normally connect to MCUs. Weirdo.
My oled dont work, beacuse i messsed up the footprint... I added one random pad inside. Fuck...
Not good Not good. I tried forcefully soldering it while skipping one pad... but it work out horribly lol.

Ah yeas, and i have written most of the code for motor driver.

Also i cleared out and fixed few minor things in schematics of pcbs.

Lapse: 
https://lapse.hackclub.com/timelapse/ypU_1K0k5lqW

Imagesss!
![img1](journalMedia/07-07_01.jpg)
![img2](journalMedia/07-07_02.jpg)
![img3](journalMedia/07-07_03.jpg)
![img4](journalMedia/07-07_04.jpg)
![img5](journalMedia/07-07_05.jpg)
![img6](journalMedia/07-07_06.jpg)
**Total time spent: 7 hours**


# July 08: Go go go go power-rangers

Helloooo

Today dones from todo:
 - Get buzzer to working
 - Program distance sensors (get them to work faster, 250Hz instead of default 100Hz) (made some shieninigans, and now i have one big function to which i gave RX table, TX table, UART handle and it works like a charm (i could do this in before robots lol))
 - Literally it was so much work, but i made them work!
 - Good filtration for all data from distance sensors (their temp, distance, strenthg of reflected laser, moving average filtration for all of this)
 - Got all of the ADC to work fully autonomusly, with battery voltage readout too!
 - Made full initial routine for robot

 Also i got hold up on new rulebook for upcoming competition!

*Also later i searched up for some smaller alternative motor driver and MCU, for v2 version! I think i would like to fit one big motor driver into one small PCB, we well se 'bout that. I have found upcoming stm32c532 FREAKIN small mcu. It got CAN, 144HZ and poretty powerfull cortex core, and DRV8701 in same package. It would be so freaking small, BUT! But.. but... butt :3... but the MCU ist out yet lol.*

*Ah yeas! i would forgor! I got shortcircuit on TX line on uart! I fixed in quickly and it works like a charm now*

EDIT: AND I HAVE WRITTEN QUICK SCRIPT IN PYTHON TO CONVERT DEC TO HEX, BEACUSE WHO ON THE EARTH WOULD USE DECIMAL IN UART COMMUNICATION

Lapse: 
https://lapse.hackclub.com/timelapse/t728XH_6cTbH

Imagesss!
![img1](journalMedia/07-08_01.jpg)
![img2](journalMedia/07-08_02.jpg)
![img3](journalMedia/07-08_03.jpg)
![img4](journalMedia/07-08_04.jpg)
**Total time spent: 4.5 hours**


# July 09: Holy **not** 67

Helloooo

FUCK. I bought 3.3v buck conv instead of 5v one. Thankfully it arrived today :D 6767676
I soldered it into all of the PCBs. got few shortcircuits in a process, but i got them out.
Later i tried to start CANning (yk, i CAN, beacuse it it spelled CAN, not CANNOT!) and i got huge problem. Some weirdo put NC on my schematics, where it should be Vdd for logic level :skulker:
So... ye... i got fucked up. Thankfully i have like .2mm wire in insulation and microscope lol. Here we go guys! Lets wire this thing up. 
ANOTHER FUCK TODAY! WHYYYYYYYYYYYYYYYYYYYY. I got shortcirtuic on 3.3 and gnd. WHY TODAY GUYZ; after desoldering components from PCB... it come up... IT WAS FUCKIN MCU. Blyat... 

OH YES. I forgot, but i have crosser CANH and CANL lines on motor drivers xD
I think i will order V2 version of PCBs in the future!
But ye, resoldering these tiny cables was paaaaaaaaaaaaaaaaaaaain in theeeeeeee assssssssssssssss.

Lapse: 
No lapse, i forgor :(

Imagesss!
![img1](journalMedia/07-09_01.jpg)
![img2](journalMedia/07-09_02.jpg)
![img3](journalMedia/07-09_03.jpg)
![img4](journalMedia/07-09_04.jpg)
![img5](journalMedia/07-09_05.jpg)
![img6](journalMedia/07-09_06.jpg)
![img7](journalMedia/07-09_07.jpg)
![img8](journalMedia/07-09_08.jpg)
**Total time spent: 5.3 hours**


# July 10: WHOA

Yeeee!
Today i desoldered mcu, sodlered mcu, desoldered mcu, had crashout, soldered it again lol.
A lot of work done today. I understanded CAN, got it to working, failed it, got it to work again....
Im crooked rn, letme go sleep guyz.

Lapse it is *but im dyin lol*:
https://lapse.hackclub.com/timelapse/tlmj2piRnfcS
(I got one break, 8 to 9hr of recording, i forgot to stop lapse, but after short snack break i forgot to turn it back on. I have 13hrs on my work timer ":skulker:")

Imagesss!
![img1](journalMedia/07-10_01.jpg)
![img2](journalMedia/07-10_02.jpg)
![img3](journalMedia/07-10_03.jpg)
![img4](journalMedia/07-10_04.jpg)
![img5](journalMedia/07-10_05.jpg)
![img6](journalMedia/07-10_06.jpg)
![img7](journalMedia/07-10_07.jpg)
![img8](journalMedia/07-10_08.jpg)
![img9](journalMedia/07-10_09.jpg)
![img10](journalMedia/07-10_10.jpg)
**Total time spent: 12 hours**



# July 11: anode day anode problym

Yeeee!
I soldered another motor driver... And now one is working flawlewsy and other one got problem with can.
I get only few messeges and i drop some, while other one with entirely same hardware works. 
Is there any specialist who knows how to CAN, not CANnot?

But hey! After all i got one can to working and now i somewhat learned it and understand it now!

Lapse:
https://lapse.hackclub.com/timelapse/sVqIrzqbEWA-
(Dinner break, 6.02 to 6.58, i forgot to turn off lapse)

Journal reel:
https://forge.hackclub.com/reels/146

Imagesss!
![img1](journalMedia/07-11_01.jpg)
![img2](journalMedia/07-11_02.jpg)
![img3](journalMedia/07-11_03.jpg)
![img4](journalMedia/07-11_04.jpg)
![img5](journalMedia/07-11_05.jpg)
![img6](journalMedia/07-11_06.jpg)
**Total time spent: 10.3 hours**


# July 12: It is literally bright outside lol

Today was a big day. Kidding. Just a long day lol.
From morning to about 7pm i was trying everything to make CAN work. It was warking flawlessly on one PCB and not on other. In the proces i touched +12v onto +3.3v and broke mcu. Good i have bought 4pieces of this exact mcu from ali like a month ago... right!
WROOOOONG! They were all wrong! I soldered one and for another long fucking work time, without realising was trying to CAN... on like 2AM i realised that this might be beacouse of aliexpress mcu. It didnt even cross my mind, beacuse they looked good!
When trying to initialize interrupts and timers mcu just stopps working... With light code, without anything, just while-loop there were no problemos my friendos....

So ye, after that i just joinked every mcu i had on my driver, soldering, desoldering, soldering, desoldering, soldering... and then! To my suprise! Last one was just working! one from batch of 4. 25% of working mcu. 75% Dead on arrival.
Hellye. So it just worked. What about second driver? I had to take serious decision. Desolder mcu from my other robot, and make it unusable or joinked this robot... Yk what i have done. OFC WE ARE DOIN RISKY WAY!

So after soldering and desoldering and cooking this poor PCB work like another one and a holf an hour (remember, this is ufqfpn-48, so very small pads, not so easy to solder) i got everyhitng to work. 

from 3.30AM to 4AM i was just clearing up code from testing and "trying to fix" leftovers. I will remember this night forever lol.

**BBBIG LESSON FOR EVEYRONE:**
**TRY NO TO BUY IMPORTANT ICs FROM ALIEXPRESS - THEY CAN SCAM YOU**
*resistor, capacitors, and other easy/passive components are okay, but VERY FUCKING IMPORTANT MCU might not be best idea to aliexpress*

Ahh yeee, and i got all line and distance sensors soldered and hooked up!

lapse froze and broke at 12hrs of recording... I realised this after a loooong time lol :skulk:. I started working around 11.30 in the morning and finished about 4.00 at night, with about two half an hour breaks, lets add another half an hour for stuff like eating snacks and times where i lost focus on main goal, etc...
Long lapse:
https://lapse.hackclub.com/timelapse/SSPbA1fPo_17
2AM lapse:
https://lapse.hackclub.com/timelapse/Cs3l5lJ24dIN

Imagesss!
![img1](journalMedia/07-12_01.jpg)
![img2](journalMedia/07-12_02.jpg)
![img3](journalMedia/07-12_03.jpg)
![img4](journalMedia/07-12_04.jpg)
![img5](journalMedia/07-12_05.jpg)
![img6](journalMedia/07-12_06.jpg)
**Total time spent: 15 hours**


# July 3: Last day before going offline for a week!

__ITS FLIPPING WORKS GUYS__

_67676767676767676767676_

(code writing, got to fix some minor soldering issues)
Lapse:
https://lapse.hackclub.com/timelapse/znTl7opDQoub

No images, but reels today!
https://forge.hackclub.com/reels/147
https://forge.hackclub.com/reels/148

__HELLFUCKINGYEAH__

_It is fully autonomus byt the way_

_nvm hers image, AI is mad at me for not having one_
![img1](journalMedia/07-13_01.jpg)
**Total time spent: 1.5 hours**