
#include "IOUtils.h"

template <typename T>
void ioutils::print(vector<T> data){
		if(data.empty())
			cout << "No data found" << endl;
		for(auto value: data)
			cout << value << endl;
}
void ioutils::enableFastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void ioutils::log(){
	cout << "Working"<<endl;
}