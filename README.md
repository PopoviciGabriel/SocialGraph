# Social Graph – Unique Ownership C++

A small modern C++ project that models a social network using a **clear and safe ownership design**.

## Overview
The project implements a social graph where people can form bidirectional friendships.  
All objects are managed by a central `SocialNetwork`, ensuring explicit lifetimes and no hidden ownership.

## Key Design Decisions
- **Single ownership model** using `std::unique_ptr`
- **ID-based references** for friendships (no `shared_ptr` / `weak_ptr`)
- Explicit bidirectional relationships controlled by `SocialNetwork`
- Full separation between **domain logic** and **I/O**
- Const-correct APIs that return data instead of printing

## Features
- Add and remove people
- Create friendships safely
- Automatic cleanup of relationships when a person is removed
- Query friend lists and counts

## Project Structure
SocialGraph/
├── main.cpp
├── Person.h / Person.cpp
├── SocialNetwork.h / SocialNetwork.cpp
└── Types.h

mathematica
Copiază codul

## Build & Run
Compile with a C++20-compatible compiler:
```bash
g++ -std=c++20 main.cpp Person.cpp SocialNetwork.cpp -o SocialGraph
./SocialGraph
Why this project
This project demonstrates modern C++ best practices:
explicit ownership, safe object relationships, clean architecture, and maintainable APIs.
It reflects patterns used in real-world systems such as entity graphs and centralized managers.

Author
Developed as a learning and portfolio project in modern C++.