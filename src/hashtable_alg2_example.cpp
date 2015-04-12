//
// A More Evolved Hash Table Example
// hashtable_alg2_example.cpp
// Description: TABLE contains a count of the number of elements and a pointer to the first one
//				BIN: each element is a BIN structure in which firstNode points to a word list
//				nodes: contains the number of nodes in the list.
//
// created: 4/11/15 by j-concept
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int LINE_LEN = 256;		// size of input buffer
const char * const ORIG_FNAME = "/Users/kojo/Documents/workspace/concepts/TestFile1.txt";

// Node Descriptor
struct Node
{
	Node *next;
	size_t count;			// size_t is an unsigned integral type
	char *string;
};

struct BIN
{
	size_t nodes;
	Node *firstNode;
};

struct TABLE
{
	size_t bins;
	BIN *firstBin;
};

// Hash function
int HashFunction(const char *key, size_t bins)
{
	return (int)(strlen(key) % bins);		// value is number of characters % bins
}


TABLE *CreateTable(size_t bins)
{
	TABLE *hashTable;		// create a hash table object
	BIN *bin;				// create a pointer to the first bin
	BIN *end;				// create a pointer to the last bin

	hashTable = new(nothrow)TABLE[sizeof(TABLE)];				// allocate memory for one hash table (too lazy to check if this value is NULL first before moving on)
	hashTable->bins = bins;										// how many bins (value passed into this function)
	hashTable->firstBin = new(nothrow)BIN[bins * sizeof(BIN)];	// allocate memory for N = "bins * sizeof(BIN)" bins (Heap)
	end = hashTable->firstBin + bins;							// end points to the last bin in the hash table

	for (bin = hashTable->firstBin; bin < end; ++bin) {			// bin initialization loop (increment each bin and set firstNode to NULL)
		bin->nodes = 0;											// initialize node count
//		hashTable->firstBin->bin->nodes = 0;					// why not this instead of line above? how is bin->nodes = 0 associated with the hashtable created earlier?
		bin->firstNode = NULL;									// initialize head pointer
	}

	return(hashTable);
}

void BuildList(BIN *bp, const char *str)
{
	Node *p;
	p = bp->firstNode;

	for(; p != NULL; p = p->next)
		if (!strcmp(p->string, str))
			break;

	if (p == NULL) {
		size_t length = strlen(str) + 1;

		p = new(nothrow)Node[sizeof(Node)];
		p->string = new(nothrow)char[length];
		memcpy(p->string, str, length);
		p->count = 1;
		p->next = bp->firstNode;
		bp->firstNode = p;
		++bp->nodes;
	}
	else
		++p->count;
}

void PrintTable(const TABLE *hashTable)
{
	BIN *bin;
	BIN *end;
	Node *node;
//	cout << "Inside PrintTable function now";
	end = hashTable->firstBin + hashTable->bins;					// end = pointer to the last bin
	for (bin = hashTable->firstBin; bin < end; ++bin) {				// visit bins
		cout << bin->nodes << " entries for hash key = " << bin - hashTable->firstBin << ":" << '\n';	// visit nodes
		for (node = bin->firstNode; node != NULL; node = node->next)
			cout << (int)node->count << " ea. : " << node->string << '\n';
	}
}

void DeleteTable(TABLE *hashTable)
{
	BIN *bin;
	BIN *end;
	Node *p;
	Node *node;

	end = hashTable->firstBin + hashTable->bins;
	for (bin = hashTable->firstBin; bin < end; ++bin)	// visit bins
		for (node = bin->firstNode; node != NULL;) {
			p = node;
			node = node->next;
			delete p->string;
			delete p;
		}
		delete hashTable->firstBin;		// delete all bins
		delete hashTable;				// delete the table descriptor
}


int main()
{
	char buf[LINE_LEN];		// word string buffer
	int howManyBins = 20;	// made constant
	TABLE *hashTable;		// pointer to hash table
	BIN *bin;				// pointer to a bin
	string line;

	hashTable = CreateTable((size_t)howManyBins);

    ifstream orig_file;
    orig_file.open(ORIG_FNAME);

     if (orig_file.is_open())
     {
		 while (!orig_file.eof())
		 {
			 orig_file >> buf;
			 bin = &hashTable->firstBin[HashFunction(buf,(size_t)howManyBins)];
			 BuildList(bin, buf);
		 }
    }

     PrintTable(hashTable);
     DeleteTable(hashTable);

     orig_file.close();

	return 0;
}




