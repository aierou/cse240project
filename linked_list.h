#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

template <class Node> class linked_list{
	Node* head_;
  public:
	linked_list(Node* node);
	~linked_list();
	Node* head(){return head_;}
	void delete_node(Node* node);
	Node* push(Node* node);
};

template <class Node>
linked_list<Node>::linked_list(Node* node) : 
	head_(node)
{
	head_->next=NULL;
}
template <class Node>
linked_list<Node>::~linked_list(){
	delete_node(head_);
}
template <class Node>
void linked_list<Node>::delete_node(Node* node){
	Node* current=node;
	Node* prev;
	while(current->next!=NULL){
		prev=current;
		current=current->next;
		delete prev;
	}
}
template <class Node>
Node* linked_list<Node>::push(Node* node){
	Node* current=head_;
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=node;
	node->next=NULL;
	return node;
}


#endif // LINKED_LIST_H_