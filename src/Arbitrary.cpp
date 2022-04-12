#include "Arbitrary.hpp"

//----------------------------------------------------------------------
Arbitrary::Arbitrary(float tStop, unsigned int NbPoints):Signal(tStop,NbPoints){
		float 	real_t;
		// set the "t" vector
		for (int t=0;t<NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		}
		
		// Fills the output vector with default value
		this->signal_tn.assign(NbPoints,defaultArbValue);
		
		
		
		}

//----------------------------------------------------------------------
Arbitrary::Arbitrary(const Signal &OrigSignal):Signal(OrigSignal.gettStop(),OrigSignal.getNbPoints()){
	
	
	this->tn.clear();
	this->signal_tn.clear();
	
	for (int i=0;i<this->NbPoints;i++){
		this->tn.push_back(OrigSignal.getValtn(i));
		this->signal_tn.push_back(OrigSignal.getValsignal_tn(i));
		
		
		}
}
//----------------------------------------------------------------------
Arbitrary::Arbitrary(float tStop, const std::vector<float> &orig_signal_tn):Signal(tStop,orig_signal_tn.size()){
	float 	real_t;
	this->tn.clear();
	this->signal_tn.clear();
	
	for (int t=0;t<NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		this->signal_tn.push_back(orig_signal_tn.at(t));
	}
				
}
//----------------------------------------------------------------------
Arbitrary::Arbitrary(float tStop, std::string FileName):Signal(tStop,0){
	std::ifstream inputfile(FileName,std::ifstream::in);
	if (inputfile.fail()){
		throw(FileError("Error opening the file."));
	} 
	
	std::string Line;
	int Index;
	std::vector<float> tmp_vect;
	
	while(inputfile.eof() == false){
		std::getline(inputfile,Line);	// use of sdt::getline instead of inputfile >> 
		if (Line.size() > 0){
			if ((Index = Line.find("\t",0)) == std::string::npos){ 	// /!\ ' ' != '\t' 
				tmp_vect.push_back(std::stof(Line));
			}
			else{
	
				tmp_vect.push_back(std::stof(Line.substr(Index)));
			} 
		}
	}
	inputfile.close();
	
	// Check what's inside tmp_vect
	for (float Val:tmp_vect) std::cout << Val << std::endl;
	

	this->NbPoints = tmp_vect.size();
	std::cout << "NbPoints = " << this->NbPoints << "- tStop = " << this->tStop << std::endl;
	
	this->Refresh_dt();
	float real_t;
	for (int t=0;t<this->NbPoints;t++){
		real_t = t*dt;
		this->tn.push_back(real_t);
		this->signal_tn.push_back(tmp_vect.at(t));
	}
	
}
//----------------------------------------------------------------------
int Arbitrary::Import(const std::vector<float> &orig_signal_tn){

	if (orig_signal_tn.size() != this->NbPoints) return -1;	// Error : sizes aren't the same
	this->signal_tn.clear();
	for (int t=0;t<this->NbPoints;t++){
		this->signal_tn.push_back(orig_signal_tn.at(t));
	}
	this->needToCompute=true;
	return 0;
}
//----------------------------------------------------------------------		
int		Arbitrary::Compute()const{

	this->needToCompute=false;
	return 0;	
}
//----------------------------------------------------------------------
int	Arbitrary::Append(const Signal &SigToAppend){
	
	// Check sizes : the signal to append must have same tStop and NbPoints as the "this" signal
	if (SigToAppend.getNbPoints() != this->NbPoints) return -1;	// Error : sizes aren't the same
	if (SigToAppend.gettStop() != this->tStop) return -2;		// Error : tStop differs
	
	std::vector<float> oldVector=signal_tn;
	
	this->signal_tn.clear();
	for (int t=0;t<this->NbPoints;t++){
		this->signal_tn.push_back(oldVector.at(t) + SigToAppend.getValsignal_tn(t));
	}
	
	this->needToCompute=true;
	 
	return 0;
}
//----------------------------------------------------------------------
Arbitrary operator+(const Arbitrary &SignalA, const Arbitrary &SignalB){
	
	Arbitrary tmp(SignalA);
	int Res = tmp.Append(SignalB);
	if (Res == -1) throw DifferentnbPointsException();
	if (Res == -2) throw DifferenttStopException();

	return tmp;
}
//----------------------------------------------------------------------



