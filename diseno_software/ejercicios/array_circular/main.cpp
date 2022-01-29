#include <iostream>
#include "msgqueue.h"
using namespace std;

void print_queue_status(string name, Msgqueue& q)
{
    cout << name;
    cout << " Empty: " << q.is_queue_empty() << " Full: " << q.is_queue_full();
    cout << " Elements: " << q.get_number_of_elements();
    cout << endl;

}

int main()
{
    const int Q1_MAX_ELEMENTS = 5;
    Msgqueue q1(Q1_MAX_ELEMENTS);

    print_queue_status("q1", q1);

    const int MSG_SENT_SIZE = 32;
    char msg_sent[MSG_SENT_SIZE];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < i+5; j++)
            msg_sent[j] = 'A' + i + j;

        cout << q1.insert_element(msg_sent, i + 5) <<" ";
        print_queue_status("q1", q1);
    }

    const int MSG_RECEIVED_SIZE = 32;
    char msg_recived[MSG_RECEIVED_SIZE];
    for(int i = 0; i < 8; i++)
    {
        int msg_recived_size = q1.extract_element(msg_recived);
        cout << msg_recived_size << " ";
        for(int j = 0; j < msg_recived_size; j++)
            cout<< msg_recived[j] << " ";
        cout << " ";

        print_queue_status("q1",q1);
    }


    return 0;
}
