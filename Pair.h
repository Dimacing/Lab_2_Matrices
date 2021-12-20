#include <tuple>

template<typename F,typename S>
class Pair {
public:
    const F f;
    const S s;
    Pair():f(S()),s(S()){}
    Pair(F first, S second) : f(first), s(second) {}
};

bool operator > (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.f,lhs.s) > std::make_tuple(rhs.f,rhs.s);
}

bool operator != (const Pair<int,int>& lhs,const Pair<int,int>& rhs){
    return std::make_tuple(lhs.f,lhs.s) != std::make_tuple(rhs.f,rhs.s);
}