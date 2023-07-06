//
// Created by Dardan Matias Berisha on 05/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_MAINFRAME_H
#define ELABORATO_PROGRAMMAZIONE_MAINFRAME_H


#include <wx/wx.h>
#include "ActivityLog.h"
#include <map>

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    std::map<std::string, std::vector<ActivityLog> > days;
    wxListBox* listBox;

    void OnAddButtonClick(wxCommandEvent& event);
};


#endif //ELABORATO_PROGRAMMAZIONE_MAINFRAME_H
