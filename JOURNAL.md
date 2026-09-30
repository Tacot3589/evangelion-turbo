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


# May 30: Coding - start (first time using lapse... lemme know if link is accesible guys)
I never thought i like coding, but now i think i hate it lol.
I started by adding multiple .h and .c  and after thinking for a while and coding some other things i deleted them lol
I dont know how i will use them if i cant use variables from main. Writing function could be my soution, but we well see in the future.

One thing i wanted to point out is how i choose prescaler and counter period for timers, which are used to generate PWM signals for drivers.
Bigger freq = less noise, less torque and lower "speed" and more, a lot more EMI! Lower freq have unfortunalety more noise, but dont generate as much emi as higher ones. 
On the other hand going much lower than 20-30Khz can lead to very bad noise which you may hear (humans hear from 20Hz to about 20Khz) and unstable torque and speed of the dc motors.

*Also writing code for hardware i dont have yet is pretty hard. I cant test and write code in the same time. If i would write whole code now, and then get some errors, debuging this would be crazy.
[Im talking about hardware problems, STM32 is pretty...  whimsical lol. For example my oled wasnt working at my old robot, beacuse I2C was... too SLOOW. Like whattte helll]*

Oh and i would forgot. I added OLED libraries to my project! Guys, if you want to use oled, please do it the right way. Use DMA or interrupt, now polling. DMA and interrupt is soo much lighter on cpu!

Alsoo i got into measuring load of the cpu... Which comes out to be harder than expected lol
Like in the MCU everything works how you set it up... Unless it cant, beacuse next interrupt comes before end of the last one.
I have written some code - will test it and fix it in the future, when i will have hardware. Now i cant even check it lol

Guys my lapse... I have too slow internet for lapse for now. Network provider said that they will fix it by last friday. Yesterday the exceeded expectation and send another info, that they will fix it by next saturday.
Currently im trying to work on my phone hotspot but it is painfully slow lol

*Aarav please dont sue me for not having lapse while coding, it broke while i was trying to upload it😭*
![ioc](journalMedia/05-30_01.jpg)
![code](journalMedia/05-30_02.jpg)
![lapse](journalMedia/05-30_03.jpg)
![error](journalMedia/05-30_04.jpg)
![timer](journalMedia/05-30_05.jpg)
![how i feel](journalMedia/05-30_06.jpg)

**Total time spent: 3 hours**


# May 31: RAAAGHHH I CANT WORK IF LAPSE ISNT WORKING AND IM TRYING TO FIX IT INSTEAD OF WORKING

Laps freakin not workin. I also posted in lapse-help channel. Raghhhhhhh!
![beuh](journalMedia/05-31_01.jpg)


HORRAY! I managed to recover lapse!
I managed to recover yesterdays laps and make it smaller and faster! At the start i set stoper and at the end i also show it so i have about 3hrs and a few minutes lapsed :)
Video file is right here: "journalMedia/05-30_67.mp4"
![Video file](journalMedia/05-30_67.mp4)

*lol, it came through, i didnt believed that github would allow this lol*

*------------------------------------------------------*

Today we are doing research on how to clear signals from sensors - kalman filter, median filter, moving average etcetra.
Im trying to use lapse in google chroom instead of firefox this time, we well see if it helps and works now!

Best video of kalman filter i have found: https://www.youtube.com/watch?v=HCd-leV8OkU
This has a lot of information too: https://www.youtube.com/watch?v=jn8vQSEGmuM

After research  i think i will stick to ADRC or PiD in this robot. Kalman would be cool for IMU or predicting opponent location but it is hard and complicated!
![research](journalMedia/05-30_2.jpg)

Lapse link for todays research: https://lapse.hackclub.com/timelapse/bxvmavSPl1Jg

**Total time spent: 1.5 hours**


# June 01: Sending for review!

After quick thought process and qucik talk with my brother i decided to ground all of the metal parts and motor encosures with 1Mohm resistor and 100nF capacitor.
I am worriend that without this i would die of EMI lol

Also double checked everything before submitting. Wish me luck guys!

*have a nice day fellow rewiever :)*
![emi](journalMedia/06-01_01.jpg)

**Total time spent: 0.5 hours**

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


# July 13: Last day before going offline for a week!

__ITS FLIPPING WORKS GUYS__

_67676767676767676767676_

(code writing, got to fix some minor soldering issues)
Lapse:
https://lapse.hackclub.com/timelapse/znTl7opDQoub

No images, but reels today!
https://forge.hackclub.com/reels/147
https://forge.hackclub.com/reels/148

__HELLFUCKINGYEAH__

_It is fully autonomus byt the way... And its only 40% power!_

_nvm hers image, AI is mad at me for not having one_
![img1](journalMedia/07-13_01.jpg)
**Total time spent: 1.5 hours**



# July 20: 67

got oled to working ;-;
i got some problems beacuse my library didnt allow 64x32 oled, but after a lot of tinkering and help of unc google and chatgpt i managed to make it work!
Also all of my sensors, but one are working!
Lapse:
https://lapse.hackclub.com/timelapse/UPXGVnVu585F
![img1](journalMedia/07-20_01.jpg)
**Total time spent: 5.5 hours**


# July 22: Hello here

I got full init oled information! Now i know when my robot is talking with lidars, when with motor drivers and when he is ready!
*And when something is borked lol - say what you want but this is SO FUCKIN USEFULL*

Also i had one distance sensor not working, ya'll remember? I got it to work.
At the price of burning MCU. This time it is last one. 
Unfortunetaly in whole process i ripped like 3 pads, so i had to wire them by hand with .1mm copper wire :skulkerer:

And ye. As for today i have everything __BUT__ can :cry:
I dont know why. it worked before. But now i CANNOT ?-?!

Lapse:
https://lapse.hackclub.com/timelapse/jAqGxBFecOSW
![img1](journalMedia/07-22_01.jpg)
![img2](journalMedia/07-22_02.jpg)
![img3](journalMedia/07-22_03.jpg)
![img4](journalMedia/07-22_04.jpg)
**Total time spent: 7.4 hours**


# July 22: LOOKS SOOO FLIPPIN DOPE!

YAY! I got it from not working to working again! Replacing mainboard connector with new ones was the thing to do!
Now my drivers work!

Also i made ui and all of the nice cool stuff, like undervoltage protection!
My battery voltage redouts wasnt working so i just joinked it, removed protection diode and it is working like a bliss now looool

And yup, i had to solder some pads wiht 0.04mm (human hair is freakin 0.1mm bytheway) copper wire, beacuse i ripped like 6 od 7 padssss

It is miracle. I didnt believe it would work anymore.
More coding more coding, i also got to write whole START MODULE operations, like wait for signal, read signal, when signal set start_flag to TRUE, etcetra.

Aaalsoo some calculations. I have exactly 200MS to stop before going extinc!

Lapse:
https://lapse.hackclub.com/timelapse/-6MXYkGq6m6p
![img1](journalMedia/07-23_01.jpg)
![img2](journalMedia/07-23_02.jpg)
![img3](journalMedia/07-23_03.jpg)
![img4](journalMedia/07-23_04.jpg)
![img5](journalMedia/07-23_05.jpg)
![img6](journalMedia/07-23_06.jpg)
**Total time spent: 6 hours**


# August 04: Finnaly got my hands on start remote!

Comeback after long breakkkk! HELLYE!
Yesterday i borrowed start remote from out robotics club!
Without it i could propelly test IR receiver functionality. I had som shienienigans problems, but after long debuging and talking with chat, changing timer settings and SIRC/CR5 timeframes worked.
After that i changed a lil bit my rims, so i could cast them again. Ones i made before arent bad, but they are a little bit off center, which makes be angryyyyyy

so yeee! Coming after that i programed starting sequence, as rulebook require.
Remember guys to not use any HAL_Delay or SLEEP functions, if you are working mainly on interrupts, beacuse they will break your cede lol.
Literally. They will render it unusableee.. Why? Beacuse MCU tries to do his job at working out all of your functions event and interrupts, when YOINK! NAH MEN - you gotta wait for SLEEP(67) miliseconds, lol
And everything breaks!

Lapse:
https://lapse.hackclub.com/timelapse/j1nPhS0W8PA5
![img1](journalMedia/08-04_01.jpg)
![img2](journalMedia/08-04_02.jpg)
![img3](journalMedia/08-04_03.jpg)
![img4](journalMedia/08-04_04.jpg)
**Total time spent: 4.9 hours**



# August 05: Last day of work before competition...

Last day...
Today i got rims which i designed yesterday, from my brother and casted them. Ofc they didnt hardened yet, but they will be ready for championship!

I have wrote attack sequences and all of that. I wanted to add one attack mode, in which robot just go into circles on the edge of the dohyo, to suprise opponent and gain high ground...
But after all i suck at line following, so no-good. I lost it all lol. No line following for me :)
Problem may be that i for that i can only use 2 sensor, one on the front and one on the back, which may be not enought for smoooth line following experience.

Maybe i will rock it at the beggining of the championship, if i will have some time for minor fixes and additions like that!
So guys... Wish me luck at the "RoboRAVE Word Championship 2025"!

*ah yes, also i added proper photos to readme! Im more than these prototype-shit photos lol*

Lapse:
https://lapse.hackclub.com/timelapse/Y0BkItvrs7Am
![img1](journalMedia/08-05_01.jpg)
![img2](journalMedia/08-05_02.jpg)
**Total time spent: 3 hours**


# August 10: Night before competition

Today i made all of the check before competition.
I didnt know it before, byt dohyo at RoboRave have reversed color -> i had to reprogram line sensors.
Alsooo they sent everyone an email at 2AM, that they changed rules and starting sequence...
I HAD TO FUCKING REPROGRAM THIS SEQUENCE AT NIGHT BROSSS.

Also i spent like 4hr at sharpeping my front plow. I hope it will be better than these guys sharp knifes!

![img1](journalMedia/08-10_01.jpg)
**Total time spent: 6 hours**


# August 11: First competition day!

Im fucking furious and not in the same time lol.
Today i spent full day testing and fixing robot. I was supposed to have more than half of planned fights, but organisation was so cooked, that i didnt had even one fight lol.

I had so much problem w ith line sensors. They were cooked. After a lot of testing i found out, that when line sensors is far from ground plane it dont sense any received ground, same as on black - while sensors is over white it sense all of the emited light. Main poroblem is that i have short robot and My front constantly go up, beacuse of my freakin powerfull motors!

Main idea to fix it was to add accelerataion curve. Instead of going FULL POWER FOR MOTORS i changed into give them little bit more than before, until hits 100% PWM. Not they work okayish!

After that i fixed some attack code, got all of the values for velocities, max speed, distances etcetra.
And that was it for a full day!

In the night i tried to make line follower mode work at faster speeds but with none success... The main problem is that i have not enough line sensors, so it is just borked. At the beggining i tried to do PID tuning, but pid with one digital sensor isnt really pid LOL. It is just a D i think.

So i sticked with normal ELSEIF statements and i managed to somewhat use Front as well as Back line sensor. 
After all it was too borked to use it safely in a competition, so i didnt use it at all.

![img1](journalMedia/08-11_01.jpg)
**Total time spent: 12.3 hours**


# August 12: Competition date!

Competition dayyy!

I got some fights! As yesterday we arrived there like 3hrs before start of the competition, so about 8AM and stayed there till 6PM.
Thanks to that i got pleeeeenty of time for actual testing. Thanks to my friend (WHO ACTUALLY GOT 1ST PLACE AT WHOLE COMPETITION!!! CONGRATS MANIEK!) i discovered that my distance sensors arent working propelly.

I had to lessen filtration and add some IFs. I changed AMP treschold little bit down and added statment, when distance is lower than about 10CM, then i dont care about AMP... AMP is strenght of received IR signal. This is why these sensors dont costs 5bucks lol. They work like a charm <3

With some robot to test against I perfected values to attack and curve attack.

Reels from fight!:
https://forge.hackclub.com/reels/170
https://forge.hackclub.com/reels/171

*Guys, i pushed out FUCKIN 3KG ROBOT while my weight was 850G only LOL*

After all of the fights i reached my conclusion that:
    - My plow wasnt as hard as i wanted, and my opponets plows were sometimes sharper
    - I want a little bit more distance sensors in future robots
    - Overall it is a great robot!

*Also quick readme update with certificate!*

![img1](journalMedia/08-12_01.jpg)
**Total time spent: 6.4 hours**