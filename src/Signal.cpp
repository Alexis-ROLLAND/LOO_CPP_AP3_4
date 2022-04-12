
#include "Signal.hpp"

//----------------------------------------------------------------------
Signal::Signal(float tStop, unsigned int NbPoints):tStop{tStop},NbPoints{NbPoints},needToCompute{true}{

	Refresh_dt();
}

//----------------------------------------------------------------------
float 	Signal::getValtn(int Pos)const{
	if (this->needToCompute) this->Compute();
	return this->tn.at(Pos);
}
//----------------------------------------------------------------------
float 	Signal::getValsignal_tn(int Pos)const{
	if (this->needToCompute) this->Compute();
	return this->signal_tn.at(Pos);
}
//----------------------------------------------------------------------
void	Signal::Refresh_dt()const{
	
	if (this->tStop <= 0) this->tStop = defaulttStop;	// Reset tStop to 1 in case of wrong/bad value
	if (this->NbPoints == 0) this->NbPoints = defaultNbPoints;	// Reset NbPoints to 100 in case of wrong/bad value
	
	this->dt = (this->tStop - this->tStart)/this->NbPoints;
	this->needToCompute = true;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int	Signal::Generate(std::string FileName)const{
	if (this->needToCompute){
		if (this->Compute() != 0) return -1;	// Compute problem... 
	}
	
	if ( (this->tn.size() != this->NbPoints) || (this->signal_tn.size() != this->NbPoints) ) return -3;	// Size incoherency
	
	std::ofstream outputfile(FileName,std::ofstream::out);
	if (outputfile.fail()) return -2;	// File problem...
	
	for (unsigned int i=0 ; i<this->NbPoints ; i++){
		float x=this->tn.at(i);
		float y=this->signal_tn.at(i);
		std::string data_line = std::to_string(x)+"\t"+std::to_string(y)+"\n";
		
		outputfile << data_line;
	} 
	outputfile.close();
	
	return 0;
}
//----------------------------------------------------------------------
Signal& Signal::operator=(const Signal &OrigSignal){
	
	if (this != &OrigSignal){
		this->NbPoints = OrigSignal.getNbPoints();
		this->tStop = OrigSignal.gettStop();
		
		this->tn.clear();
		this->signal_tn.clear();
		
		for (int i=0;i<this->NbPoints;i++){
			this->tn.push_back(OrigSignal.getValtn(i));
			this->signal_tn.push_back(OrigSignal.getValsignal_tn(i));
			
			}
		this->needToCompute=true;
	}
	
	return *this;
}
//----------------------------------------------------------------------


