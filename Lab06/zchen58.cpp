#include <iostream>
#include <list>
#include <sstream>

using namespace std;

//sources: textbook p.258 chapter 11. hash tables

int h(int k, int size) {
    int g;
    g = k % size;
	return g;
}

void Insert(list<int>*verList, int k, int size) {
	int i;
    i = 0;
	while(h(k, size) > i){
        i++;
    } 
	verList[i].insert(verList[i].begin(), k);
}

void Search(list<int>*verList, int k, int size) {
	int i;
    int j;
    i = 0;
    j = 0;

	bool Found;

	list<int>::iterator horList;
	while(h(k, size) > i) {
        i++;
    } 
	for( horList=verList[i].begin(); *horList!= k; horList++ ) {
		if (horList==verList[i].end()) {
            break;
        }
		j++;
	}
	cout << k << ":";
	if( *horList== k ) {
        cout << "FOUND_AT" << i << "," << j;
    } 
	else{
        cout << "NOT_FOUND";
    } 
	cout << ";\n";
}

void Delete(list<int>*verList, int k, int size) {
	int i;
    i = 0;
	list<int>::iterator horList;
	while (h(k, size) > i) {
        i++;
    }
	for( horList=verList[i].begin(); *horList!= k; horList++ ) {
		if (horList==verList[i].end())
			break;
	}
	cout << k << ":";
	if (*horList== k) {
		verList[i].erase(horList);
		cout << "DELETED";
	}
	else cout << "DELETE_FAILED";
	cout << ";\n";
}

int main(int argc, char **argv) {
	int size = 0;
	cin >> size;

	list<int>*verList = new list<int>[size];
    list<int>::iterator horList;

	int key = 0;

  char line[100];

  while ( std::cin.getline(line,100)) {
    string str(line);
    if ( str.size()==0 ) continue; 

//str is from sstreasize library
    else if (str.substr(0,1) == "e") {
    	return 0;
    }
    if (str.substr(0,1) == "o") {
        //output function
        for (int i = 0; i < size; i++) {
		    cout << i << ":";
		    for (horList =verList[i].begin(); horList!=verList[i].end(); horList++) {
			    cout << *horList<< "->";
		    }
		    cout << ";\n";
	    }
       continue;
    }   

    stringstream convert_stsize(str.substr(1,str.size()-1));
    if (!(convert_stsize >> key))
       return -1;

    if (str.substr(0,1) == "i") {
     	Insert(verList, key, size);
    }
    else if (str.substr(0,1) == "s") {
    	Search(verList, key, size);
    }
    else if (str.substr(0,1) == "d") {
    	Delete(verList, key, size);
    }
  }
}
