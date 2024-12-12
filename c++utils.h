#ifndef _UTILS_H_
#define _UTILS_H_
#include <bits/stdc++.h>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", "; 
        }
    }
    os << "]";
    return os;
}

template <typename T>
void print(const T& lhs)
{
    std::stringstream ss;
    ss << lhs;
    cout << ss.str() << endl;
}


#endif /* _UTILS_H_ */
