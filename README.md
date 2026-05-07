# Moon Lander Simulation

This project uses a heap priority queue to update a set of moon landers, checking their velocity each second.



https://github.com/user-attachments/assets/f9734676-1107-475c-885f-31f70c79764b

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
