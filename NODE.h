
#include "Pair.h"

template<typename T>
class NODE {

public:
    Pair<Pair<int,int>,T> ind_value;
    NODE *LEFT ;
    NODE *RIGHT;

    explicit NODE(const Pair<Pair<int,int>,T>& indices_) : ind_value(indices_), LEFT(nullptr), RIGHT(nullptr){}

};

