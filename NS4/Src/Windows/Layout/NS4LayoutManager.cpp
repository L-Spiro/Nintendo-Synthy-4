#include "NS4LayoutManager.h"


namespace ns4 {

	// == Functions.
	// Creates a class based on its type.
	CWidget * CLayoutManager::CreateWidget( const LSW_WIDGET_LAYOUT &_wlLayout, CWidget * _pwParent, bool _bCreateWidget, HMENU _hMenu, uint64_t _ui64Data ) {
		switch ( _wlLayout.ltType ) {
			case NS4_MAIN_WINDOW : {
				//return new CMhsMainWindow( _wlLayout, _pwParent,  _bCreateWidget, _hMenu, _ui64Data );
			}
		}
		return lsw::CLayoutManager::CreateWidget( _wlLayout, _pwParent, _bCreateWidget, _hMenu, _ui64Data );
	}

}	// namespace ns4
