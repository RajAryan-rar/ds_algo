#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Node{
public :
    int val;
    Node* next;
    Node(int val) {;
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* temp) {
    while(temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int f(int n) {
        int r = 0;
        while(n > 0) {
            int ld = n%10;
            r *= 10;
            r += ld;
            n /= 10;
        }
        
        return r;
    }
    bool isSameAfterReversals(int num) {
        int a = f(num);
        cout<<a<<endl;
        int b = f(a);
        cout<<b<<endl;
        return (a == b) ? true : false;
    }

int main() {
    // Node* a = new Node(5);
    // Node* b = new Node(4);
    // Node* c = new Node(3);
    // Node* d = new Node(2);
    // Node* e = new Node(1);

    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;

    // display(a);

    // isSameAfterReversals(526);

    // long long ans = 0;
    // int x =  -125;
    // while (x != 0) {
    //     ans = ans * 10 + x % 10;
    //     if (ans > INT_MAX || ans < INT_MIN)
    //         return 0;
    //     x /= 10;
    //     cout<<"x: "<<x<<", ans: "<<ans<<endl;
    // }

    // cout<<ans;

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<vector<int>> res;
    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=i; j<n; j++) {
            v.push_back(arr[j]);
            res.push_back(v);
        }
    }

    for(int i=0; i<res.size(); i++) {
        for(auto ele : res[i]) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }


    return 0;
}