#include <iostream>
#include <vector>
#include <string>
#include <fstream>
void swap_element
(
    long long a, long long b, std::vector<std::pair<long long,std::string>> &num
)
{
    std::pair<long long, std::string> c;
    c = num[a];
    num[a] = num[b];
    num[b] = c;
}

long long interpret_to_long
(
    std::string now
)
{

    long long wr=0;
    long long number_length = now.size();
    for (long long i=0;i<number_length;i++){

        wr += now[i] - '0';
        wr *= 10;

    }
    wr /= 10;

    return wr;

}
char check_str
(
    std::string a, std::string b
)
{
    
    for (int i=0;i<a.size();i++){
        if (a[i]-'0'>b[i]-'0'){
            return '0';
        }
        if (a[i]-'0'<b[i]-'0'){
            return '1';
        }
    }
    return '2';
    
}
long long sort
(
    
    long long left_glob,
    long long right_glob, 
    std::vector<std::pair<long long,std::string>> &num
    
) 
{
    long long len_N=num.size();
    for (long long i=0;i<len_N-1;i++){
        for (long long j=i+1;j<len_N;j++){
            std::string v_1,v_2;
            v_1 = num[i].second + num[j].second;
            v_2 = num[j].second + num[i].second;
            
            if (check_str(v_1,v_2)=='0') swap_element(i, j, num);
        }
    }
}


int main() {

    std::vector<std::pair<long long, std::string>> num(0);
    std::string element;
    long long size_num = 0;

    std::ifstream in;
    std::ofstream out;
    in.open("number.in");
    out.open("number.out");
    
    while (in>>element) {
        
        num.push_back({ interpret_to_long(element), element });
        size_num++;
    }
    if (size_num!=0)
    sort(0, size_num-1, num);
    std::string ans="";
    
    for (long long i = size_num-1;i >=0;i--)
    {
        ans += num[i].second;
    }
    
    out << ans;
    
    in.close();
    out.close();
    
}