#include "QueueFactory.hpp"
#include <iostream>
#include <random>
#include <string>

using namespace std;

static void simulationTicketCounter() {
    Queue<int>* q = QueueFactory::GetQueue(10);

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> step(-1, 1);

    int arrivals = 0;
    int served = 0;
    int turnedAway = 0;
    int emptyDequeueSkips = 0;

    for (int i = 0; i < 100; i++) {
        int r = step(rng);
        if (r < 0) {
            try {
                q->dequeue();
                served++;
            } catch (const string&) {
                emptyDequeueSkips++;
            }
        } else {
            try {
                q->enqueue(0);
                arrivals++;
            } catch (const string&) {
                turnedAway++;
            }
        }
    }

    cout << "--- Small ticket counter ---\n";
    cout << "Only ten people can wait in line. I ran 100 random steps to mimic arrivals and service.\n\n";
    cout << "Customers who actually got in line: " << arrivals << "\n";
    cout << "Customers who left because the line was full: " << turnedAway << "\n";
    cout << "Customers served and sent on their way: " << served << "\n";
    cout << "Times we tried to serve but nobody was waiting: " << emptyDequeueSkips << "\n";
    cout << "People still waiting when we closed: " << q->getLength() << "\n\n";

    delete q;
}

static void simulationBankLine() {
    Queue<int>* q = QueueFactory::GetQueue();

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> step(-1, 2);

    int arrivals = 0;
    int finished = 0;
    int emptyDequeueSkips = 0;

    for (int i = 0; i < 100; i++) {
        int r = step(rng);
        if (r < 0) {
            try {
                q->dequeue();
                finished++;
            } catch (const string&) {
                emptyDequeueSkips++;
            }
        } else {
            q->enqueue(0);
            arrivals++;
        }
    }

    cout << "--- Busy bank line ---\n";
    cout << "There is no cap on the line, so it can grow as long as it needs to. Same deal: 100 random steps.\n\n";
    cout << "Customers who joined the back of the line: " << arrivals << "\n";
    cout << "Customers who finished and walked out: " << finished << "\n";
    cout << "Times we tried to finish someone but the line was empty: " << emptyDequeueSkips << "\n";
    cout << "People still in line at the end: " << q->getLength() << "\n";

    delete q;
}

int main() {
    cout << "Week 9 homework: build each queue through the factory, then run both simulations.\n\n";
    simulationTicketCounter();
    simulationBankLine();
    return 0;
}
