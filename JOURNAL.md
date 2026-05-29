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

![drivers](journalMedia/04-01_01.jpg)
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


# April 20: No chance, that i will route this thing and this will work at high frequencies...
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
![BJ example from JLC](journalMedia/04-29_01.jpg)
![SML example from JLC](journalMedia/04-29_02.jpg)
**Total time spent: 2 hours**


# May 03: More testing!
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
![prototyping](journalMedia/05-03_01.jpg)
![PCB1](journalMedia/05-03_02.jpg)
![PCB2](journalMedia/05-03_03.jpg)
![printin!](journalMedia/05-03_04.jpg)

**Total time spent: 11.3 hours**


# May 04: Is c0 an better idea?
After consultation with my coach we came up with idea of using smalle, stm32c011 MCU and using UART instead of CAN as communication.
I have remade PCB and schematics. While working i discovered that C011 is so much smaller, BUT it doesnt have DAC. Quick search on DIGI and i found some DAC on I2C.
So in SUM:
 - UART for communication with main MCU
 - HSE crystal
 - Debug serial wire
 - Gpio input NFault from DRV driver
 - 2*PWM output for driver
 - 3 ADCs for Temp, battery voltage and Current readout
 - I2C for DAC.

So uhm. After i made it i think about switching back to g431... After all it is more capable MCU and why not... Also can is better for noisy scenarios like meine.

Guys. I scraped changes. I thought why not if i already took the effort to put bigger MCU here? Its like 1 bucks diffrence and i got full CAN now!
I really wanted to do galvanic isolation, but i didnt manage to fit it. BUT. I organized texts and even added hackclub forge (guys give us bitmaps of your logosss)!
I think i am really done here and i can start with main controller pcb.
![mcu](journalMedia/05-04_01.jpg)
![schematics](journalMedia/05-04_02.jpg)
![PCB](journalMedia/05-04_03.jpg)
**Total time spent: 7.1 hours**


# May 05: CANing and Schmatiing
So after all of my effort i had to rewrite my schemtaics... yay..?
Thus i have like 7 pins left on MCU so its okay :)
Anyway, guys! Remember! To connect signal ports (these big blue ones, not small yellow ones) you HAVE TO USE signal harness! Not normal wire. I spent like hour figuring out what is wrong XD
Discovery came by mistake.... Yeah. It is awful. But i think schematics are done!

So uhm... Another problem. Annotation. Tools-Annottaion-Board Level Annotation. Here you can change how altium annotates, reset and re-annotate all components...

THE HECK! JLC WANT LIKE 70 BUCKS MORE FOR .15MM VIAS XDDD
I had to change everthjinnnnn

Thus... I think i have cooked today. I dont know how i will route this... But yk. TO BE COOKED OR COOKIN!
![overall](journalMedia/05-05_01.jpg)
![cubeMX](journalMedia/05-05_02.jpg)
![PCB XDDD](journalMedia/05-05_03.jpg)
![hello do anyone read this?](journalMedia/05-05_04.jpg)
**Total time spent: 9.9 hours**

# May 06: Burnout?
Today i have worked most of the time on main controller PCB. Yk some routing some parts placementr etcetra...
Yesterday evening i came up with few improvments for the 3D model.
I changed them to!
here they are:
 - Added holes to rotate back distance sensors to add space for cables if neccesarry
 - I added some place for thrust bearing in gearbox - we well se if it fits tho, beacuse it is tight fit 
 - Added a looot of fillets to make easier assembly
 - Changed fan mouting - now it is screwless. also he have little guard for protection now!
 - Chamfer for screw to go in!

I also think about adding buzzer to main PCB. We well think about that later. Thus i worked not-so-much i started feeling burned out... 
So no more work for today! Im going to sleepover with my friends and chill out with some board games!
Have fun guys but dont forget about your mental health!

![fan guard](journalMedia/05-06_01.jpg)
**Total time spent: 6.6 hours**


# May 07: Eat Sleep Program Design (spent some time with friends and came up with good ideas in meanwhile :)) repeat!
Beacuse we are going back to school tommorow, after holidays i have to do homework and accually learn for exams... This is saddd like yk i cant spent half a day in CAD.
Yesterday when i was at sleepover and my thought was wandering i got worried about one things. And this is accualy question for anyone who is reading this.
Do you think this is an issue? Or smth like that? Or with good lubrication it wont couse any issues?

*Im talking about this flange bearing and middle-sized gear. They have 0.1mm of clearance... This part of flange bearing is statics - it doesnt move of anything like that...*

Yeaaa... I lied... I didnt to all of my homework. Thus i have rims now!
I accually have *some* experience in custom wheels and rims. First of all, silicone is like a gel - it wont go throu .1mm hole or anythink like that! Rule of thumb is about 1.5mm minimum radius for silicone to flow throu. 
Secondly, it is really hard to pour silicone into mould when mold and rim have 1mm of diffrence in diameter! So keep about 3mm of "offset", without anny additional things to make your future life easier. So uhm... Experiment, try and learn guys! And remember, always wear protective gear! This thing *may* cause cancer for you futere self!

*Simpler the rim, the better the wheel... i guess... Thats how my brother used to say* Thus idk how my schools printer will be able to print it :)

So yeaaa... I lied agaid... Instead of doing homework i found smaller mosftets and made reverse currect protection. I had to delete all of the tracks from MCU, then move everything up a little bit and reroute everything back. Idk why altium is so bad to me... Thus now i have reverse polarity protection!

![fan guard](journalMedia/05-07_01.jpg)
![sketch](journalMedia/05-07_03.jpg)
![3d](journalMedia/05-07_02.jpg)
![mosfets!](journalMedia/05-07_04.jpg)
**Total time spent: 2.8 hours**


# May 08: I had to get up early to school. Such a shame.
Im tired. But it is wekend now!! I think i will have done PCBs in a week or so!
Today i routed few things, changes few things in 3D model. Also researched and checked price on JLCCNC. It was horribly expensive ;-;
Cames out, that mills accually exists and have *some* diameter. That why you need to add internal fillets when you design something for CNC! Bigger the fillet, smaller the machining time, lower the costs!
I managed to bring down price from about 150 bucks per plow to 35 bucks per two! (they were about 50 bucks for one so it is like... pay 50% more, get one free deal, so not bad).
Thus it was not a lottttt today unfortunatelly.

Also screw holes were in diffrent places from holes in CAD lol

![pcb](journalMedia/05-08_01.jpg)
![cncmill](journalMedia/05-08_03.jpg)
![JLC](journalMedia/05-08_02.jpg)
**Total time spent: 3.8 hours**


# May 09:OMFG MOM LOOK, THAT ME!
Thanks guyssss!
![me](journalMedia/05-09_01.jpg)
**Total time spent: 0 hours**


# May 09: *Clap calp* **TUDUTUDU Wake up Daddy's Home!** (thats my vibe nowwww!) (if anyone didnt catch, thats an ironman reference)
Yeah guys, i think i accually didnt explain one thing before. Low pass filter on ADC sensor lines and URAT lines. I use them, for analog signals, to not get messy and distorted by high freq nearby signals like PWM, uart, buck conv, it is just cleaner for MCU! There i use about 10k cutoff freq.
"Wait, if low pass filter is used to negate quick changes in signal, using it on uart wont make it junk and unusable for mcu?" Yeas, unless you use configure it to have veeery high cutoff frequency! I used about 500kHz cutoff here.
Normally i dont use low pass filter for uart, they are just not needed. But Beacuse of space saving im routing them *under* buck converter, which is just fast switching thing, so it generates a lot of noise. Good thing is that this noise for my buck is in 1Mhz-2Mhz spectrum,
so as i  said beffore, i added 0.5Mhz cutoff low pass filter, to cut off this noise! My uart is running 115200 baud, and chatgpt told me it is about 50kHz, but for signal intergriety and other electric shieniegasens you need about x2 to x10 higher cutoff freq, to not distort clean uart!
So put 30ohm and 10pF here.

As a thanks for picking me out, from all project decided to add buzzer, to annoy everyone i can think of :)
And one more IR receiver for start ir controls. (For sumo robot you want all of them - more ir receivers = lower chance of **not** picking out referee signal to start sumo fight).
And i made these small PCBs for rised ir recivers today

Also 4pin 1.27mm connector i found was discountinoued so i had to search for another one lol.
I found some 1mm ones, at the competition i willpray that they will not desintegrate and fight.

Mire routing and squeezing everything...

![IR receiver on rised schematic](journalMedia/05-09_02.jpg)
![IR receiver on rised PCB](journalMedia/05-09_03.jpg)
![controller](journalMedia/05-09_04.jpg)
**Total time spent: 9.4 hours**


# May 10: Ah yeas, the price of working too long last night
So yeeaeaa... It was as productive day as yesterday
Today every signa line got routed. Tommorow will be power lines.
New quick tip for you! Dont route fast signal lines near eachother (for example UART neart I2C, urat TX very close to uart RX, SPI to i2c, like every possible combination) (exception is ofcourse differentail lines like usb (d+, d-) or can (can high, can low), beacuse theye are like veeery noise resistant).
Thus why may you ask. Beacuse of electric interference. One quick changin wire near second one quick changing wire will make them both super duper noisy. Nobody like noisy signal. Analog signals dont care about it, beacuse they change greadually, and slow.
Thats why, i routed uart slightly apart.

I also exported PCB into cad (File>export as>.step) to check if i made any errors while settings boards shape, check holes aligment etcetra.
And yeah, it is lookin HELLA SICK!

Ceil too :)

![routinggg](journalMedia/05-10_01.jpg)
![hellye](journalMedia/05-10_02.jpg)
![ceil](journalMedia/05-10_03.jpg)

**Total time spent: 8.9 hours**


# May 11: Capabitiles of manufacturing ;-;
I checked JLC design capabilites, specially for vias. When i read it last time there was that vias need to be .3mm hole and .4mm diameter annular ring, so i followed that.
After reading it again i saw it... They can do .3/.4mm via BUT preffered for them is .3/.45mm (and bigger annular ring)... I had to change every via on controller and drivers .-.
Hellye... I guess...

Also i routed power lines!
And... Somehow ground...
Yeah, always remember to use Design Rule Checker to check you work.

I changed vias to pad in power microswitch - i done this beacuse im worried, that it myght short circuit on my metal gearbox lol.

GUYS I DISCOVERED NEW COOL THING!
Shift+S to get into cool one layer view mode
Then ctrl+shift+scrol wheel
This way i checked if i had any overcomplicated traces or vias which shouldnt been there!

![Bcool thing](journalMedia/05-11_03.jpg)
![microswitch](journalMedia/05-11_01.jpg)
![BURN THE WITCH!!!](journalMedia/05-11_02.jpg)

**Total time spent: 6.6 hours**


# May 12: Final touches and we are done!
Guys! I cooked so much!

Final touches, few disconnected GND lines, more than a few (lol) disconnected signal, overall cleanup.
And ofc ANNOTATIONS!
Remember to annotate! IT is sooo muchh easier to solder if you have good annotations.
And another important thing, annotate your connectors - add text for these gnd, power and signal lines (right beside connector) - you will not have to open you laptop to crimp these connectors in the future 😃

Additionally i spent some time on reseach on MOSFETS. I want one that are capable of high current with little-to-no power loss - beacuse power loss means HEAT!
And more heat equal more bad. Also i learned that if you use enough inneficient mosfet, it can desolder itself from PCB and cause big mess lol

In the qucik dinner breake I talked with my brother and he gave me some feedback! Here it is:
 - Check LDO footprint (it varies a lot and wrong one can couse a lot of problems)
 - Remove dead copper (more copper = more heat capacitance, BUT more dead copper = higher capacitance of traces so it is worse)
 - Straighted lines from EPROM (i2c is fast and dont like suddent changes in direction)
 - Bruh, low-pass filter on TX near MCU? The heck? - Yeah, it wouldnt work. low pass filter filter noise, but i put it before any noise was added to signal. nice.
 - Also i had to fix some power lines, beacuse i made GND tight necks lol (less space = higher resistance = higher noise and more heat -> So it is bad. We want alll of the space for comeback of GND)
 - Plated and non-plated vias ;-;... I had to fix them!
 - Also to make then (PCBs) in one chuck so it would be cheaper to order! - like yk, connecter all of the pcbs into one panel and order them as one pcb, cheaper!

*Indeed these cat annotations are abslutely necessary*
![front](journalMedia/05-12_01.jpg)
![back](journalMedia/05-12_02.jpg)

**Total time spent: 5.4 hours**


# May 13: JLC!
So If you want to but 3d printer parts from JLC, it not ADD>PAY>RECEIVE. Its more of sending them files, they rewiev it, then you send new version, then they may approve it or add another 60 bucks to you overall costs and then finnally they make it for you...
Yeah. Lesson for future me and all of you guys. It is a lot more work than i thought lol. Also always check your manufacturer capabilites. One more thing that came up unexpendictally is that they can do sharp edges - like lol, it just 45 degree mill and go brr, nothing crazy.
But the edge has to be dull, minimum of .5mm. Pretty sad, that i will have to sand a lot of material and blackening. Also i had to add little things, so they wouldnt complain (i had .5mm wall and their minimum is 1.5mm), to sand off later.

*I spent about 3hrs on thing freaking thing (isntead of sleepinn), but i think it shouldnt taken into time of improvment of this project, so i only journaled time accually spent in CAD*

![1](journalMedia/05-13_01.jpg)
![2](journalMedia/05-13_02.jpg)

**Total time spent: 1 hours**

# May 14: BOM and ceil!
Today i checked actual pricing in JLC and updated the bom accordlingly.
Also finnaly i had some time and motivation to make the ceil propely, and not quick and dirty way! (photos included ofcourse).

Qucik tip time!
If you want to extrude you image in inventor:
 - Convert it to black and white only (no gray, please)
 - Convert your image to SVG - beacouse we want vectors! (smth like https://convertio.co/ works)
 - ~~Use some webpage to convert it to dwg~~
 - ~~Open fusion 360 or autocad~~
 - ~~Nevermind... Accually open oneshape lol~~
 - ~~Import your image in SVG format~~
 - ~~Save file~~

NEVERMIN GUYS IT DOESNT WORK BUT I FOUND IT - I FOUND WEBPAGE CAPABLE OF CONVERTING SVG TO DXF.
https://cloudconvert.com/svg-to-dxf
Go check it out.
I spent too much time searching how to do this, so here you are :)

Also one cool thing i discovered is that you can group parts of you sketch with "create blox" - with that part of your sketch act as one.

*Pretty things took a lot longer than expreceted...*

![ceil](journalMedia/05-14_01.jpg)
![katze](journalMedia/05-14_02.jpg)
![ceiling!](journalMedia/05-14_03.jpg)

**Total time spent: 4.8 hours**


# May 26: Long break lol
Soo yeee... I started thinking about writing some simple code... But i have a lot to do at school right now lol.
I opened editor to adjust MCU configuration and i messed up badly lol.
Also yes i fixed MCU configuration where i could.

Always check your PCB before you are done with it lol.

![mcu1](journalMedia/05-26_01.jpg)
![mcu2](journalMedia/05-26_02.jpg)
![cube ide](journalMedia/05-26_03.jpg)

**Total time spent: 0.8 hours**


# May 27: I accually started doing something beacuse of streak system LoL
Retook images from CAD and Altium, polished readme, made proper BOM in .csv format. 
nothing serius. Just beeing consistent :)

Added BOM in .csv format and BOM section to readme.

Accually i took a look at some readme's and change mine.
credits for inspiration: https://github.com/notaroomba/cyberboard/

Also guys remember to have everything separated by "," and not by ";". I had to repair bom beacuse github was mad at me beacuse of it lol.
Also my github is tweaking...

![mcu1](journalMedia/05-27_01.jpg)
![bom](journalMedia/05-27_02.jpg)

**Total time spent: 1.9 hours**


# May 28: Research day
Not so much. As far as i want i will have massive pill of the code for this robot, so i wanted to do some multi-file programming thing.
Today i researched a bit about this, global variables, local variables and everything that sounds complicated lol.

Some nice page to read, about global variables and when they are acceptable: https://sqlpey.com/c++/when-are-global-variables-acceptable/
I think this is basic, but very important, for multi-file design: https://codelucky.com/c-multi-file-programs/

I still have to do some deep research on headers, beacuse they sound complicated and unecesarry for me, for now...

![research](journalMedia/05-28_01.jpg)

**Total time spent: 0.6 hours**


# May 29: ~Printin~!
Nevermind. I accually work same as before, but now i journal every small step, that i was like "meh, only 20min of work, i am too lasy to journal this.".
Now i actually journal this lol.

I changed a bit my distance sensor mounts/holders and printed them in school, so i wouldnt have to worry about them in future!
![3dmodel](journalMedia/05-29_01.jpg)
![printed](journalMedia/05-29_02.jpg)

**Total time spent: 0.3 hours**