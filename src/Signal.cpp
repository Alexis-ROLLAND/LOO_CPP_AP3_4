
#include "Signal.hpp"

//----------------------------------------------------------------------
Signal::Signal(float tStop, unsigned int NbPoints):tStop{tStop},NbPoints{NbPoints},needToCompute{true}{

	Refresh_dt();
}

//----------------------------------------------------------------------
float 	Signal::getValtn(int Pos)const{
	if (this->needToCompute) this->Compute();
		
	return tn.at(Pos);
}
//----------------------------------------------------------------------
float 	Signal::getValsignal_tn(int Pos)const{
	if (this->needToCompute) this->Compute();
	return signal_tn.at(Pos);
}
//----------------------------------------------------------------------
void	Signal::Refresh_dt()const{
	
	if (tStop <= 0) tStop = defaulttStop;	// Reset tStop to 1 in case of wrong/bad value
	if (NbPoints == 0) NbPoints = defaultNbPoints;	// Reset NbPoints to 100 in case of wrong/bad value
	
	dt = (tStop - tStart)/NbPoints;
	needToCompute = true;
}
//----------------------------------------------------------------------
int	Signal::Generate(std::string FileName)const{
	if (needToCompute){
		if (Compute() != 0) return -1;	// Compute problem... 
	}
	
	if ( (tn.size() != NbPoints) || (signal_tn.size() != NbPoints) ) return -3;	// Size incoherency
	
	std::ofstream outputfile(FileName,std::ofstream::out);
	if (outputfile.fail()) return -2;	// File problem...
	
	for (unsigned int i=0 ; i<NbPoints ; i++){
		float x=tn.at(i);
		float y=signal_tn.at(i);
		std::string data_line = std::to_string(x)+"\t"+std::to_string(y)+"\n";
		
		outputfile << data_line;
	} 
	outputfile.close();
	
	return 0;
}


