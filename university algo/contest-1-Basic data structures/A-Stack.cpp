#include<string>
#include<iostream> 
struct node {
    int val;
    int size;
    node *prev;
    node (node *prev_now){
        prev = prev_now;
    }
    node (int n_value){
        val = n_value;
        size = n_value;
    }
};

///////////////////////////////
node* push_stack(node* last_of_struct, int push_val);
node* delete_el_of_stack(node* last_of_struct);
node* clear_el_of_stack(node* last_of_struct);
bool write_last_of_stack(node* last_of_struct);
bool write_size_of_stack(node* last_of_struct);
node* clear_stack(node* last_of_struct);
void exit();
///////////////////////////////
node* push_stack(node* last_of_struct, int push_val) {
    int prev_size;   
    node* n=new node(0);
    n->val = push_val;
    n->size = 1;
    n->prev = nullptr;
    if (last_of_struct != nullptr) { 
        prev_size = last_of_struct->size;
        n->prev = last_of_struct;
        n->size = prev_size + 1;
    }
    std::cout << "ok" << '\n';
    return n;
}

node* delete_el_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        std::cout << "error"<<'\n';
        return last_of_struct;
    }
    write_last_of_stack(last_of_struct);
    last_of_struct = last_of_struct->prev;
    return last_of_struct;
}

node* clear_el_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        std::cout << "error"<<'\n';
        return last_of_struct;
    }
    last_of_struct = last_of_struct->prev;
    return last_of_struct;
}

bool write_last_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        std::cout << "error"<<'\n';
        return 0;
    }
    std::cout << last_of_struct->val<<'\n';
    return 1;
}

bool write_size_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        std::cout << 0 <<'\n';
        return 0;
    }
    std::cout << last_of_struct->size<<'\n';
    return 1;
}

node* clear_stack(node* last_of_struct){
    while (last_of_struct != nullptr) last_of_struct = clear_el_of_stack(last_of_struct);
    if (last_of_struct == nullptr) std::cout << "ok"<<'\n';
    return last_of_struct;
}

void exit(){
    std::cout << "bye" << '\n';
}

int main(){
    node* last=nullptr;
    std::string current_request;
    while (current_request != "exit")
    {
        std::cin >> current_request;
        int now;
        if (current_request == "push") 
        {
            std::cin >> now;
            last = push_stack(last, now);
        }
        if (current_request=="pop"){
            last = delete_el_of_stack(last);
        }
        if (current_request=="back"){
            write_last_of_stack(last);
        }
        if (current_request=="size"){
            write_size_of_stack(last);
        }
        if (current_request=="clear"){
            last=clear_stack(last);
        }
        if (current_request=="exit"){
            exit();
        }
    }
    return 0;
}