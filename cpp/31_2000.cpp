// Một phân số luôn luôn có thể được viết dưới số thập phân hữu hạn hoặc vô hạn tuần hoàn.
// Ví dụ:
// 23/5 = 4.6
// 3/8 = 0.375
// 1/3 = 0.(3)
// 45/56 = 0.803(571428)
//  ....
// Trong các ví dụ trên thì các chữ số đặt trong dấu ngoặc chỉ phần tuần hoàn của số thập phân.
// Nhiệm vụ của bạn là viết một chương trình nhập tử số (N) và nhập mẫu số (D), sau đó đưa
// ra kết quả là dạng thập phân của phân số N/D.
// Ví dụ chạy chương trình:
// Nhap N, D:1 7
// 1/7 = 0.(142857)_
#include <iostream>
#include <string>
#include <unordered_map>

#define ll long long

using namespace std;

string fracToDec(int n, int d){
    if(n == 0) return "0";
    
    string result;
    //th so am
    if((n < 0) ^ (d < 0)) result += "-";
    
    ll nume = abs((ll)n);
    ll deno = abs((ll)d);
    
    result += to_string(nume / deno);
    ll rem = nume % deno;
    
    if(rem == 0) return result;
    
    result += ".";
    
    unordered_map<ll, int> remMap;
    
    while(rem != 0){
        if(remMap.find(rem) != remMap.end()){
            result.insert(remMap[rem], "(");
            result += ")";
            break;
        }
        
        remMap[rem] = result.size();
        rem *= 10;
        result += to_string(rem / deno);
        rem %= deno; 
    }
    
    for(const auto& [key, val]: remMap){
        cout << "[ " << key << " ] : " << val << " ";   
    }
    return result;
}

int main()
{
    int n, d;
    cin >> n >> d;
    
    string result = fracToDec(n, d);
    
    cout << result;

    return 0;
}
