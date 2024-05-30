#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a Number: ";
        cin >> num;
        cout << endl;

        //Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue Overflow\n";
        }
        //Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT == 0;
            REAR = 0;
        }
        else {
            //Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;

    }
        void remove()
        {
            //Cek apakah antrian kosong
            if (FRONT == -1) {
                cout << "Queue Underflow\n";
                return;
            }
            cout << "\nThe element deleted from queue is: " << queue_array[FRONT] << "\n";

            //Cek jika antrian hanya memiliki 1 elemen
            if (FRONT == REAR) {
                FRONT = -1;
                REAR = -1;
            }
            else {
                //jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
                if (FRONT == max - 1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
        }

        void display() {
            int FRONT_position = FRONT;
            int REAR_position = REAR;

            //Cek apakah antrian kosong
            if (FRONT == -1) {
                cout << "Queue is empty\n";
                return;
            }

            cout << "Element in the queue are....\n";

            if (FRONT_position <= REAR_position) {
                while (FRONT_position <= REAR_position) {
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }
            else {
                while (FRONT_position <= max - 1) {
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }

                FRONT_position = 0;

                //Iterasi dari awal array hingga REAR
                while (FRONT_position <= REAR_position) {
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }

        }
};
int main()
{
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choices (1-4)" << endl;
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1': {
                q.insert();
                break;
            }
            case '2': {
                q.remove();
                break;
            }
            case '3': {
                q.display();
                break;
            }
            case '4': {
                return 0; 
            }
            default: {
                cout << "Invalid Option!!" << endl;
                break;
                
            }
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered" << endl;
        }
    }

    return 0;
}