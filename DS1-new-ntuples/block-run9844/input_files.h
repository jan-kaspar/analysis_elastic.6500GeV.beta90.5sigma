#include <string>
#include <vector>

//----------------------------------------------------------------------------------------------------

std::vector<std::string> input_files;

std::string input_ntuple_name;

void InitInputFiles()
{
	input_ntuple_name = "TotemNtuple";

	input_files.clear();

	std::string prefix = "root://eostotem.cern.ch//eos/totem/data/offline/2015/90m_5sigma/version2/";
	input_files.push_back(prefix + "run_9844.0_ntuple.root");
	input_files.push_back(prefix + "run_9844.1_ntuple.root");
	input_files.push_back(prefix + "run_9844.2_ntuple.root");
	input_files.push_back(prefix + "run_9844.3_ntuple.root");
	input_files.push_back(prefix + "run_9844.4_ntuple.root");
	input_files.push_back(prefix + "run_9844.5_ntuple.root");
	input_files.push_back(prefix + "run_9844.6_ntuple.root");
	input_files.push_back(prefix + "run_9844.7_ntuple.root");
	input_files.push_back(prefix + "run_9844.8_ntuple.root");
	input_files.push_back(prefix + "run_9844.9_ntuple.root");
}
