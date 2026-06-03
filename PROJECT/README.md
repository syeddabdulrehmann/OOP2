# ✈️ SkyLink Airways — Airline Reservation & Flight Management System

**Course:** Object-Oriented Programming (C++)
**Assignment:** Problem-Based Learning (PBL) — Individual
**Language:** C++17 | Single File: `airline.cpp`

---

## 📋 Table of Contents

1. [What This Program Does](#what-this-program-does)
2. [How to Run](#how-to-run)
3. [Menu Guide](#menu-guide)
4. [OOP Concepts Used](#oop-concepts-used)
5. [Class Structure](#class-structure)
6. [Sample Data](#sample-data)
7. [Test Cases](#test-cases)
8. [File Persistence](#file-persistence)

---

## What This Program Does

SkyLink Airways is a **console-based airline management system** that lets you:

- Manage **flights** (Domestic, International, Charter)
- Register and manage **passengers** (Economy, Business, First Class)
- **Book and cancel tickets** with automatic refund calculation
- View **reports** — occupancy percentages and top revenue flights
- **Save and reload** all data between program runs

---

## How to Run

### Option 1 — Dev C++ (Easiest for Students)
```
1. Open Dev C++
2. File → New → Source File
3. Paste or open airline.cpp
4. Press F11 to Compile & Run
```

### Option 2 — Visual Studio Code
```
1. Open airline.cpp in VS Code
2. Open Terminal → type:

   g++ airline.cpp -o airline
   ./airline          (Linux/Mac)
   airline.exe        (Windows)
```

### Option 3 — Online (No Installation)
```
1. Go to: https://www.onlinegdb.com
2. Select "C++" as language
3. Paste the code and press RUN
```

---

## Menu Guide

When the program starts you will see this menu:

```
==========================================
   SKYLINK AIRWAYS - MANAGEMENT SYSTEM
==========================================
  FLIGHTS
  1. List all flights
  2. Find flight by number
  3. Search by route
  4. Search by date
  5. Add new flight
  6. Remove flight
------------------------------------------
  PASSENGERS
  7.  List all passengers
  8.  Add passenger
  9.  Remove passenger
  10. Passenger booking history
------------------------------------------
  BOOKINGS
  11. Book a ticket
  12. Cancel a ticket
------------------------------------------
  REPORTS
  13. Occupancy report
  14. Top revenue flights
------------------------------------------
  0.  Save & Exit
==========================================
```

### Quick Usage Examples

**Book a ticket:**
```
Enter choice: 11
Passenger ID  : P001
Flight number : SK101
→ Booking successful! TKT1 — Seat A1 — Rs.5500
```

**Cancel a ticket:**
```
Enter choice: 12
Ticket ID to cancel: TKT1
→ Ticket cancelled. Refund: Rs.2750 (50%)
```

**Search flights by route:**
```
Enter choice: 3
Origin     : KHI
Destination: DXB
→ Shows all KHI→DXB flights
```

---

## OOP Concepts Used

| Concept | Where It Is Used | Why |
|---|---|---|
| **Abstract Class** | `Flight`, `Passenger` | Cannot create a generic flight or passenger — must use a specific type |
| **Pure Virtual Functions** | `calculateFare()`, `showDetails()`, `getClass()` etc. | Forces every child class to provide its own version |
| **Inheritance** | `DomesticFlight`, `InternationalFlight`, `CharterFlight` inherit from `Flight` | Avoids repeating common code |
| **Inheritance** | `EconomyPassenger`, `BusinessPassenger`, `FirstClassPassenger` inherit from `Passenger` | Same reason |
| **Polymorphism** | `calculateFare()` called on a `Flight*` pointer | Runs the correct version depending on flight type at runtime |
| **Polymorphism** | `getRefundPercent()` called on a `Passenger*` pointer | Economy gets 50%, Business 75%, First 90% — decided at runtime |
| **Encapsulation** | All data in `Flight`/`Passenger` is `protected` or `private` | Data is only accessible through functions |
| **Operator Overloading** | `<<` on Flight, Passenger, Ticket | Lets you print objects with `cout << flight` |
| **Operator Overloading** | `==` on Flight and Ticket | Lets you compare with `==` naturally |
| **Template Function** | `searchByID<T>()` | One function works for both `Flight*` and `Passenger*` |
| **Custom Exceptions** | `FlightFullException`, `InvalidCancelException` | Clean error handling without crashing |
| **STL Vector** | `vector<Flight*>`, `vector<Passenger*>`, `vector<Ticket>` | Dynamic list storage |
| **File I/O** | `saveToFile()`, `loadFromFile()` | Data survives after program closes |
| **Destructor** | `~Airline()` deletes all `Flight*` and `Passenger*` | Prevents memory leaks |

---

## Class Structure

```
airline.cpp
│
├── FlightFullException       ← custom exception (thrown when flight is full)
├── InvalidCancelException    ← custom exception (thrown on bad cancellation)
│
├── Flight  [ABSTRACT]
│     ├── DomesticFlight      fare = flat rate
│     ├── InternationalFlight fare = base × 1.18 (18% tax)
│     └── CharterFlight       fare = total price ÷ seats
│
├── Passenger  [ABSTRACT]
│     ├── EconomyPassenger    baggage=20kg  refund=50%
│     ├── BusinessPassenger   baggage=35kg  refund=75%
│     └── FirstClassPassenger baggage=50kg  refund=90%
│
├── Ticket                    links a Passenger to a Flight
│
├── searchByID<T>()           template function — searches any vector by ID
│
└── Airline                   main controller
      ├── addFlight / removeFlight / findFlight
      ├── addPassenger / removePassenger / findPassenger
      ├── bookTicket / cancelTicket
      ├── reportOccupancy / reportTopRevenue
      └── saveToFile / loadFromFile
```

---

## Sample Data

The program **automatically loads sample data** on first run:

### 10 Flights

| Flight | Type | Route | Date | Seats | Fare |
|---|---|---|---|---|---|
| SK101 | Domestic | KHI → LHR_PK | 2026-07-10 | 120 | Rs.5,500 |
| SK102 | Domestic | LHE → KHI | 2026-07-11 | 80 | Rs.3,200 |
| SK103 | Domestic | ISB → KHI | 2026-07-12 | 90 | Rs.3,500 |
| SK104 | Domestic | KHI → PEW | 2026-07-13 | 100 | Rs.4,000 |
| SK201 | International | KHI → DXB | 2026-07-15 | 200 | Rs.21,240 |
| SK202 | International | LHE → LON | 2026-07-16 | 180 | Rs.64,900 |
| SK203 | International | ISB → RYD | 2026-07-20 | 150 | Rs.25,960 |
| SK204 | International | KHI → NYC | 2026-07-25 | 220 | Rs.94,400 |
| SK301 | Charter | KHI → SKT | 2026-07-18 | 40 | Rs.4,000/seat |
| SK302 | Charter | LHE → MUX | 2026-07-19 | 30 | Rs.4,000/seat |

### 8 Passengers

| ID | Name | Class | Baggage | Refund |
|---|---|---|---|---|
| P001 | Ali Ahmed | Economy | 20 kg | 50% |
| P002 | Sara Khan | Economy | 20 kg | 50% |
| P003 | Umar Farooq | Economy | 20 kg | 50% |
| P004 | Ayesha Malik | Business | 35 kg | 75% |
| P005 | Bilal Saeed | Business | 35 kg | 75% |
| P006 | Hina Butt | Business | 35 kg | 75% |
| P007 | Sultan Rao | First Class | 50 kg | 90% |
| P008 | Diana Shah | First Class | 50 kg | 90% |

---

## Test Cases

These are test cases you can run to verify the system works:

| # | Test | Steps | Expected Result |
|---|---|---|---|
| 1 | List flights | Choose 1 | All 10 flights shown with fares |
| 2 | Book a ticket | Choose 11 → P001 → SK101 | Booking confirmed, TKT1 created |
| 3 | Duplicate booking | Choose 11 → P001 → SK101 again | "Already booked on this flight!" |
| 4 | Cancel ticket | Choose 12 → TKT1 | 50% refund = Rs.2,750 |
| 5 | Cancel again | Choose 12 → TKT1 | "Ticket already cancelled!" |
| 6 | Full flight | Book SK301 (40 seats) 41 times | 41st throws FlightFullException |
| 7 | Find flight | Choose 2 → SK201 | Shows international flight details |
| 8 | Search route | Choose 3 → KHI → DXB | Shows SK201 |
| 9 | Search date | Choose 4 → 2026-07-10 | Shows SK101 |
| 10 | Passenger history | Choose 10 → P001 | Shows all tickets for Ali Ahmed |
| 11 | Occupancy report | Choose 13 | Booked/Total for each flight |
| 12 | Top revenue | Choose 14 | Flights ranked by total revenue |
| 13 | Save & reload | Choose 0, restart, choose 1 | All data restored correctly |
| 14 | First class refund | Book with P007, cancel | 90% refund (higher than Economy) |
| 15 | Invalid passenger | Choose 11 → X999 → SK101 | "Passenger not found." |

---

## File Persistence

When you press **0 (Save & Exit)**, the program saves everything to `airline_data.txt` in the same folder.

Next time you run the program, it reads this file and **restores exactly where you left off** — including:
- All flights with their current seat counts
- All passengers with their loyalty points
- All tickets (active and cancelled)

If no save file is found, the program loads the 10 sample flights and 8 passengers automatically.

---

## Known Limitations

- Date comparison for "today's flights" is not implemented (requires system date)
- Fare pricing is simplified (real airlines use dynamic pricing)
- No password or login system
- Single user only — not networked

---

*SkyLink Airways System — OOP PBL Assignment*
