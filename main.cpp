#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Event {
    int id;
    std::string title;
    std::string date;
    std::string location;
    int maxCapacity;
    std::vector<std::string> rsvpList;
};

class EventManager {
private:
    std::vector<Event> events;
    int nextEventId;

public:
    EventManager() : nextEventId(1) {}

    void createEvent(const std::string& title, const std::string& date, const std::string& location, int capacity) {
        Event newEvent = {nextEventId++, title, date, location, capacity, {}};
        events.push_back(newEvent);
        std::cout << "Event '" << title << "' created successfully with ID: " << newEvent.id << "\n";
    }

    void registerAttendee(int eventId, const std::string& attendeeName) {
        for (auto& event : events) {
            if (event.id == eventId) {
                if (event.rsvpList.size() >= static_cast<size_t>(event.maxCapacity)) {
                    std::cout << "Registration failed: Event '" << event.title << "' is at full capacity.\n";
                    return;
                }
                event.rsvpList.push_back(attendeeName);
                std::cout << "RSVP successful: " << attendeeName << " registered for '" << event.title << "'.\n";
                return;
            }
        }
        std::cout << "Error: Event ID " << eventId << " not found.\n";
    }

    void displayEvents() const {
        if (events.empty()) {
            std::cout << "No upcoming events scheduled.\n";
            return;
        }

        std::cout << "\n=== Upcoming Campus Events ===\n";
        for (const auto& event : events) {
            std::cout << "ID: " << event.id << " | " << event.title << "\n";
            std::cout << "Date: " << event.date << " | Location: " << event.location << "\n";
            std::cout << "RSVPs: " << event.rsvpList.size() << "/" << event.maxCapacity << "\n";
            std::cout << "Attendees: ";
            if (event.rsvpList.empty()) {
                std::cout << "None yet";
            } else {
                for (size_t i = 0; i < event.rsvpList.size(); ++i) {
                    std::cout << event.rsvpList[i] << (i + 1 < event.rsvpList.size() ? ", " : "");
                }
            }
            std::cout << "\n----------------------------------------\n";
        }
    }
};

int main() {
    EventManager manager;

    // Create sample club events
    manager.createEvent("CS Club Hackathon", "2026-10-15", "Student Union Hall A", 3);
    manager.createEvent("Tech Networking Night", "2026-10-22", "Cyber Lab 101", 30);

    // Register attendees
    manager.registerAttendee(1, "Abel Wolde");
    manager.registerAttendee(1, "Jane Smith");
    manager.registerAttendee(1, "Alex Johnson");
    manager.registerAttendee(1, "Chris Lee"); // Should trigger capacity limit

    // Display event details
    manager.displayEvents();

    return 0;
}
