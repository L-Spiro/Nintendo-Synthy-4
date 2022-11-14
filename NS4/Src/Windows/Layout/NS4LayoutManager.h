#pragma once

#include <Layout/LSWLayoutManager.h>

using namespace lsw;

namespace ns4 {

	enum NS4_LAYOUT_TYPES : DWORD {
		NS4_MAIN_WINDOW				= LSW_LT_CUSTOM,
	};

	class CLayoutManager : public lsw::CLayoutManager {
	public :
		// == Functions.
		// Creates a class based on its type.
		virtual CWidget *				CreateWidget( const LSW_WIDGET_LAYOUT &_wlLayout, CWidget * _pwParent, bool _bCreateWidget, HMENU _hMenu, uint64_t _ui64Data );
	};

}	// namespace ns4
