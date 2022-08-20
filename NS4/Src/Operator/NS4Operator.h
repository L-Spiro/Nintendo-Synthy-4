#pragma once


namespace ns4 {

	class COperator {
	public :
		COperator( double _dStartingVal, double _dFreq );
		virtual ~COperator();


		// == Functions.
		/**
		 * Advances the operation by the given amount.
		 *
		 * \param _dTime The time by which to advance the operation.
		 */
		virtual void							Tick( double /*_dTime*/ ) {}

		/**
		 * Gets the current value.
		 *
		 * \return Returns the current value of the operator.
		 */
		virtual double							Val() const { return m_dVal; }


	protected :
		// == Members.
		/** The effective value. */
		double									m_dVal;
		/** The master frequency. */
		double									m_dFreq;

	};

}	// namespace ns4
