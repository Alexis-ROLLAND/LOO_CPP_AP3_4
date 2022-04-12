#ifndef __ARBITRARY_H__
#define	__ARBITRARY_H__

#include "Signal.hpp"

constexpr	float 	defaultArbValue = 0;

//----------------------------------------------------------------------
class DifferentnbPointsException{};
class DifferenttStopException{};
class FileError{
	public:
	std::string errMessage;
	FileError(std::string errMessage="File Error"):errMessage{errMessage}{};
	};
//----------------------------------------------------------------------
class Arbitrary:public Signal{
	private:
	
	int		Compute()const ;
	
	public:
	Arbitrary(const Signal &OrigSignal);					// Copy Ctor
	Arbitrary(float tStop=defaulttStop, unsigned int NbPoints=defaultNbPoints); 			// default Ctor, ne need to delegated ctor here
	
	Arbitrary(float tStop, const std::vector<float> &orig_signal_tn);	// Specific Ctor #1, based on a filled vector
	Arbitrary(float tStop, std::string FileName);						// Specific Ctor #2, based on a ".data" file
	
	virtual ~Arbitrary(){};
	
	int Import(const std::vector<float> &orig_signal_tn);
	int	Append(const Signal &SigToAppend);
	
	friend Arbitrary operator+(const Arbitrary&, const Arbitrary&);
	
};	

#endif
