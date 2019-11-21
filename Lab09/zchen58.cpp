//collaborator: Tom Mcgee
//Sources used: textbook p.431
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

//node struct
struct node {
	double freq;
	char content;
	string encoding;
	node *left;
	node *right;
};
vector<node> arr;

//removes the min from 
node extractMin() {
	double value = INT_MAX;

	vector<node>::iterator i, j;
	for(i = arr.begin(); i != arr.end(); i++)
	{
		if(value > (*i).freq)
		{
			j = i;
			value = (*i).freq;
		}
	}

	node temp = (*j);
	arr.erase(j);
	return temp;
}

node HuffmanTree()
{
	while(!arr.empty())
	{
		node *tempNode1 = new node();
		node *tempNode2 = new node();
		node *tempNode3 = new node();
		*tempNode2 = extractMin();
		*tempNode3 = extractMin();

		tempNode1->left = tempNode2;
		tempNode1->right = tempNode3;
		tempNode1->freq = tempNode2->freq+tempNode3->freq;
		arr.push_back(*tempNode1);

		if(arr.size() == 1)
		{
			break;
		}
	}
	return arr[0];
}

void BFS(node *tempRoot, string str, char ch)
{
	node *root = new node();
	root = tempRoot;
	root->encoding = str;
	
	if((root->left == NULL) && (root->right == NULL))
	{
		if(root->content == ch)
		{
			cout << root->content << ":" << root->encoding <<endl;
		}
	}
	else
	{
		//create node encoding
		root->left->encoding = str.append("0");
		str.erase(str.end() - 1);
		root->right->encoding = str.append("1");
		str.erase(str.end() - 1);
		BFS(root->left, str.append("0"), ch);
		str.erase(str.end() - 1);
		BFS(root->right, str.append("1"), ch);
		str.erase(str.end() - 1);
	}
}

int main() {
	//construct node array
	double freqIn;
	char symbol = ' ';
	for(int i = 0; i < 6; i++)
	{
		node tempNode;
		cin >> freqIn;
		switch(i)
		{
			case 0:
			symbol = 'A';
			break;
			case 1:
			symbol = 'B';
			break;
			case 2:
			symbol = 'C';
			break;
			case 3:
			symbol = 'D';
			break;
			case 4:
			symbol = 'E';
			break;
			default: 
			symbol = 'F';
			break;
		}
		tempNode.freq = freqIn;
		tempNode.content = symbol;
		tempNode.left = NULL;
		tempNode.right = NULL;
		arr.push_back(tempNode);
	}
	//construct HuffmanTree with the array
	node root = HuffmanTree();
	
	BFS(&root, "", 'A');	
	BFS(&root, "", 'B');
	BFS(&root, "", 'C');
	BFS(&root, "", 'D');
	BFS(&root, "", 'E');
	BFS(&root, "", 'F');

	return 0;
}