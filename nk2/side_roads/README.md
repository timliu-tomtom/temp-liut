
Given no side road required for HOV
hov stop, waypoint and toll not stop
  - container
    -- missing side road for fork if there is side road before hov enter generation point
    -- missing side road for waypoint if it is in the sequence of hov exit generation ranges
  - provider (pass last_instruction_offset)
    -- extra side road if waypoint is between [hov enter, hov exit]
       it takes fork (before hov enter) as last_instruction_offset
       (to fix - pass far away instruction offset to generate() as well)
hov not stop, waypoint and toll not stop
  - container
    -- ok
  - provider (pass last_instruction_offset)
    -- ok

hov stop, waypoint and toll stop
  - container
    -- missing side road after waypoint
    -- missing side road for fork if there is side road before hov enter generation point
    -- missing side road for waypoint if it is in the sequence of hov exit generation ranges
  - provider (pass last_instruction_offset)
    -- extra side road if waypoint is between [hov enter, gereration of hov exit]
       it takes fork (before hov enter) as last_instruction_offset
       (to fix - pass far away instruction offset to generate() as well)

hov1
====
TTDebug, Generate() start, last_instruction_end_offset 0 cm===========
TTDebug, Genreate() last line length 5349 cm, end offset 3300 cm
TTDebug, process inst type Departure, offset 0 cm
TTDebug, max of last_instruction_end_offset 0 cm, instruction.offset 0 cm
TTDebug, request side road [0 cm, 0 cm
TTDebug, udpate last_instruction_end_offset to 0 cm
TTDebug, process inst type Turn, offset 3300 cm
TTDebug, max of last_instruction_end_offset 0 cm, instruction.offset 3300 cm
TTDebug, request side road [0 cm, 3300 cm
TTDebug, udpate last_instruction_end_offset to 3300 cm

TTDebug, Generate() start, last_instruction_end_offset 3300 cm===========
TTDebug, Genreate() process line length 6351 cm, end offset 9700 cm
TTDebug, Genreate() process line length 3315 cm, end offset 13000 cm
TTDebug, Genreate() process line length 11167 cm, end offset 24200 cm
TTDebug, Genreate() last line length 11250 cm, end offset 35500 cm
TTDebug, process inst type EnterHov, offset 228884 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 228884 cm

TTDebug, Generate() start, last_instruction_end_offset 3300 cm===========
TTDebug, Genreate() process line length 21162 cm, end offset 56700 cm
TTDebug, Genreate() process line length 4617 cm, end offset 61300 cm
TTDebug, Genreate() process line length 46488 cm, end offset 107800 cm
TTDebug, Genreate() process line length 33316 cm, end offset 141100 cm
TTDebug, Genreate() process line length 19413 cm, end offset 160500 cm
TTDebug, Genreate() process line length 28948 cm, end offset 189400 cm
TTDebug, Genreate() process line length 6107 cm, end offset 195500 cm
TTDebug, Genreate() last line length 29391 cm, end offset 224900 cm
TTDebug, process inst type Fork, offset 224900 cm
TTDebug, max of last_instruction_end_offset 3300 cm, instruction.offset 224900 cm
TTDebug, request side road [124900 cm, 224900 cm
TTDebug, udpate last_instruction_end_offset to 224900 cm

TTDebug, Generate() start, last_instruction_end_offset 224900 cm===========
TTDebug, Genreate() process line length 45471 cm, end offset 270400 cm
TTDebug, Genreate() process line length 28003 cm, end offset 298400 cm
TTDebug, Genreate() process line length 44038 cm, end offset 342400 cm
TTDebug, Genreate() process line length 16022 cm, end offset 358400 cm
TTDebug, Genreate() process line length 31594 cm, end offset 390000 cm
TTDebug, Genreate() process line length 66969 cm, end offset 457000 cm
TTDebug, Genreate() process line length 17344 cm, end offset 474300 cm
TTDebug, Genreate() process line length 4541 cm, end offset 478800 cm
TTDebug, Genreate() process line length 102077 cm, end offset 580900 cm
TTDebug, Genreate() process line length 21865 cm, end offset 602800 cm
TTDebug, Genreate() last line length 12322 cm, end offset 615100 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() last line length 60090 cm, end offset 675200 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() process line length 3891 cm, end offset 679100 cm
TTDebug, Genreate() process line length 23116 cm, end offset 702200 cm
TTDebug, Genreate() last line length 24915 cm, end offset 727100 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() process line length 29645 cm, end offset 756700 cm
TTDebug, Genreate() last line length 32644 cm, end offset 789300 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() last line length 17889 cm, end offset 807200 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm
TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() last line length 57837 cm, end offset 865000 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 228884 cm===========
TTDebug, Genreate() last line length 43894 cm, end offset 908900 cm
TTDebug, process inst type ExitHov, offset 908900 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 908900 cm

TTDebug, Generate() start, last_instruction_end_offset 908900 cm===========
TTDebug, Genreate() process line length 19527 cm, end offset 928400 cm
TTDebug, Genreate() process line length 29937 cm, end offset 958300 cm
TTDebug, Genreate() process line length 18418 cm, end offset 976700 cm
TTDebug, Genreate() process line length 32457 cm, end offset 1009200 cm
TTDebug, Genreate() last line length 51029 cm, end offset 1060200 cm
TTDebug, process inst type Fork, offset 1060200 cm
TTDebug, max of last_instruction_end_offset 908900 cm, instruction.offset 1060200 cm
TTDebug, request side road [960200 cm, 1060200 cm
TTDebug, udpate last_instruction_end_offset to 1060200 cm

TTDebug, Generate() start, last_instruction_end_offset 1060200 cm===========
TTDebug, Genreate() process line length 35693 cm, end offset 1095900 cm
TTDebug, Genreate() process line length 17438 cm, end offset 1113300 cm
TTDebug, Genreate() process line length 3474 cm, end offset 1116800 cm
TTDebug, Genreate() process line length 16751 cm, end offset 1133600 cm
TTDebug, Genreate() process line length 32108 cm, end offset 1165700 cm
TTDebug, Genreate() process line length 47329 cm, end offset 1213000 cm
TTDebug, Genreate() process line length 17579 cm, end offset 1230600 cm
TTDebug, Genreate() process line length 50408 cm, end offset 1281000 cm
TTDebug, Genreate() process line length 10465 cm, end offset 1291500 cm
TTDebug, Genreate() last line length 45015 cm, end offset 1292700 cm
TTDebug, process inst type Arrival, offset 1292700 cm
TTDebug, max of last_instruction_end_offset 1060200 cm, instruction.offset 1292700 cm
TTDebug, request side road [1192700 cm, 1292700 cm
TTDebug, udpate last_instruction_end_offset to 1292700 cm



hov2
====
TTDebug, Generate() start, last_instruction_end_offset 0 cm===========
TTDebug, Genreate() process line length 55831 cm, end offset 16700 cm
TTDebug, Genreate() process line length 117763 cm, end offset 134500 cm
TTDebug, Genreate() process line length 29829 cm, end offset 164300 cm
TTDebug, Genreate() process line length 18780 cm, end offset 183100 cm
TTDebug, Genreate() process line length 38600 cm, end offset 221700 cm
TTDebug, Genreate() process line length 18388 cm, end offset 240100 cm
TTDebug, Genreate() last line length 51260 cm, end offset 291400 cm
TTDebug, process inst type Departure, offset 0 cm
TTDebug, max of last_instruction_end_offset 0 cm, instruction.offset 0 cm
TTDebug, request side road [0 cm, 0 cm
TTDebug, udpate last_instruction_end_offset to 0 cm
TTDebug, process inst type Fork, offset 291400 cm
TTDebug, max of last_instruction_end_offset 0 cm, instruction.offset 291400 cm
TTDebug, request side road [191400 cm, 291400 cm
TTDebug, udpate last_instruction_end_offset to 291400 cm

TTDebug, Generate() start, last_instruction_end_offset 291400 cm===========
TTDebug, Genreate() process line length 98656 cm, end offset 390100 cm
TTDebug, Genreate() process line length 41317 cm, end offset 431400 cm
TTDebug, Genreate() process line length 26226 cm, end offset 457600 cm
TTDebug, Genreate() process line length 2225 cm, end offset 459800 cm
TTDebug, Genreate() process line length 32491 cm, end offset 492300 cm
TTDebug, Genreate() process line length 18174 cm, end offset 510500 cm
TTDebug, Genreate() last line length 30766 cm, end offset 541300 cm
TTDebug, process inst type ExitHov, offset 685167 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 685167 cm

TTDebug, Generate() start, last_instruction_end_offset 291400 cm===========
TTDebug, Genreate() last line length 54202 cm, end offset 595500 cm
TTDebug, process inst type ExitHov, offset 685167 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 685167 cm

TTDebug, Generate() start, last_instruction_end_offset 291400 cm===========
TTDebug, Genreate() last line length 23580 cm, end offset 619100 cm
TTDebug, process inst type ExitHov, offset 685167 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 685167 cm

TTDebug, Generate() start, last_instruction_end_offset 291400 cm===========
TTDebug, Genreate() last line length 76539 cm, end offset 695600 cm
TTDebug, process inst type ExitHov, offset 685167 cm
TTDebug, not request side road
TTDebug, udpate last_instruction_end_offset to 685167 cm

TTDebug, Generate() start, last_instruction_end_offset 685167 cm===========
TTDebug, Genreate() process line length 27521 cm, end offset 723100 cm
TTDebug, Genreate() process line length 11679 cm, end offset 734800 cm
TTDebug, Genreate() process line length 82268 cm, end offset 817100 cm
TTDebug, Genreate() process line length 6846 cm, end offset 823900 cm
TTDebug, Genreate() process line length 72133 cm, end offset 896000 cm
TTDebug, Genreate() process line length 12318 cm, end offset 908300 cm
TTDebug, Genreate() process line length 48306 cm, end offset 956600 cm
TTDebug, Genreate() last line length 13556 cm, end offset 970200 cm
TTDebug, process inst type Fork, offset 970200 cm
TTDebug, max of last_instruction_end_offset 685167 cm, instruction.offset 970200 cm
TTDebug, request side road [870200 cm, 970200 cm
TTDebug, udpate last_instruction_end_offset to 970200 cm

TTDebug, Generate() start, last_instruction_end_offset 970200 cm===========
TTDebug, Genreate() process line length 29640 cm, end offset 999800 cm
TTDebug, Genreate() process line length 30072 cm, end offset 1029900 cm
TTDebug, Genreate() process line length 40765 cm, end offset 1070700 cm
TTDebug, Genreate() process line length 26618 cm, end offset 1097300 cm
TTDebug, Genreate() process line length 4769 cm, end offset 1102100 cm
TTDebug, Genreate() process line length 16750 cm, end offset 1118900 cm
TTDebug, Genreate() last line length 25730 cm, end offset 1144600 cm
TTDebug, process inst type Exit, offset 1144600 cm
TTDebug, max of last_instruction_end_offset 970200 cm, instruction.offset 1144600 cm
TTDebug, request side road [1044600 cm, 1144600 cm
TTDebug, udpate last_instruction_end_offset to 1144600 cm

TTDebug, Generate() start, last_instruction_end_offset 1144600 cm===========
TTDebug, Genreate() process line length 17262 cm, end offset 1161900 cm
TTDebug, Genreate() process line length 18102 cm, end offset 1180000 cm
TTDebug, Genreate() last line length 9894 cm, end offset 1189900 cm
TTDebug, process inst type Turn, offset 1189900 cm
TTDebug, max of last_instruction_end_offset 1144600 cm, instruction.offset 1189900 cm
TTDebug, request side road [1144600 cm, 1189900 cm
TTDebug, udpate last_instruction_end_offset to 1189900 cm

TTDebug, Generate() start, last_instruction_end_offset 1189900 cm===========
TTDebug, Genreate() last line length 5813 cm, end offset 1194200 cm
TTDebug, process inst type Arrival, offset 1194200 cm
TTDebug, max of last_instruction_end_offset 1189900 cm, instruction.offset 1194200 cm
TTDebug, request side road [1189900 cm, 1194200 cm
TTDebug, udpate last_instruction_end_offset to 1194200 cm


* hov instruction does not have maneuver view either.
* The generation of hov instruction varies from other instructions.  it is generated even it is beyond the _last_processed_line_, see also the [hov adr](https://bitbucket.tomtomgroup.com/projects/NAVKIT2/repos/nk2-navigation-instruction-engine/browse/documentation/architecture/src/adr/2021-09-13T11:50:00+0200-integration-of-hov-situation-handler.adoc)
In the figure, the further HovEnter is generated in advance. At that time, it does not know the existence of Fork, and will take side roads before the Fork and also treat the Fork as valid side road.
```
      Generated in iteration#1     Generated in iteration#0
             \                          /  
            Fork                    HovEnter
  --->  ----> * -------> -------> -----*-------->
   |      |
   |      last_processed_line in iteration#1
   |
 last_processed_line in iteration#0
```
There is no trivial solution and need further discussion if we really want side roads for hov.

