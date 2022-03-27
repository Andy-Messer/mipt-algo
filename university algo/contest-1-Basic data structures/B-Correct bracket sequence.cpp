#include<string>
#include<iostream> 
struct node {
    long long type,size;
    node *prev;
    node (node *prev_now){
        prev = prev_now;
    }
    node (long long n_value){
        type = n_value;
        size = n_value;
    }
};

///////////////////////////////
node* push_stack(node* last_of_struct, long long push_val);
node* delete_el_of_stack(node* last_of_struct);
///////////////////////////////
node* push_stack(node* last_of_struct, long long push_val) {
    long long prev_size;   
    long long delta = 0;
    node* n=new node(delta);
    n->prev = nullptr;
    n->type = push_val;
    n->size = 1;
    if (last_of_struct != nullptr) { 
        n->prev = last_of_struct;
        prev_size = last_of_struct->size;
        n->size = prev_size + 1;
    }
    return n;
}

node* delete_el_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        return last_of_struct;
    }
    last_of_struct = last_of_struct->prev;
    return last_of_struct;
}

std::pair <std::string, long long> what_type_bracket(char bracket) {
    if (bracket == '(') return { "open",1 };
    if (bracket == '{') return { "open",2 };
    if (bracket == '[') return { "open",3 };
    if (bracket == ')') return { "close",1 };
    if (bracket == '}') return { "close",2 };
    if (bracket == ']') return { "close",3 };
}

bool check_bracket(node* last_el_of_stack, long long type_now) {
    if (last_el_of_stack == nullptr)return 0;
    if (last_el_of_stack->type == type_now) return 1;
    return 0;
}
bool answer_check(node* last_el_of_stack){
    if (last_el_of_stack == nullptr)  return 1;
    return 0;
}

long long size_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        return 0;
    }
    return last_of_struct->size;
}

int main(){
    node* last=nullptr;
    std::string cor_bracket_seq;
    getline(std::cin, cor_bracket_seq);
    long long counter = 0;
    bool wrong_answer_flag = 0;
    long long cbq_size = cor_bracket_seq.size();
    for (long long cur = 0;cur < cbq_size;cur++) {
        std::pair <std::string, long long> current_bracket = what_type_bracket(cor_bracket_seq[cur]);
        long long cur_size = size_of_stack(last);
        if (cbq_size - cur >= cur_size) {
            if (current_bracket.first == "open")
                last = push_stack(last, current_bracket.second);
            else {
                if (check_bracket(last, current_bracket.second))
                    last = delete_el_of_stack(last);
                else
                    wrong_answer_flag = 1;
            }
        }
        else
            wrong_answer_flag = 1;
    }
    if (wrong_answer_flag || !answer_check(last)) std::cout << "no";
    else std::cout << "yes";
    return 0;
}