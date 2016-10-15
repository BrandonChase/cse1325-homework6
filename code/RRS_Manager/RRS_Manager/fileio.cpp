#include "fileio.h"

using namespace std;
/*
process for saving:

input filename to save to.

check, does file already exist? if yes- ask to overwrite. 
-- check other possible errors associated with writing to a prexisting 
file, ex. file that is already being used by another process etc..

Take anything that can be outputted to "report menu"- for starters.

get dynamic size of each.

operator overload classes of each to file in for loop. ex. file<<heads[i]
at beginning of each loop print START_$TYPE (ex. START_HEAD, START_MODEL)
and end w/ the opposite as well.  this will make loading it easier later.


process for loading:

input filename of file to load.

if file does not exist, throw error.
if file is empty, through error.
once all checks are passed, begin loading process..

if argument is START_HEAD- addhead(args[0],...,args[6]) etc..
once end, go to next  **there are some potential issues here**








*/


void Fileio::loadfile()
{
	cout << "Name of file to read from: ";
	string infile;
	cin >> infile;
	ifstream ist {infile};
	if(!ist) throw runtime_error("Unable to load specified file"+infile);

	//Logic for reading in a file.


}

void Fileio::savefile()
{
	cout << "Name of file to write to: ";
	string outfile;
	cin >> outfile;
	ofstream ofs;
	ofs.open (outfile.c_str());
	if(!ofs) throw runtime_error("Unable to open output file"+outfile);

	// Logic for outputting to file



	ofs << "Writing this to a file\n";
	ofs.close();


}