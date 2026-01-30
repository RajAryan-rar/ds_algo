#include<iostream>
#include<queue>
using namespace std;

void display(deque<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

void displayRev(deque<int> q) {
    while(!q.empty()) {
        cout<<q.back()<<" ";
        q.pop_back();
    }
    cout<<endl;
}

int main() {
    deque<int> q;

    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.push_back(50);

    q.push_front(100);

    display(q);

    displayRev(q);



    return 0;
}