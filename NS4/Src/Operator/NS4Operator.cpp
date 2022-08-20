#include "NS4Operator.h"


namespace ns4 {

	COperator::COperator( double _dStartingVal, double _dFreq ) :
		m_dVal( _dStartingVal ),
		m_dFreq( _dFreq ) {
	}
	COperator::~COperator() {
	}

}	// namespace ns4
