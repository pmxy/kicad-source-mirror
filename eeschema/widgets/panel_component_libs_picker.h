/*
 * panel_hierarchy_browser.h
 *
 *  Created on: 24 mai 2021
 *      Author: pmx
 */



#ifndef EESCHEMA_WIDGETS_PANEL_COMPONENT_LIBS_PICKER_BROWSER_H_
#define EESCHEMA_WIDGETS_PANEL_COMPONENT_LIBS_PICKER_BROWSER_H_

#include <widgets/panel_component_libs_picker_base.h>


class panel_component_libs_picker : public panel_component_libs_picker_base
{
public :
	panel_component_libs_picker( wxWindow* aParent );

//	~panel_hierarchy_browser();


protected:

  //	virtual void OnUpdateUI( wxUpdateUIEvent& event ) override;

	virtual void OnNotebookPageChanged( wxNotebookEvent& event ) override;

//    virtual void OnSetFocus( wxFocusEvent& aEvent ) override;

//    virtual void OnSize( wxSizeEvent& aEvent ) override;

private :
	void setFontSubChilds(wxWindowListNode* childNode, wxFont &wxf);

	void getSubChilds(std::vector<wxWindow*> & wlist, unsigned int &count);


};

#endif /* EESCHEMA_WIDGETS_PANEL_COMPONENT_LIBS_PICKER_BROWSER_H_ */

