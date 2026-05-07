# Moon Lander Simulation

This project uses a heap priority queue to update a set of moon landers, checking their velocity each second.


<img width="720" height="896" alt="2026-05-0710-27-14-ezgif com-video-to-gif-converter" src="https://github.com/user-attachments/assets/5c857b57-0e0d-4bdc-ac69-587de0e74297" />


---

## Overview

- Physics calculation to determine velocity and landing
- Implements a priority queue to keep track of front lander
- Prints out a leaderboard each second of the simulation
---

## Features

- Works for >1000 iterations of simulation
- Has custom precision up to 6 decimal points
- Hash map to easily find an index in O(1) time
---

##  Project Structure

Class PriorityQ {
  ClassPriorityType
    key, priority
  Capacity, Heap size
}
Class Lander {
  name
  Velocity, altitude
}
