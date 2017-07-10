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
	input_files.push_back(prefix + "run_9843.0_ntuple.root");
	input_files.push_back(prefix + "run_9843.10_ntuple.root");
	input_files.push_back(prefix + "run_9843.11_ntuple.root");
	input_files.push_back(prefix + "run_9843.12_ntuple.root");
	input_files.push_back(prefix + "run_9843.13_ntuple.root");
	input_files.push_back(prefix + "run_9843.14_ntuple.root");
	input_files.push_back(prefix + "run_9843.15_ntuple.root");
	input_files.push_back(prefix + "run_9843.16_ntuple.root");
	input_files.push_back(prefix + "run_9843.17_ntuple.root");
	input_files.push_back(prefix + "run_9843.18_ntuple.root");
	input_files.push_back(prefix + "run_9843.19_ntuple.root");
	input_files.push_back(prefix + "run_9843.1_ntuple.root");
	input_files.push_back(prefix + "run_9843.2_ntuple.root");
	input_files.push_back(prefix + "run_9843.3_ntuple.root");
	input_files.push_back(prefix + "run_9843.4_ntuple.root");
	input_files.push_back(prefix + "run_9843.5_ntuple.root");
	input_files.push_back(prefix + "run_9843.6_ntuple.root");
	input_files.push_back(prefix + "run_9843.7_ntuple.root");
	input_files.push_back(prefix + "run_9843.8_ntuple.root");
	input_files.push_back(prefix + "run_9843.9_ntuple.root");
}
