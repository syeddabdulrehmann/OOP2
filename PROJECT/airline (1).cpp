#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// ============================================================
//  CUSTOM EXCEPTIONS
// ============================================================
class FlightFullException {
public:
    string message;
    FlightFullException(string msg) { message = msg; }
};

class InvalidCancelException {
public:
    string message;
    InvalidCancelException(string msg) { message = msg; }
};

// ============================================================
//  ABSTRACT BASE CLASS: Flight
// ============================================================
class Flight {
protected:
    string flightNumber;
    string origin;
    string destination;
    string departureDate;   // format: YYYY-MM-DD
    int    totalSeats;
    int    availableSeats;

public:
    // Constructor
    Flight(string fn, string orig, string dest, string date, int seats) {
        flightNumber   = fn;
        origin         = orig;
        destination    = dest;
        departureDate  = date;
        totalSeats     = seats;
        availableSeats = seats;
    }

    virtual ~Flight() {}   // virtual destructor

    // Pure virtual functions (must be overridden in child classes)
    virtual double calculateFare()    = 0;
    virtual void   showDetails()      = 0;
    virtual string getType()          = 0;

    // Getters
    string getFlightNumber()  { return flightNumber; }
    string getOrigin()        { return origin; }
    string getDestination()   { return destination; }
    string getDepartureDate() { return departureDate; }
    int    getTotalSeats()    { return totalSeats; }
    int    getAvailableSeats(){ return availableSeats; }

    // Book or release a seat
    bool bookSeat() {
        if (availableSeats <= 0) return false;
        availableSeats--;
        return true;
    }
    void releaseSeat() {
        if (availableSeats < totalSeats) availableSeats++;
    }

    // Occupancy percentage
    double occupancyPercent() {
        return ((totalSeats - availableSeats) * 100.0) / totalSeats;
    }

    // Operator overload: print flight with <<
    friend ostream& operator<<(ostream& os, Flight& f) {
        os << "[" << f.getType() << "] "
           << f.flightNumber << "  "
           << f.origin << " -> " << f.destination
           << "  Date: " << f.departureDate
           << "  Seats left: " << f.availableSeats << "/" << f.totalSeats
           << "  Fare: Rs." << fixed << setprecision(0) << f.calculateFare();
        return os;
    }

    // Operator overload: compare two flights by flight number
    bool operator==(Flight& other) {
        return flightNumber == other.flightNumber;
    }
};

// ============================================================
//  CHILD CLASS 1: DomesticFlight
// ============================================================
class DomesticFlight : public Flight {
private:
    double baseFare;

public:
    DomesticFlight(string fn, string orig, string dest,
                   string date, int seats, double fare)
        : Flight(fn, orig, dest, date, seats) {
        baseFare = fare;
    }

    // Override pure virtual functions
    double calculateFare() {
        return baseFare;   // simple flat fare
    }

    void showDetails() {
        cout << "\n--- DOMESTIC FLIGHT ---\n";
        cout << "  Number  : " << flightNumber  << "\n";
        cout << "  Route   : " << origin << " -> " << destination << "\n";
        cout << "  Date    : " << departureDate  << "\n";
        cout << "  Seats   : " << availableSeats << " / " << totalSeats << "\n";
        cout << "  Fare    : Rs." << baseFare     << "\n";
    }

    string getType() { return "DOMESTIC"; }
};

// ============================================================
//  CHILD CLASS 2: InternationalFlight
// ============================================================
class InternationalFlight : public Flight {
private:
    double baseFare;
    bool   visaRequired;
    string country;

public:
    InternationalFlight(string fn, string orig, string dest,
                        string date, int seats,
                        double fare, bool visa, string cntry)
        : Flight(fn, orig, dest, date, seats) {
        baseFare     = fare;
        visaRequired = visa;
        country      = cntry;
    }

    double calculateFare() {
        // International adds 18% tax
        return baseFare * 1.18;
    }

    void showDetails() {
        cout << "\n--- INTERNATIONAL FLIGHT ---\n";
        cout << "  Number  : " << flightNumber   << "\n";
        cout << "  Route   : " << origin << " -> " << destination << "\n";
        cout << "  Country : " << country         << "\n";
        cout << "  Date    : " << departureDate   << "\n";
        cout << "  Seats   : " << availableSeats  << " / " << totalSeats << "\n";
        cout << "  Visa    : " << (visaRequired ? "Required" : "Not Required") << "\n";
        cout << "  Fare    : Rs." << fixed << setprecision(0) << calculateFare() << "\n";
    }

    string getType() { return "INTERNATIONAL"; }
};

// ============================================================
//  CHILD CLASS 3: CharterFlight
// ============================================================
class CharterFlight : public Flight {
private:
    double totalCharterPrice;
    string companyName;

public:
    CharterFlight(string fn, string orig, string dest,
                  string date, int seats,
                  double price, string company)
        : Flight(fn, orig, dest, date, seats) {
        totalCharterPrice = price;
        companyName       = company;
    }

    double calculateFare() {
        // Price divided equally among all seats
        return totalCharterPrice / totalSeats;
    }

    void showDetails() {
        cout << "\n--- CHARTER FLIGHT ---\n";
        cout << "  Number  : " << flightNumber   << "\n";
        cout << "  Route   : " << origin << " -> " << destination << "\n";
        cout << "  Company : " << companyName     << "\n";
        cout << "  Date    : " << departureDate   << "\n";
        cout << "  Seats   : " << availableSeats  << " / " << totalSeats << "\n";
        cout << "  Fare    : Rs." << fixed << setprecision(0) << calculateFare() << "\n";
    }

    string getType() { return "CHARTER"; }
};

// ============================================================
//  ABSTRACT BASE CLASS: Passenger
// ============================================================
class Passenger {
protected:
    string passengerID;
    string name;
    string phone;
    int    loyaltyPoints;

public:
    Passenger(string id, string nm, string ph) {
        passengerID   = id;
        name          = nm;
        phone         = ph;
        loyaltyPoints = 0;
    }

    virtual ~Passenger() {}

    // Pure virtual functions
    virtual double getBaggage()         = 0;   // kg allowed
    virtual double getRefundPercent()   = 0;   // % refund on cancel
    virtual string getClass()           = 0;

    // Getters
    string getID()    { return passengerID; }
    string getName()  { return name; }
    string getPhone() { return phone; }
    int    getPoints(){ return loyaltyPoints; }

    void addPoints(int pts) { loyaltyPoints += pts; }

    // Operator overload: print passenger with <<
    friend ostream& operator<<(ostream& os, Passenger& p) {
        os << "[" << p.getClass() << "] "
           << p.passengerID << "  " << p.name
           << "  Phone: " << p.phone
           << "  Points: " << p.loyaltyPoints
           << "  Baggage: " << p.getBaggage() << " kg";
        return os;
    }
};

// ============================================================
//  CHILD CLASS: EconomyPassenger
// ============================================================
class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string id, string nm, string ph)
        : Passenger(id, nm, ph) {}

    double getBaggage()       { return 20; }   // 20 kg
    double getRefundPercent() { return 50; }   // 50% refund
    string getClass()         { return "ECONOMY"; }
};

// ============================================================
//  CHILD CLASS: BusinessPassenger
// ============================================================
class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string id, string nm, string ph)
        : Passenger(id, nm, ph) {}

    double getBaggage()       { return 35; }   // 35 kg
    double getRefundPercent() { return 75; }   // 75% refund
    string getClass()         { return "BUSINESS"; }
};

// ============================================================
//  CHILD CLASS: FirstClassPassenger
// ============================================================
class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string id, string nm, string ph)
        : Passenger(id, nm, ph) {}

    double getBaggage()       { return 50; }   // 50 kg
    double getRefundPercent() { return 90; }   // 90% refund
    string getClass()         { return "FIRST"; }
};

// ============================================================
//  TICKET CLASS
// ============================================================
class Ticket {
public:
    string ticketID;
    string passengerID;
    string flightNumber;
    string seatNumber;
    double farePaid;
    bool   active;   // false = cancelled

    // Default constructor (needed for vector)
    Ticket() {
        farePaid = 0;
        active   = false;
    }

    Ticket(string tid, string pid, string fn, string seat, double fare) {
        ticketID      = tid;
        passengerID   = pid;
        flightNumber  = fn;
        seatNumber    = seat;
        farePaid      = fare;
        active        = true;
    }

    // Operator overload: compare tickets
    bool operator==(Ticket& other) {
        return ticketID == other.ticketID;
    }

    // Operator overload: print ticket
    friend ostream& operator<<(ostream& os, Ticket& t) {
        os << "Ticket[" << t.ticketID << "]"
           << "  Passenger: " << t.passengerID
           << "  Flight: "    << t.flightNumber
           << "  Seat: "      << t.seatNumber
           << "  Fare: Rs."   << fixed << setprecision(0) << t.farePaid
           << "  Status: "    << (t.active ? "ACTIVE" : "CANCELLED");
        return os;
    }
};

// ============================================================
//  TEMPLATE SEARCH FUNCTION
//  Works for both Flight* and Passenger* vectors
// ============================================================
template <typename T>
T* searchByID(vector<T*>& list, string id) {
    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i]->getID() == id) {
            return list[i];
        }
    }
    return NULL;  // not found
}

// ============================================================
//  AIRLINE CLASS  (main controller)
// ============================================================
class Airline {
private:
    string            airlineName;
    vector<Flight*>   flights;
    vector<Passenger*>passengers;
    vector<Ticket>    tickets;
    int               nextTicketNum;
    int               nextSeatNum;

    // Generate a seat like A1, A2, B1 ...
    string makeSeat() {
        char row = 'A' + ((nextSeatNum - 1) / 6);
        int  col = ((nextSeatNum - 1) % 6) + 1;
        nextSeatNum++;
        return string(1, row) + string(col);
    }

public:
    Airline(string name) {
        airlineName   = name;
        nextTicketNum = 1;
        nextSeatNum   = 1;
    }

    // Destructor: free memory
    ~Airline() {
        for (int i = 0; i < (int)flights.size();    i++) delete flights[i];
        for (int i = 0; i < (int)passengers.size(); i++) delete passengers[i];
    }

    // ── FLIGHT MANAGEMENT ──────────────────────────────────

    void addFlight(Flight* f) {
        flights.push_back(f);
        cout << "  Flight " << f->getFlightNumber() << " added.\n";
    }

    void removeFlight(string fn) {
        for (int i = 0; i < (int)flights.size(); i++) {
            if (flights[i]->getFlightNumber() == fn) {
                delete flights[i];
                flights.erase(flights.begin() + i);
                cout << "  Flight removed.\n";
                return;
            }
        }
        cout << "  Flight not found.\n";
    }

    Flight* findFlight(string fn) {
        for (int i = 0; i < (int)flights.size(); i++) {
            if (flights[i]->getFlightNumber() == fn)
                return flights[i];
        }
        return NULL;
    }

    void listFlights() {
        if (flights.empty()) { cout << "  No flights.\n"; return; }
        for (int i = 0; i < (int)flights.size(); i++) {
            cout << "  " << *flights[i] << "\n";
        }
    }

    void searchByRoute(string orig, string dest) {
        bool found = false;
        for (int i = 0; i < (int)flights.size(); i++) {
            if (flights[i]->getOrigin() == orig &&
                flights[i]->getDestination() == dest) {
                cout << "  " << *flights[i] << "\n";
                found = true;
            }
        }
        if (!found) cout << "  No flights found for this route.\n";
    }

    void searchByDate(string date) {
        bool found = false;
        for (int i = 0; i < (int)flights.size(); i++) {
            if (flights[i]->getDepartureDate() == date) {
                cout << "  " << *flights[i] << "\n";
                found = true;
            }
        }
        if (!found) cout << "  No flights on this date.\n";
    }

    // ── PASSENGER MANAGEMENT ───────────────────────────────

    void addPassenger(Passenger* p) {
        passengers.push_back(p);
        cout << "  Passenger " << p->getID() << " registered.\n";
    }

    void removePassenger(string pid) {
        for (int i = 0; i < (int)passengers.size(); i++) {
            if (passengers[i]->getID() == pid) {
                delete passengers[i];
                passengers.erase(passengers.begin() + i);
                cout << "  Passenger removed.\n";
                return;
            }
        }
        cout << "  Passenger not found.\n";
    }

    Passenger* findPassenger(string pid) {
        // Using our template function
        return searchByID(passengers, pid);
    }

    void listPassengers() {
        if (passengers.empty()) { cout << "  No passengers.\n"; return; }
        for (int i = 0; i < (int)passengers.size(); i++) {
            cout << "  " << *passengers[i] << "\n";
        }
    }

    void passengerHistory(string pid) {
        Passenger* p = findPassenger(pid);
        if (!p) { cout << "  Passenger not found.\n"; return; }

        cout << "  Bookings for " << p->getName() << ":\n";
        bool any = false;
        for (int i = 0; i < (int)tickets.size(); i++) {
            if (tickets[i].passengerID == pid) {
                cout << "    " << tickets[i] << "\n";
                any = true;
            }
        }
        if (!any) cout << "    No bookings.\n";
    }

    // ── BOOKING ────────────────────────────────────────────

    void bookTicket(string pid, string fn) {
        try {
            Passenger* p = findPassenger(pid);
            if (!p) { cout << "  Passenger not found.\n"; return; }

            Flight* f = findFlight(fn);
            if (!f) { cout << "  Flight not found.\n"; return; }

            // Check if flight is full
            if (f->getAvailableSeats() == 0)
                throw FlightFullException("Flight " + fn + " is fully booked!");

            // Check duplicate booking
            for (int i = 0; i < (int)tickets.size(); i++) {
                if (tickets[i].passengerID == pid &&
                    tickets[i].flightNumber == fn  &&
                    tickets[i].active) {
                    cout << "  Already booked on this flight!\n";
                    return;
                }
            }

            // Create ticket
            f->bookSeat();
            double fare = f->calculateFare();
            string seat = makeSeat();
            string tid  = "TKT" + to_string(nextTicketNum++);

            Ticket t(tid, pid, fn, seat, fare);
            tickets.push_back(t);

            // Give loyalty points
            int pts = (int)(fare / 100);
            p->addPoints(pts);

            cout << "\n  Booking successful!\n";
            cout << "  " << t << "\n";
            cout << "  Loyalty points earned: " << pts << "\n";

        } catch (FlightFullException& e) {
            cout << "  ERROR: " << e.message << "\n";
        }
    }

    // ── CANCELLATION ───────────────────────────────────────

    void cancelTicket(string tid) {
        try {
            for (int i = 0; i < (int)tickets.size(); i++) {
                if (tickets[i].ticketID == tid) {

                    if (!tickets[i].active)
                        throw InvalidCancelException("Ticket already cancelled!");

                    Flight*    f = findFlight(tickets[i].flightNumber);
                    Passenger* p = findPassenger(tickets[i].passengerID);

                    double refundPct = p ? p->getRefundPercent() : 0;
                    double refund    = tickets[i].farePaid * (refundPct / 100.0);

                    tickets[i].active = false;
                    if (f) f->releaseSeat();

                    cout << "  Ticket cancelled.\n";
                    cout << "  Refund: Rs." << fixed << setprecision(0)
                         << refund << "  (" << refundPct << "%)\n";
                    return;
                }
            }
            cout << "  Ticket not found.\n";

        } catch (InvalidCancelException& e) {
            cout << "  ERROR: " << e.message << "\n";
        }
    }

    // ── REPORTS ────────────────────────────────────────────

    void reportOccupancy() {
        cout << "\n=== FLIGHT OCCUPANCY ===\n";
        if (flights.empty()) { cout << "  No flights.\n"; return; }
        for (int i = 0; i < (int)flights.size(); i++) {
            cout << "  " << left << setw(8) << flights[i]->getFlightNumber()
                 << "  " << flights[i]->getOrigin()
                 << " -> " << flights[i]->getDestination()
                 << "  Booked: "
                 << (flights[i]->getTotalSeats() - flights[i]->getAvailableSeats())
                 << "/" << flights[i]->getTotalSeats()
                 << "  (" << fixed << setprecision(1)
                 << flights[i]->occupancyPercent() << "%)\n";
        }
    }

    void reportTopRevenue() {
        cout << "\n=== TOP REVENUE FLIGHTS ===\n";
        // Calculate revenue per flight
        vector<string> flightNums;
        vector<double> revenues;

        for (int i = 0; i < (int)tickets.size(); i++) {
            if (!tickets[i].active) continue;
            string fn = tickets[i].flightNumber;
            bool exists = false;
            for (int j = 0; j < (int)flightNums.size(); j++) {
                if (flightNums[j] == fn) {
                    revenues[j] += tickets[i].farePaid;
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                flightNums.push_back(fn);
                revenues.push_back(tickets[i].farePaid);
            }
        }

        if (flightNums.empty()) { cout << "  No revenue data.\n"; return; }

        // Bubble sort by revenue (descending)
        for (int i = 0; i < (int)revenues.size() - 1; i++) {
            for (int j = 0; j < (int)revenues.size() - i - 1; j++) {
                if (revenues[j] < revenues[j+1]) {
                    swap(revenues[j],   revenues[j+1]);
                    swap(flightNums[j], flightNums[j+1]);
                }
            }
        }

        int limit = (int)flightNums.size() < 5 ? (int)flightNums.size() : 5;
        for (int i = 0; i < (int)limit; i++) {
            cout << "  #" << (i+1) << "  " << left << setw(8) << flightNums[i]
                 << "  Rs." << fixed << setprecision(0) << revenues[i] << "\n";
        }
    }

    // ── FILE PERSISTENCE ───────────────────────────────────

    void saveToFile() {
        ofstream f("airline_data.txt");
        if (!f) { cout << "  Cannot save file!\n"; return; }

        // Save flights
        f << flights.size() << "\n";
        for (int i = 0; i < (int)flights.size(); i++) {
            Flight* fl = flights[i];
            f << fl->getType()           << "\n"
              << fl->getFlightNumber()   << "\n"
              << fl->getOrigin()         << "\n"
              << fl->getDestination()    << "\n"
              << fl->getDepartureDate()  << "\n"
              << fl->getTotalSeats()     << "\n"
              << fl->getAvailableSeats() << "\n"
              << fl->calculateFare()     << "\n";
        }

        // Save passengers
        f << passengers.size() << "\n";
        for (int i = 0; i < (int)passengers.size(); i++) {
            Passenger* p = passengers[i];
            f << p->getClass()  << "\n"
              << p->getID()     << "\n"
              << p->getName()   << "\n"
              << p->getPhone()  << "\n"
              << p->getPoints() << "\n";
        }

        // Save tickets
        f << tickets.size() << "\n";
        for (int i = 0; i < (int)tickets.size(); i++) {
            f << tickets[i].ticketID     << "\n"
              << tickets[i].passengerID  << "\n"
              << tickets[i].flightNumber << "\n"
              << tickets[i].seatNumber   << "\n"
              << tickets[i].farePaid     << "\n"
              << tickets[i].active       << "\n";
        }

        f << nextTicketNum << "\n";
        f << nextSeatNum   << "\n";
        f.close();
        cout << "  Data saved to airline_data.txt\n";
    }

    void loadFromFile() {
        ifstream f("airline_data.txt");
        if (!f) {
            cout << "  No saved data found. Loading sample data...\n";
            loadSampleData();
            return;
        }

        int count;

        // Load flights
        f >> count; f.ignore();
        for (int i = 0; i < (int)count; i++) {
            string type, fn, orig, dest, date;
            int    total, avail;
            double fare;
            getline(f, type);
            getline(f, fn);
            getline(f, orig);
            getline(f, dest);
            getline(f, date);
            f >> total >> avail >> fare; f.ignore();

            Flight* fl = NULL;
            if (type == "DOMESTIC")
                fl = new DomesticFlight(fn, orig, dest, date, total, fare);
            else if (type == "INTERNATIONAL")
                fl = new InternationalFlight(fn, orig, dest, date, total,
                                             fare / 1.18, false, "");
            else if (type == "CHARTER")
                fl = new CharterFlight(fn, orig, dest, date, total,
                                       fare * total, "Company");
            if (fl) {
                // Restore booked seats
                for (int s = 0; s < (total - avail); s++) fl->bookSeat();
                flights.push_back(fl);
            }
        }

        // Load passengers
        f >> count; f.ignore();
        for (int i = 0; i < (int)count; i++) {
            string cls, id, nm, ph;
            int pts;
            getline(f, cls);
            getline(f, id);
            getline(f, nm);
            getline(f, ph);
            f >> pts; f.ignore();

            Passenger* p = NULL;
            if      (cls == "ECONOMY")  p = new EconomyPassenger(id, nm, ph);
            else if (cls == "BUSINESS") p = new BusinessPassenger(id, nm, ph);
            else if (cls == "FIRST")    p = new FirstClassPassenger(id, nm, ph);
            if (p) { p->addPoints(pts); passengers.push_back(p); }
        }

        // Load tickets
        f >> count; f.ignore();
        for (int i = 0; i < (int)count; i++) {
            Ticket t;
            getline(f, t.ticketID);
            getline(f, t.passengerID);
            getline(f, t.flightNumber);
            getline(f, t.seatNumber);
            f >> t.farePaid >> t.active; f.ignore();
            tickets.push_back(t);
        }

        f >> nextTicketNum >> nextSeatNum;
        f.close();

        cout << "  Loaded " << flights.size()    << " flights, "
             << passengers.size() << " passengers, "
             << tickets.size()    << " tickets.\n";
    }

    // ── SAMPLE DATA ────────────────────────────────────────

    void loadSampleData() {
        // 10 flights
        addFlight(new DomesticFlight    ("SK101","KHI","LHR_PK","2026-07-10",120,5500));
        addFlight(new DomesticFlight    ("SK102","LHE","KHI",   "2026-07-11", 80,3200));
        addFlight(new DomesticFlight    ("SK103","ISB","KHI",   "2026-07-12", 90,3500));
        addFlight(new DomesticFlight    ("SK104","KHI","PEW",   "2026-07-13",100,4000));
        addFlight(new InternationalFlight("SK201","KHI","DXB",  "2026-07-15",200,18000,true, "UAE"));
        addFlight(new InternationalFlight("SK202","LHE","LON",  "2026-07-16",180,55000,true, "UK"));
        addFlight(new InternationalFlight("SK203","ISB","RYD",  "2026-07-20",150,22000,true, "KSA"));
        addFlight(new InternationalFlight("SK204","KHI","NYC",  "2026-07-25",220,80000,true, "USA"));
        addFlight(new CharterFlight      ("SK301","KHI","SKT",  "2026-07-18", 40,160000,"PIA Corp"));
        addFlight(new CharterFlight      ("SK302","LHE","MUX",  "2026-07-19", 30,120000,"AirGulf"));

        // 8 passengers (3 Economy, 3 Business, 2 First)
        addPassenger(new EconomyPassenger  ("P001","Ali Ahmed",    "0300-1111111"));
        addPassenger(new EconomyPassenger  ("P002","Sara Khan",    "0300-2222222"));
        addPassenger(new EconomyPassenger  ("P003","Umar Farooq",  "0300-3333333"));
        addPassenger(new BusinessPassenger ("P004","Ayesha Malik", "0301-4444444"));
        addPassenger(new BusinessPassenger ("P005","Bilal Saeed",  "0301-5555555"));
        addPassenger(new BusinessPassenger ("P006","Hina Butt",    "0301-6666666"));
        addPassenger(new FirstClassPassenger("P007","Sultan Rao",  "0321-7777777"));
        addPassenger(new FirstClassPassenger("P008","Diana Shah",  "0321-8888888"));

        cout << "  Sample data ready: 10 flights, 8 passengers.\n";
    }
};

// ============================================================
//  HELPER: read a line after cin >>
// ============================================================
string readLine(string prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int readInt(string prompt) {
    cout << prompt;
    int n;
    cin >> n;
    cin.ignore();
    return n;
}

// ============================================================
//  MENU
// ============================================================
void showMenu() {
    cout << "\n";
    cout << "==========================================\n";
    cout << "   SKYLINK AIRWAYS - MANAGEMENT SYSTEM   \n";
    cout << "==========================================\n";
    cout << "  FLIGHTS\n";
    cout << "  1. List all flights\n";
    cout << "  2. Find flight by number\n";
    cout << "  3. Search by route\n";
    cout << "  4. Search by date\n";
    cout << "  5. Add new flight\n";
    cout << "  6. Remove flight\n";
    cout << "------------------------------------------\n";
    cout << "  PASSENGERS\n";
    cout << "  7.  List all passengers\n";
    cout << "  8.  Add passenger\n";
    cout << "  9.  Remove passenger\n";
    cout << "  10. Passenger booking history\n";
    cout << "------------------------------------------\n";
    cout << "  BOOKINGS\n";
    cout << "  11. Book a ticket\n";
    cout << "  12. Cancel a ticket\n";
    cout << "------------------------------------------\n";
    cout << "  REPORTS\n";
    cout << "  13. Occupancy report\n";
    cout << "  14. Top revenue flights\n";
    cout << "------------------------------------------\n";
    cout << "  0.  Save & Exit\n";
    cout << "==========================================\n";
    cout << "  Enter choice: ";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    Airline airline("SkyLink Airways");

    cout << "\n  Welcome to SkyLink Airways System\n";
    cout << "  Loading data...\n";
    airline.loadFromFile();

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n=== ALL FLIGHTS ===\n";
            airline.listFlights();

        } else if (choice == 2) {
            string fn = readLine("  Enter flight number: ");
            Flight* f = airline.findFlight(fn);
            if (f) f->showDetails();
            else   cout << "  Flight not found.\n";

        } else if (choice == 3) {
            string o = readLine("  Origin     : ");
            string d = readLine("  Destination: ");
            cout << "\n=== SEARCH RESULTS ===\n";
            airline.searchByRoute(o, d);

        } else if (choice == 4) {
            string dt = readLine("  Date (YYYY-MM-DD): ");
            cout << "\n=== SEARCH RESULTS ===\n";
            airline.searchByDate(dt);

        } else if (choice == 5) {
            cout << "  Type: 1=Domestic  2=International  3=Charter\n";
            int t = readInt("  Choice: ");
            string fn   = readLine("  Flight number : ");
            string orig = readLine("  Origin        : ");
            string dest = readLine("  Destination   : ");
            string date = readLine("  Date (YYYY-MM-DD): ");
            int    seats= readInt ("  Total seats   : ");

            if (t == 1) {
                double fare = readInt("  Base fare (Rs): ");
                airline.addFlight(new DomesticFlight(fn,orig,dest,date,seats,fare));
            } else if (t == 2) {
                double fare = readInt("  Base fare before tax (Rs): ");
                string cc   = readLine("  Country code  : ");
                int    visa = readInt ("  Visa required? (1=Yes 0=No): ");
                airline.addFlight(new InternationalFlight(fn,orig,dest,date,seats,fare,visa,cc));
            } else {
                double price   = readInt ("  Total charter price (Rs): ");
                string company = readLine("  Company name  : ");
                airline.addFlight(new CharterFlight(fn,orig,dest,date,seats,price,company));
            }

        } else if (choice == 6) {
            string fn = readLine("  Flight number to remove: ");
            airline.removeFlight(fn);

        } else if (choice == 7) {
            cout << "\n=== ALL PASSENGERS ===\n";
            airline.listPassengers();

        } else if (choice == 8) {
            cout << "  Class: 1=Economy  2=Business  3=First\n";
            int    t  = readInt ("  Choice   : ");
            string id = readLine("  ID       : ");
            string nm = readLine("  Name     : ");
            string ph = readLine("  Phone    : ");
            if      (t == 1) airline.addPassenger(new EconomyPassenger(id,nm,ph));
            else if (t == 2) airline.addPassenger(new BusinessPassenger(id,nm,ph));
            else             airline.addPassenger(new FirstClassPassenger(id,nm,ph));

        } else if (choice == 9) {
            string pid = readLine("  Passenger ID to remove: ");
            airline.removePassenger(pid);

        } else if (choice == 10) {
            string pid = readLine("  Passenger ID: ");
            airline.passengerHistory(pid);

        } else if (choice == 11) {
            string pid = readLine("  Passenger ID  : ");
            string fn  = readLine("  Flight number : ");
            airline.bookTicket(pid, fn);

        } else if (choice == 12) {
            string tid = readLine("  Ticket ID to cancel: ");
            airline.cancelTicket(tid);

        } else if (choice == 13) {
            airline.reportOccupancy();

        } else if (choice == 14) {
            airline.reportTopRevenue();

        } else if (choice == 0) {
            airline.saveToFile();
            cout << "  Goodbye!\n\n";

        } else {
            cout << "  Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
