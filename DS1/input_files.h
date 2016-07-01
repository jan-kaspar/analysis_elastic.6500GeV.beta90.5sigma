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

	std::string prefix = "root://eostotem.cern.ch//eos/totem/data/cmstotem/2015/90m/Totem/Ntuple/version1/";

	for (auto evb : { "EVB11_1", "EVB11_2", "EVB12_1", "EVB12_2", "EVB13_1", "EVB13_2", "EVB14_1", "EVB14_2", "EVB15_1", "EVB15_2" } )
	{
		input_files.push_back(prefix + "9836_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9838_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9840_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9841_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9843_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9844_" + evb + ".0-9_ntuple.root");
		input_files.push_back(prefix + "9845_" + evb + ".0-9_ntuple.root");
	}
}
