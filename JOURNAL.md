---
title: "Evangelion Turbo"
author: "Szymon Filipkowski"
description: "Evangelion Turbo is an SUMO robot of footprint 10x10cm and weighing less than 1kg. It is direct successor to my last robot, Evangelion. Evangelion have 4 distance sensors, 4 line sensors, IMU, oled, UI and maybe even enkoders (idk if i will fit them tho)"
created_at: "2026-03-16"
---



# March 07: Designed the PCB layout
First idea. I decided that i want to go with Pololu 37D chunky motors - beacuse they are more powerfull and more chunkier than motors i have in my previous robot, Evangelion.
I revied every option i had on had. Pololu 25D, some chinese motors, like RS395. Pololus seems the best for this. We well see what CAD will tell thus.
![Layout](journalMedia/03-07_01.jpg)
**Total time spent: 2 hours**


# March 09: CADding!
So today i spent some time playing with cad, sensors ETC. CAD told me "NAH" pololu 37D would be too big :(
I really wanted to FORCE THEM TO FIT... So i spent a looooot of time trying anything. After all i decided that they are too heavy (bcoz i want this robot to be able to start in 500G weight too).
Sooooooo i decided to put same motors as in my previous robot, evangelion! And to make them better, take out one gear from gearboxes, making this robot a lil bit faste (19:1 changed to 7.5:1).
Gears from pololu 37D already worked for me so for this robot i plan to use it too, but orded cheaper, from aliexpress, instead of the original ones. I added them to cad and made all of the needed constraints.
I measured and added LIPO batteries to test if i even can fit any of them (2s and 3s, 450 and 550mAh).
Aaaalso i made double shear bearings, like in the VORONs. I like 3d printer and vorons :)
![CAD](journalMedia/03-09_01.jpg)
**Total time spent: 8 hours**


# March 10: Who needs school when you can sit in the CAD, talk with your friends and do cool stuff?
Parents made me go to school today ;-; soo sad.
But anyway. WHO NEEDS 2 SENSORS WHEN YOU CAN HAVE 8 OF THEM! I managed to fit 8 sensors in 10x10cm sumo robot. 2 laser distances at the front. 2 IR distances pointing to the sides. 4 line sensors in each corner.

![CAD1](journalMedia/03-10_01.jpg)
**Total time spent: 4 hours**


# March 11: WHO NEEDS 2 SENSORS WHEN YOU CAN HAVE 10 OF THEM
YESSIR! There are 10 of them now! I managed to add extra two IR distance sensors!
HELLNAH, yesterday i forgor that wheels _do_ exists. I had to made back sensor tilt a little bit. But they are two more of them now :) Overall it was an good evening.
TBH I dont know why it takes so much time to fit everything into so big footprint (wait... this is only 10cm so it is small XD)
![CAD1](journalMedia/03-11_01.jpg)
**Total time spent: 3 hours**


# March 21: Competition time!
I mounted IR sensors i planned to use in this robot, in Evangelion (my previous robot which is working). I spent a few hours trying to force SHARPs (these IR sensors) to work! It turns out that these types of sensors are literally _shit_. They are painfully slow and very innacurate.
Yup. beacouse of them i have lost ;-;
Feels bad - thus not so bad, beacuse i tested sensors now, not on the RoboRave, abroad!
**Total time spent: 2 hours**


# March 23: GUYS VERY GOOD INFO!
I talked with my teachers. They let me attend only the most important lessons (like math, polish, english and physics)! No stupid history for now! I can work more! Lets goooooooooooooooooooo. :DDD


# March 25: Safety first!
After some research and rethinking my life choices i decided to bury cool idea od 10 sensors and steep front. I had to move everything to the front, to leave more space for laser sensors, to fit. After more research, big problem came up to me. EMI will kill all of my capabilities. After searching i found some motor shielding - about .7mm thick. I think it will be enough. If not - then im cooked guys.

Moving everything in cad .7mm BROKE EVERY CONSTRAIN IMAGINABLE...
remember guys. always constrain your parts to origin planes, not other parts.

So i had to spend more time redoing everything :|

After dinner i added interface board with oled.
![CAD1](journalMedia/03-25_01.jpg)
![CAD2](journalMedia/03-25_02.jpg)
**Total time spent: 7 hours**


# March 27: Mom, look! My MCU barely fits there!
So today. Today is the big day. No procrastination and rotating model in CAD. Pure lock-in in PCB design.
Guys. If you dont use Library Loader - start using it. I discovered it via random problem in reddit. IT IS SO HELPFUL. Like you can add any part without losing time on rewriting it.

For the work, today i have made MCU with all the ports, IOC in stm32cubeide, with all of the PINs configure, power supply and low pass filter for filtering anything from analog channels.

![Mcu schematics](journalMedia/03-27_01.jpg)
**Total time spent: 4 hours**


# March 28: Any UI/Ux designer to help me? Pwetty Pwaseeeee
From the beggining of this project i wanted to use OLED without stupid additional useless piece of PCB they ship it with. My friend, managed to pull it off on his LineFollower, so i think it may _(please, work, please)_ work.
I found schematics for OLED in some random chinese website written in chinese, so wich me luck XD

![OLED](journalMedia/03-28_01.jpg)
**Total time spent: 3 hours**


# March 29: Interface? Not the UI tho
Today, at school, i thought "Wouldnt be cool to have one push button, to turn on and off robot? And ofc fully electrical/mechanical, no GPIO involved". Yea guys. Its alive. After tinkering in electric simulation and coutless arduino toturials i have found it.
I was bored, so i also made schematics for power supply. Buck conv from lipo 3s to 5v and ldo from 5v to 3.3v.
![Soft latching button](journalMedia/03-29_01.jpg)
**Total time spent: 4 hours**


# April 1: High current? Please be enough this time
In my previous robot, Evangelion, motors were highly limited by drivers (they were limited to about 3A). Theoretically motors in spike are pulling about 5A and drivers could withstand up to 4.2A. But taking no cooling and hot chasish into consideration DRV8251 limited them to aboud 3A. So for this robot i made good research and settled on to use DRV8873 drivers. Max 10A in spike. No external mosfets, for easier routing. I want to fit two motors drivers between motors, so there is little space there.

GUYS! You can choose from hardware and software version of this driver. It accually is little driffrence. In hardware you use resistors etc to change max AMP for example, in software you do this via SPI. In both versions you need to control both drivers via PWM tho.

![drivers](journalMedia/04-03_01.jpg)
**Total time spent: 3 hours**


# April 2: LOCK-IN. I may have skipped school.
Big lockin today it was. I finished doing all of the interface-controller board schematics. I didnt know how would i connect my three boards! After some research and talk with my brother, he adviced me to use BTB connector. After searching for a while i found 40pin one :D
40pin - OLED, start module, SPI to drivers, 5v, 3.3V, joystick... A lot.

Schematics for IMU and EPROM done too today!
And i even managed to fir buzzer here! (Like it is hard to do schematics for one ;-;)
Also did you guys heard about STLINK? I wanna have it on board. Research for any schematics.

Im really exhausted tho...
![Schematics1](journalMedia/04-02_01.jpg)
![Schematics2](journalMedia/04-02_02.jpg)
![Schematics3](journalMedia/04-02_03.jpg)
**Total time spent: 10 hours**


# April 3: STLINKIN
I wanna stlink. On my robot.
After yesterday's research i have schematics from some random guys from github. CHATGPT told me, that i need to have some f103 MCU for this to work, and i cant use something like C0 in really small casing. At first glance i wanted to use smallest f103 I could find (something like f103 in case with BGA out pins). BUT THIS WOULDNT WORK! Chatgpt and datasheets - in the official code there are pins, that are missing in smallest f103 in bga. Soo i was forced to use some normal, big f103.

Did you know, you could damage your PCB if you dont have proper safety diodes added? I know right, this is cool physics stuff. But not cool tho - i have to add more compontents...
Yeah. You are thinking right. USB-C schematics - made by me :)

_please fit in my PCB, please fit. im worried. ik, maybe i will go with 4lyaer PCB thus?_

![link](journalMedia/04-03_01.jpg)
![usbc](journalMedia/04-03_02.jpg)
**Total time spent: 6 hours**


# April 4: Good sleep = Good, new ideas and HUGE AMOUNT OF ENERGY!
I may have made gearbox holders in one day or may i not... I have experience tho (yes, i made them entirely today XD)
A lot of work done today:
 -Gearboxes
 -Interface board shape with more space for ICs
 -back sensor mounts

Im hungry now ;-;
![gears](journalMedia/04-04_01.jpg)
**Total time spent: 7 hours**


# April 5: Another day, another day...
Anothe day anothe day.

Today i made front mount... front face... Idk how to call it! It is a part which holds line sensors (no screws needed!), distance sensors, battery and the plow. I had to add place for wires inside XD

Also i learnt something cool today! You can see through parts with "section wiev"! Like now motors or gearbox dont inrerrupt me or i dont have to change visibility of certain object every 30 seconds

Also remember to angle you distance sensors, so they wont hit and detect ground! By brother came up to my room for something, and adviced me to do this. And i think is has a looot of sense!

![cad1](journalMedia/04-05_01.jpg)
![cad2](journalMedia/04-05_02.jpg)
![cad3](journalMedia/04-05_03.jpg)
**Total time spent: 6 hours**


# April 6: DA HELL
Guys what the hell. I want to change a few parts but i cant! I dont know what the hell happend in my cad. Could you help me?
I have a lot work to do for school's 3rd year project, so i will just do this today, and come back to CAD tomorrow.
![cad1](journalMedia/04-06_01.jpg)
**Total time spent: 0.1 hours**


# April 7: Front plow - sctrok plow
Today i customized front plow to my needings... requiements ;)
Also after beating and beeing beaten by cad for a while i managed, to make front mount adapt to plow. Like yk, i want to have longer plow, i edit its own base sketch, update assebly and BLAH! Now front i auto updated to plow :D
It made my work a lot easier thus. To achieve this i used something called "Project Geometry" which adaptively project geometry from some object into sketch. Also a lot of contraints to not break anything ;)
![plow type 1](journalMedia/04-07_01.jpg)
![plow type 2](journalMedia/04-07_02.jpg)
**Total time spent: 2 hours**


# April 8: 3d model is done done done?
I think 3d model is finnaly done!
I changed my mind, and made plow, like, a loooot bigger. I want my weight to be at the front. If it wasnt my robot could do somehting like wheele, and we dont like it, beacuse it is easier to push me off if i dont have my plow on the ground. Inventor sais it is now about 50g inseat of 20g, so it is looking very good. Also i made ceiling, beacuse why not.
Adding cutouts in plow for line sensors was a little bit of more work - i had to tinker with dimensions and contrains a lot. After all i just YOINKED one hard coded dimension and this is now all okay and changes by itself to be okay!
![plow](journalMedia/04-08_01.jpg)
![ceil](journalMedia/04-08_02.jpg)
**Total time spent: 2 hours**


# April 9: Sharpie Sharpie Sharpen?
I printed all of the parts in school, to test all of the fittments. Before printing, while i was tinkering with this PEI plate i came with idea of making front of the robot with something similiar, but more thinner and flexible. I think it will be very cool and sharp! I made quick sketch, we well see whats comes out of this.
After printer was done i assembled it and added insert. See image :D

...Thus i dont know what i will do with motors wire connectors ;-;
This is "my futures me" problem i suppose :D

PS. These are replacement motors from Evangelion, not these stronk ones i have found on aliepxress, for Evangelion Turbo. But they are in same dimensions so yk...
![springsteel](journalMedia/04-09_01.jpg)
![3d printer parts! 1](journalMedia/04-09_02.jpg)
![3d printer parts! 2](journalMedia/04-09_03.jpg)
![3d printer parts! 3](journalMedia/04-09_04.jpg)
**Total time spent: 3 hours**


# April 13: doom.
F... FFF... UC...
I realised thad 0mm of clearance is to small. I moved everything by .7mm.
![doom 1](journalMedia/04-13_01.jpg)
![doom 2](journalMedia/04-13_02.jpg)
**Total time spent: 0.1 hours**


# April 14: We have our robotics club meeting today, so it okay :)
I talked about this with one of the students from our club and chatgpt. I was told to do:
 - Make a not-adaptive sketch in inventor
 - Make all extrusions you need from him
 - Make sure it all extrusions you need, no extrusions more after next steps
 - Go back into editing sketch
 - Now, project least geometries you need to make tou sketch fully stable
 - Change back to beeing adaptive
 - It shouldnt breake anything now, when you move something

This is very consuming way to do anything, but for me it works for now.

So... yup. I made gearboxes and front mount from scratch.

I have overall ideas and how everything should look like, so it took less time than when i was making everything for the first time
![undoomed 1](journalMedia/04-14_01.jpg)
![undoomed 2](journalMedia/04-14_02.jpg)
**Total time spent: 8 hours**


# April 15: Guys do you think this is a good idea?
I would have like 2mm *2 more space for routing PCB, on the other hand i risk shorting, like... *everythin*.
![more pcb?](journalMedia/04-15_01.jpg)
**Total time spent: 0.1 hours**


# April 15: PCB Interface
I changed and fixed few minor things is schematics.
It was tiring but i have all things arranged now. I dont know how i will route them tho XD

![schematics](journalMedia/04-15_02.jpg)
![pcb](journalMedia/04-15_03.jpg)
**Total time spent: 4 hours**


# April 16: PCB Interface
I spent my time at computer today reading JLC rules and guidelines for manufacturing PCB. Did you know, white and black soldermask requie at least .13mm? While other colors minimum space in only .1mm? This may make a big diffrence in small PCBs! I have my rules i made in repo ("MyRules" file). I also searched and found some smaller connectors, beacuse there is no way these JST 1mm i have put would work efortlessly.

JLC link to their site: https://jlcpcb.com/capabilities/Capabilities
![pcbiing](journalMedia/04-16_01.jpg)
**Total time spent: 4 hours**


# April 17: GUYS WHO LOVES COLD AIR!
HELLYEEE! Cold electronics = good electronics! Also now i have more downforce and grip (like 1g, but still).
I Also deleted few uninportant things from PCBs, like soft-latching button (ik its so coool, but i have no space on PCB... Its so sad...)

PS. Why the hell such small fan costs more than like 4010 fan? They want like 10 bucks for something this small.
I will search on ali, maybe i will find something cheaper thus.
![SHHHHHHHHHHHHHHHHHHH](journalMedia/04-17_01.jpg)
**Total time spent: 2 hours**


# April 18: METAL METAL (i want CNC in home)
A lot minor but important changes today! Biggest and most important from them:
 - I want all of my parts made from metal! (please CNC from JLC dont kill me with your price)
 - I made my own wheel HUBS
 - Updated all of the parts to metal
 - Front line sensors are now Screw-Mounted (No screw mounting is cool, but JLC might have a problem with manufacturing such thin wall - screw mount have no thin walls, so its okay)
 - Reinforced front a little bit - no obvious weak spots for now
 - Interface is now 2mm wider thanks to no gearbox cover walls!
![model](journalMedia/04-18_01.jpg)
![hubs](journalMedia/04-18_02.jpg)
**Total time spent: 4 hours**


# April 19: Motors motors motors... Drivers? I wanna bigger.
I think i have PTSD beacuse of Evangelion. His drivers (drv8251) are limiting him to about 70% of his max powers. AND to add into function his motors are... weak.
For this project - Evangelion Turbo - my most complicated robot i wanted to go with bigger drv driver, with inner MOSFETs. I though it would be enought. My friend, Michal, had put them in his line follower and it is driving flawlessly. Unfortunatelly i have PTSD. I think i need to go bigger. Reaserch, reaserch reaserch... DRV8702 - external MOSFTES driver. All of the current i need. I think it will be perfect, I dont know how i will fit it. We well se... Schematics done!
![schematics driver](journalMedia/04-19_01.jpg)
![schematics mcu](journalMedia/04-19_02.jpg)
**Total time spent: 5 hours**


# April 20: No change i will route this thing and thi will work at high frequencies...
I redone HUBS. Little flanges was added, to make wheel more stable.
I added and arranged nearly all of the parts on the PCB. 2 Layers will not be enought, which is sad, beacuse theye are cheaper... We well see.
![hubs](journalMedia/04-20_01.jpg)
![PCB back](journalMedia/04-20_02.jpg)
![PCB front](journalMedia/04-20_03.jpg)
**Total time spent: 2 hours**


# April 22: Will it work tho?
Its a mess. I decided to use one of middle layers exclusively for GND, middle layer mainly for VCc, top and bottor for everything else. Idduno men its a lot of work, thus not so much to journal...

![PCB 1](journalMedia/04-22_01.jpg)
![PCB 2](journalMedia/04-22_02.jpg)
**Total time spent: 8 hours**


# April 25: More time spent on PCBiing
More routing... Routing Routing Routing.

As a brake i changed HUBS, to easier shape and easier manufacturing.
Additionally I change aaalll of the holes to "screw", from shape of heat-set brass insert - like men, have you tried putting heat-set brass insert in metal? I have not and i dont like to.

Also guys! Never ever forget about you connectores! I realised today, that batteries *have* a XT30 connector, and theye are not wired *wirelessly*...

![CAD](journalMedia/04-25_01.jpg)
**Total time spent: 3.5 hours**


# April 26: Get the exorcicsts! For whom!? For me!
routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing routing

![pcb](journalMedia/04-26_01.jpg)
![edge](journalMedia/0I_am_living_on_the_edge.jpg)
**Total time spent: 4 hours**


# April 27: Do you think it is done? Nah. Try DRC.
So uhm.. "Design Rule Check". Yk, this little think that tells you, that you silk mask clearence is too small on 53 elements, or your via-to-via distance should be bigger? Yup. I have more than 500 errors XD.
I fixed alll of them! Now, i think it is fully done. I am sending this to my robotics coach to check it, and i will come back with his feedback!
![pcb](journalMedia/04-27_01.jpg)
**Total time spent: 6 hours**


# April 28: PCB into model
If you didnt know you can export PCBs from you favorite pcb software into step files!
In footprint i have used 3mm bullet connectors, but i can fit only 2mm ones, sooo... BRUTE FORCE! YAY!

Now everything fits.

My little cute motor driver :)

![CAD](journalMedia/04-28_01.jpg)
![CAD](journalMedia/04-28_02.jpg)
**Total time spent: 0.5 hours**


# April 29: Guys i got feedback from my coach.
Hes an engineer and work at BTW so hes got the *knowlege*.
...
He said quote: "Hey, Szymon, If you told me you wanted spaghetti, i could order you one. You didt have to make on on you PCB"
...
Yieiks.
...
About good info, he advised me to use MOSFETS in DFN33, not 5x6 i curretlny have ("Its only 15A, not 100A, it will be okay"). And more important, to divide Mosfters and drivers and controll into something like senctions. Like yk, electric interference etcetra. Better driver.
I will work on that, but i think i will stick to 4 layer PCB, beacuse it is only like 4 bucks more expensie, but makes routing a loooot easier.

After all i felt productive and devastaded today, so i made some research about pricing and options in metal parts. I found out that CNC is hella expensive, but you can get BJ or SML parts for pretty good bang for a buck.
I will prob use JLC, beacuse i orded PCBs from there too
![BJ example from JLC](journalMedia/04-29_01.png)
![SML example from JLC](journalMedia/04-29_02.png)
**Total time spent: 2 hours**


# May 04: More testing!
After some break and spending time with my GF i am back!
My brother suprised me, he ordered for me one steel front! For the competition i will need to orded few more, theye are very prone to braking.
After tapping aall of the holes and assembling it i had to change:
 - Gearbox covers - walls (im afraid of shorting anything) and clearances to gearbox
 - Gearboxes clearances for bearings
 - Place of holes for the laser distance sensord (bruh, they are all wrong XD)
 - Updated battery model and the xt30 connector
 - Changed front mount so i will have place for connectors from battery etcetra
 - Add place for cables from front sensors
 - Back steel reinforcment plate
 - Made front more steeep, yay!
 - Aaalso Im thinking about burring whole *spring steel* front idea

So uhm... After my coach told me my PCB is trash, i had to redo everythinkkkkk... WHYYYY..
This time i used smaller mosfets and payed SO MUCH MORE attention to clarity. Im sending it to my robotics coach now, we well see what he will say.
Also i found and used a few smaller components, like smaller quartz or bullet connectors (2mm instead od 3mm ones).

HELLYE! My brother agreed to print my parts on his ender (thus  only most important ones...)!
It will be junk, but not junk enought to test!
![prototyping](journalMedia/05-03_01.png)
![PCB1](journalMedia/05-03_02.png)
![PCB2](journalMedia/05-03_03.png)
![printin!](journalMedia/05-03_04.png)

**Total time spent: 11.3 hours**