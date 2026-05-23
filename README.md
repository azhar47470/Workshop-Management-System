# Car Workshop Management System

A complete workshop management system built in C++ using structs, arrays, and file handling.

## Features
- Vehicle registration with search by license plate
- Customer management with linked vehicle records
- Mechanic management with specialization and job assignment
- Spare parts inventory with stock tracking
- Job card system with status tracking (In Progress / Completed)
- Billing and invoice generation
- File persistence — all data saves and loads automatically on every run

## Modules
1. Vehicle Module — Add, display, search vehicles
2. Customer Module — Add, display, search customers
3. Mechanic Module — Add, display mechanics
4. Spare Parts Module — Add, display, search inventory
5. Job Card Module — Add jobs, view all, search, update status
6. Billing & Invoice — Generate invoice by vehicle ID

## How to Run
1. Compile: g++ Project.cpp -o workshop
2. Run: ./workshop

## Tech Used
C++ — Structs, Nested Structs, File Handling, Functions, Arrays

## Concepts Applied
- Struct design and nested structs
- File I/O with ofstream and ifstream
- Search algorithms with bool found pattern
- Menu driven interface with do-while loop
- Data persistence across program runs
