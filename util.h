#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <string>

class util{
  public:
	static std::vector<std::string> split(std::string search, char splitter){
		std::vector<std::string> ret;
		unsigned int left=0;
		for(unsigned int i=0;i<search.length();i++){
			if(search.at(i)==splitter){
				ret.push_back(search.substr(left,i-left));
				left=++i;
			}
		}
		ret.push_back(search.substr(left,search.length()));
		return ret;
	}
};

#endif // UTIL_H_