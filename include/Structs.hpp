
#include <utility>

using ErrorCode = unsigned int;

template<typename A> 
struct ResultBool: public std::pair<A, bool>{
};

template<typename A> 
struct ResultInt: public std::pair<A, ErrorCode>{
};