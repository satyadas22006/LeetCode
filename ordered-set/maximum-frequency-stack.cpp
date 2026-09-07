#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

class FreqStack {
public:
    //stores count-> number mapping
    unordered_map<int,int> mp;
    //stores freq and count(index)
    //stores number and freq mapp
    unordered_map<int,int> freq;
    priority_queue<pair<int,int>> pq;
    int count=0;
    FreqStack() 
    {
        //freq,number
        //priority_queue<pair<int,int>> pq;
        
    }
    
    void push(int val) 
    {
        //maps index to value
        mp[count]=val;
        freq[val]++;
        pq.push({freq[val],count});
        count++;
    }
    
    int pop() 
    {
        //stores the freq and index
        auto x=pq.top();
        pq.pop();
        return mp[x.second];
    }
};