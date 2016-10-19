//OBSOLOTE - KEPT FOR REFERENCE FOR TUESDAY
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
/*	cout << "Name of file to read from: ";
	string infile;
	cin >> infile;
	ifstream ist {infile};
	if(!ist) throw runtime_error("Unable to load specified file "+infile);
	string line, s; 
	vector<string> tokenized_line;

	while (getline(infile,line))
	{
		//istringstream f(line);
		while (getline(line, s, ',')) {
			tokenized_line.push_back(s);
		}
	}
*/
}

void Fileio::savefile()
{
	cout << "Name of file to write to: ";
	string outfile;
	cin >> outfile;
	ofstream ofs;
	ofs.open (outfile.c_str());
	if(!ofs) throw runtime_error("Unable to open output file "+outfile);


	//const vector<Head>& heads = shop.getHeads();
	//const vector<Locomotor>& locomotors = shop.getLocomotors();
	//const vector<Torso>& torsos = shop.getTorsos();
	//const vector<Battery>& batteries = shop.getBatteries();
	//const vector<Arm>& arms = shop.getArms();
	vector<SalesAssociate> associates = shop.getSalesAssociates();
	vector<Customer> customers = shop.getCustomers();
	vector<RobotModel> models = shop.getModels();

	for (int i = 0; i < PartType::NUM_OF_PART_TYPES; i++)
	{
		ofs << "//start " << PartType(i) << "//\n";
		PartType type(i);
		vector<type> partp;
		switch (partp)
		{
			case 0:
			shop.getHeads();
			break;

			case 1:
			shop.getLocomotors();
			break;

			case 2:
			shop.getTorsos();
			break;

			case 3:
			shop.getBatteries();
			break;

			case 4:
			shop.getArms();
		}

		for (int j = 0; j < partp.size(); j++)
		{
			ofs << partp[i].getData << "\n";
		}

		ofs << "//end " << PartType(i) << "//\n";
	}




	ofs.close();
}



/*
Good stuff for tokenizing

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> strings;
    istringstream f("denmark;sweden;india;us");
    string s;    
    while (getline(f, s, ';')) {
        cout << s << endl;
        strings.push_back(s);
    }
}

*/
