class Node{
    public:
    int value;
    int key;
    Node* prev;
    Node* next;

    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->prev=NULL;
        this->next=NULL;
    }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    int cap;
    int curCap;
    unordered_map<int,Node*> mpp;

    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;

        curCap=0;
        cap=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        else{
            Node* requiredNode=mpp[key];

            Node* prevNode=requiredNode->prev;
            Node* nextNode=requiredNode->next;

            prevNode->next=nextNode;
            nextNode->prev=prevNode;

            Node* nextToHead=head->next;
            requiredNode->prev=head;
            head->next=requiredNode;

            requiredNode->next=nextToHead;
            nextToHead->prev=requiredNode;

            return mpp[key]->value;
        }
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->value=value;
            
            Node* requiredNode=mpp[key];

            Node* prevNode=requiredNode->prev;
            Node* nextNode=requiredNode->next;

            prevNode->next=nextNode;
            nextNode->prev=prevNode;

            Node* nextToHead=head->next;
            head->next=requiredNode;
            requiredNode->prev=head;

            requiredNode->next=nextToHead;
            nextToHead->prev=requiredNode;
        }
        else{
            if(curCap>=cap){
               Node* lastNode=tail->prev;
               Node* prevNode=lastNode->prev;

               prevNode->next=tail;
               tail->prev=prevNode;

               mpp.erase(lastNode->key);
               curCap--;
               delete(lastNode);
            }
            Node* insertNode=new Node(key,value);
            mpp[key]=insertNode;

            Node* nextToHead=head->next;
            head->next=insertNode;
            insertNode->prev=head;
            insertNode->next=nextToHead;
            nextToHead->prev=insertNode;
            curCap++;
        }
    }
};
