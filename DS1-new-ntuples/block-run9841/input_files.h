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
	input_files.push_back(prefix + "run_9841.0_ntuple.root");
	input_files.push_back(prefix + "run_9841.10_ntuple.root");
	input_files.push_back(prefix + "run_9841.11_ntuple.root");
	input_files.push_back(prefix + "run_9841.12_ntuple.root");
	input_files.push_back(prefix + "run_9841.13_ntuple.root");
	input_files.push_back(prefix + "run_9841.14_ntuple.root");
	input_files.push_back(prefix + "run_9841.15_ntuple.root");
	input_files.push_back(prefix + "run_9841.16_ntuple.root");
	input_files.push_back(prefix + "run_9841.17_ntuple.root");
	input_files.push_back(prefix + "run_9841.18_ntuple.root");
	input_files.push_back(prefix + "run_9841.19_ntuple.root");
	input_files.push_back(prefix + "run_9841.1_ntuple.root");
	input_files.push_back(prefix + "run_9841.2_ntuple.root");
	input_files.push_back(prefix + "run_9841.3_ntuple.root");
	input_files.push_back(prefix + "run_9841.4_ntuple.root");
	input_files.push_back(prefix + "run_9841.5_ntuple.root");
	input_files.push_back(prefix + "run_9841.6_ntuple.root");
	input_files.push_back(prefix + "run_9841.7_ntuple.root");
	input_files.push_back(prefix + "run_9841.8_ntuple.root");
	input_files.push_back(prefix + "run_9841.9_ntuple.root");
}
