#include <string>
#include <vector>

//----------------------------------------------------------------------------------------------------

std::vector<std::string> input_files;

std::string input_ntuple_name;

void InitInputFiles()
{
	input_ntuple_name = "TotemNtuple";

	input_files.clear();

	// 2015_10_13_fill4489, DS1

	std::string prefix = "rfio:///castor/cern.ch/user/j/jkaspar/reco/sr/";
	input_files.push_back(prefix + "9836_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9838_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9840_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9840_EVB11_1.10-19_ntuple.root");
	input_files.push_back(prefix + "9841_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9843_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9844_EVB11_1.0-9_ntuple.root");
	input_files.push_back(prefix + "9845_EVB11_1.0-9_ntuple.root");
}
