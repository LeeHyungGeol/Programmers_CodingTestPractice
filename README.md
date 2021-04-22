# Programmers_CodingTestPractice
프로그래머스-코딩 테스트 연습

### string.find()

- 문자열을 찾았다면, 해당 문자열의 시작 위치를 리턴하고, 그렇지 않을 경우 npos(string::npos) 를 리턴한다.

---

## vector

### vector<pair<int, int>> compare 함수

```c++
ex)

typedef pair<int, int> pii;

bool compare(pii& a, pii& b) {
    if(a.first == b.first) {
      return a.second < b.second;
    }
    return a.first > b.first;
}
```

### vector.resize() 주의할 점

```c++
    vector<int> vec(5, 1); // 1 1 1 1 1

	vec.resize(10, 2);// 1 1 1 1 1 2 2 2 2 2

	vec.resize(3, 3);// 1 1 1
    
    // resize 하면 더 커지는 경우에만 값이 입력된다.
```

## map

ex) map<string, int> map;

- 노드 기반으로 이루어져있고 **균형 이진 트리 구조**입니다.
- **Map** - map은 key와 value로 이루어져있으며 이는 pair 객체 형태로 저장됩니다.
- **Unique Key** - key는 고유한 값이므로 중복이 불가능 합니다. (중복 key는 multimap 에서 가능합니다.)
- **Ordered** - map도 set과 마찬가지로 삽입이 되면서 **자동으로 정렬**이 됩니다. (default는 less/오름차순 입니다.)
- **Allocator-aware** - map container는 저장공간의 필요에 따라서 allocator 객체를 사용합니다. (동적할당 합니다.)

출처: https://blockdmask.tistory.com/87 [개발자 지망생]

### map 역순회

```c++
auto iter = map.end(); 

while(iter != map.begin()) { 
  iter--; 
  cout << iter->second << '\n'; 
}

```

### map -> vector

vector.assign(map.begin(), map.end());

### map과 vector의 혼합체

```c++
map<string, vector<pair<int, int>>> mapVectorPair;

mapVectorPair[String].push_back({Int, Int});

//map안의 vector : sort도 가능

 for(auto iter = mapVectorPair.begin(); iter != mapVectorPair.end(); ++iter) {
      sort(iter->second.begin(), iter->second.end(), compare);
 }
 ```
