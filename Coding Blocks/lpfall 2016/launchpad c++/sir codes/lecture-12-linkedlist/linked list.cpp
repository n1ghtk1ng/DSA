#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int d):data(d),next(NULL){}

    ~Node(){

        if(next!=NULL){
            delete next;
            next = NULL;
        }
        //cout<<"Deleting Node with data "<<data<<endl;
    }
};

class LinkedList{
public:
    Node*head;
    Node*tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtFront(int d){
        if(head==NULL){
            head = tail = new Node(d);
        }
        else{
            Node *n = new Node(d);
            n->next = head;
            head = n;
        }
    }

       void print(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data <<"-->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
       }
       int getSize(){
            int count=0;
            Node*temp = head;
            while(temp!=NULL){
                count++;
                temp = temp->next;
            }
            return count;
       }
       void insertInMiddle(int d,int p){
            if(p==0){
                insertAtFront(d);
            }
            else if(p>=getSize()){
                insertAtEnd(d);
            }
            else{
                int count=0;
                Node*temp = head;
                while(count<p-1){
                    temp = temp->next;
                    count++;
                }
                Node* n = new Node(d);
                n->next = temp->next;
                temp->next = n;
            }

       }
       int findElement(int key){
            Node*temp = head;
            int position = 0;

            while(temp!=NULL){
                if(temp->data==key){
                    return position;
                }
                position++;
                temp = temp->next;
            }
            return -1;
       }


    void insertAtEnd(int d){
        if(tail==NULL){
            head = tail = new Node(d);
        }
        else{
            Node *n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }
    static Node* findElementHelper(int key,Node*start){
        if(start==NULL){
            return NULL;
        }
        if(start->data==key){
                return start;
        }
        return findElementHelper(key,start->next);
    }
    Node*findMid(){
        Node*slow = head;
        Node*fast = head->next;
            /*
            while(fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;
            }*/

            while(fast!=NULL){
                    fast = fast->next;
                    if(fast!=NULL){
                        fast = fast->next;
                        slow = slow->next;
                    }
            }
            return slow;
    }

    Node* findElementRec(int data){
            return findElementHelper(data,head);
    }
    void deleteNode(int p){
        if(p==0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            //Delete from the middle
            int count=0;
            Node*temp = head;
            while(count<p-1){
                temp = temp->next;
                count++;
            }
            Node* n = temp->next;
            temp->next = n->next;
            n->next = NULL;
            delete n;

            if(p==getSize()){
                tail = temp;
            }
        }



    }
    ~LinkedList(){
            if(head!=NULL){
                delete head;
                head = NULL;
            }
    }

};

Node* Merge(Node*a,Node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node* newHead;
    if(a->data < b->data){
       newHead = a;
       newHead->next = Merge(a->next,b);
    }
    else{
        newHead = b;
        newHead->next = Merge(a,b->next);
    }
    return newHead;
}

int main(){
    LinkedList l;
    l.insertAtFront(1);
    l.insertAtFront(2);
    l.insertAtFront(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertInMiddle(11,2);
    l.insertInMiddle(0,0);
    l.insertInMiddle(11,20);
    l.print();
    int ans = l.findElement(100);
    if(ans==-1){
        cout<<"Not found "<<endl;
    }
    else{
        cout<<"Found at Position "<< ans <<endl;
    }
    l.deleteNode(4);
    l.print();

    Node *n = l.findElementRec(6);
    cout<<n <<" and data is "<< n->data <<endl;
    cout<< l.findMid()->data<<endl;

    LinkedList l1,l2;
    l1.insertAtEnd(1);
    l1.insertAtEnd(4);
    l1.insertAtEnd(6);
    l2.insertAtEnd(2);
    l2.insertAtEnd(3);
    l2.insertAtEnd(5);

    l1.head = Merge(l1.head,l2.head);
    l1.print();

    return 0;
}
