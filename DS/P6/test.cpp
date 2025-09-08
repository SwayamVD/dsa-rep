#include <iostream>
using namespace std;

struct Appointment {
    int startTime, endTime;
    Appointment* next;
};

class Scheduler {
private:
    Appointment* head;
public:
    Scheduler() { head = nullptr; }

    void displayFreeSlots() {
        cout << "Available slots:" << endl;
        int start = 9;
        int end = 17;
        Appointment* temp = head;
        while (temp) {
            cout << start << " - " << temp->startTime << "\n";
            start = temp->endTime;
            temp = temp->next;
        }
        if (start < end) cout << start << " - " << end << "\n";
    }

    void bookAppointment(int start, int end) {
        if (start < 9 || end > 17 || start >= end) {
            cout << "Invalid time slot!\n";
            return;
        }
        Appointment* newAppt = new Appointment{start, end, nullptr};
        if (!head || start < head->startTime) {
            newAppt->next = head;
            head = newAppt;
            return;
        }
        Appointment* temp = head;
        while (temp->next && temp->next->startTime < start) temp = temp->next;
        newAppt->next = temp->next;
        temp->next = newAppt;
    }

    void cancelAppointment(int start) {
        if (!head) {
            cout << "No appointments found!\n";
            return;
        }
        if (head->startTime == start) {
            Appointment* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Appointment* temp = head;
        while (temp->next && temp->next->startTime != start) temp = temp->next;
        if (!temp->next) {
            cout << "Appointment not found!\n";
            return;
        }
        Appointment* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void sortAppointments() {
        if (!head || !head->next) return;
        Appointment* sorted = nullptr;
        while (head) {
            Appointment* current = head;
            head = head->next;
            if (!sorted || current->startTime < sorted->startTime) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next && temp->next->startTime < current->startTime)
                    temp = temp->next;
                current->next = temp->next;
                temp->next = current;
            }
        }
        head = sorted;
    }

    void displayAppointments() {
        if (!head) {
            cout << "No booked appointments.\n";
            return;
        }
        cout << "Booked appointments:" << endl;
        Appointment* temp = head;
        while (temp) {
            cout << temp->startTime << " - " << temp->endTime << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    Scheduler scheduler;
    int choice, start, end;
    do {
        cout << "\n1. Display Free Slots\n2. Book Appointment\n3. Cancel Appointment\n4. Sort Appointments\n5. Display Appointments\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                scheduler.displayFreeSlots();
                break;
            case 2:
                cout << "Enter start and end time: ";
                cin >> start >> end;
                scheduler.bookAppointment(start, end);
                break;
            case 3:
                cout << "Enter start time to cancel: ";
                cin >> start;
                scheduler.cancelAppointment(start);
                break;
            case 4:
                scheduler.sortAppointments();
                cout << "Appointments sorted.\n";
                break;
            case 5:
                scheduler.displayAppointments();
                break;
        }
    } while (choice != 6);
    return 0;
}
