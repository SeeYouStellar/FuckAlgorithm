```C++
struct cmp{
    bool  operator ()  ( int  r , int  l  ){
        return r>l;
	} 
}; 
struct cmp1{
    bool operator ()( int a ,int b ){
        return a<b;  // 当返回true时表示两数要交换
	}
};
int  main(void){
//   priority_queue< int > q;// 默认是 从大到小。 
//   priority_queue < int , vector<int> ,less<int> > q;//从大到小 
//   priority_queue < int , vector<int>, greater<int> > q; //从小到大，需要vector
//  priority_queue < int , vector<int> , cmp1  > q;//从大到小，需要vector
//   priority_queue < int , vector<int> , cmp  > q;//从小到大，需要vector
}
```

