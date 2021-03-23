//https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        Node* myhead,*prev;
        
        myhead= new Node(0);
        myhead->val=temp->val;
        prev=myhead;
    unordered_map<Node*,Node*>umap;
            umap[temp]=prev;
        while(temp->next!=NULL){
            prev->next=new Node(0);
            umap[temp->next]=prev->next;
            prev->next->val=temp->next->val;
            prev=prev->next;
            temp=temp->next; 
        
        }
        
         prev->next=NULL;
        temp=head;
        while(temp!=NULL){
            umap[temp]->random=umap[temp->random];
            temp=temp->next;
        }
        
        return myhead;
       
    }
};