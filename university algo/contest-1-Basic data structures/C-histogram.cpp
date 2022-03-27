#include<string>
#include<vector>
#include<iostream> 
#include<string>
#include<iostream> 
#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
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
    return n;
}

node* delete_el_of_stack(node* last_of_struct) {
    if (last_of_struct == nullptr) {
        std::cout << "error" << '\n';
        return last_of_struct;
    }
    last_of_struct = last_of_struct->prev;
    return last_of_struct;
}

long long size_of_stack(node* last_of_struct){
    if (last_of_struct == nullptr) return 0;
    else 
    return (last_of_struct->size);
}

int main() {
    IOS;
    int N;
    std::cin >> N;
    node* left = nullptr;node* right = nullptr;
    std::vector<long long>a(N+1, 0);
    std::vector<long long> min_r(N+1, N+1);
    std::vector<long long> min_l(N+1, 0);
    for (int i = 1;i <= N;i++) {
        std::cin >> a[i];
    }
    for (int i = 1;i <= N;i++) {
        while (size_of_stack(left) != 0 && a[left->val] >= a[i])    left=delete_el_of_stack(left);
        if (size_of_stack(left) != 0)   min_l[i] = left->val;
        left = push_stack(left, i);
    }
    for (int i = N;i >= 1;i--) {
        while (size_of_stack(right) != 0 && a[right->val] >= a[i])    right=delete_el_of_stack(right);
        if (size_of_stack(right) != 0)   min_r[i] = right->val;
        else min_r[i] = N + 1;
        right = push_stack(right, i);
    }
    long long ans = 0;

    for (int i = 1;i <= N;i++) {
        ans = std::max(ans, a[i] * (min_r[i] - min_l[i] - 1));
    }
    std::cout << ans;
}