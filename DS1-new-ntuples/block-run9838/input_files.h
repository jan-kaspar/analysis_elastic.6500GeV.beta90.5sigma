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
	input_files.push_back(prefix + "run_9838.0_ntuple.root");
	input_files.push_back(prefix + "run_9838.10_ntuple.root");
	input_files.push_back(prefix + "run_9838.11_ntuple.root");
	input_files.push_back(prefix + "run_9838.12_ntuple.root");
	input_files.push_back(prefix + "run_9838.13_ntuple.root");
	input_files.push_back(prefix + "run_9838.14_ntuple.root");
	input_files.push_back(prefix + "run_9838.15_ntuple.root");
	input_files.push_back(prefix + "run_9838.16_ntuple.root");
	input_files.push_back(prefix + "run_9838.17_ntuple.root");
	input_files.push_back(prefix + "run_9838.18_ntuple.root");
	input_files.push_back(prefix + "run_9838.19_ntuple.root");
	input_files.push_back(prefix + "run_9838.1_ntuple.root");
	input_files.push_back(prefix + "run_9838.20_ntuple.root");
	input_files.push_back(prefix + "run_9838.21_ntuple.root");
	input_files.push_back(prefix + "run_9838.22_ntuple.root");
	input_files.push_back(prefix + "run_9838.23_ntuple.root");
	input_files.push_back(prefix + "run_9838.24_ntuple.root");
	input_files.push_back(prefix + "run_9838.25_ntuple.root");
	input_files.push_back(prefix + "run_9838.26_ntuple.root");
	input_files.push_back(prefix + "run_9838.27_ntuple.root");
	input_files.push_back(prefix + "run_9838.28_ntuple.root");
	input_files.push_back(prefix + "run_9838.29_ntuple.root");
	input_files.push_back(prefix + "run_9838.2_ntuple.root");
	input_files.push_back(prefix + "run_9838.3_ntuple.root");
	input_files.push_back(prefix + "run_9838.4_ntuple.root");
	input_files.push_back(prefix + "run_9838.5_ntuple.root");
	input_files.push_back(prefix + "run_9838.6_ntuple.root");
	input_files.push_back(prefix + "run_9838.7_ntuple.root");
	input_files.push_back(prefix + "run_9838.8_ntuple.root");
	input_files.push_back(prefix + "run_9838.9_ntuple.root");
}
