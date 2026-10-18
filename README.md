# Moon Lander Simulation

## Overview
A rocket simulation project that uses a bit of abstraction, but accurate numbers, to let you fly a rocker to the moon. Uses 0.005s timestep and csv input for controls. Ideally there will be a Qt framework to show visually show ships traveling as well as rotating bodies.

##  Project Outline
```
Moon-Landers/
├── include/
│   ├── body.h
│   ├── lander.h
│   └── priorityQ.h
├── src/
│   ├── body.cpp
│   ├── lander.cpp
│   ├── main.cpp
│   └── priorityQ.cpp
└── tests/
    ├── io/
    │   ├── inputs/
    │   │   ├── LanderInput.txt
    │   │   └── Sim01.txt ... Sim06.txt
    │   └── expected/
    │       ├── redirected/
    │       └── interactive/
    └── unit/
        ├── landerTest.cpp
        └── priorityQTest.cpp
```

## Features
- Timestep = 0.005s deemed accurate enough for scope
- Rockets may begin at any point on Earth/Moon/Space which all rotate
- Takes csv as an input and pivots or accelerates at desired times
---
