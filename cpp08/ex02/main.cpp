
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>
#include <stack>

int main() {

std::stack<int> mstack;

mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
std::stack<int> s(mstack);
return 0;

}