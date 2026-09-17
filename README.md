Markdown
# Event Management App

An event tracking application written in C++ that enables campus organizations to create events, manage attendee RSVP lists, and enforce venue capacity limits.

## Features
- **Event Creation:** Track title, date, location, and maximum capacity.
- **RSVP Tracking:** Register attendees dynamically with automated capacity checks.
- **Relational List Management:** Monitor active attendee counts for high-volume campus events.

## Tech Stack
- **Language:** C++17
- **Compiler:** `g++` / Clang / Visual Studio MSVC

## Quickstart & Build Instructions

### Build & Run (Terminal)
```bash
# Clone repository
git clone [https://github.com/THefisrt-tech/Event-Management-App.git](https://github.com/THefisrt-tech/Event-Management-App.git)
cd Event-Management-App

# Compile
g++ -std=c++17 main.cpp -o EventManager

# Run
./EventManager
