//
// Created by Dardan Matias Berisha on 06/07/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H
#define ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H

#include <wx/wx.h>
#include <wx/osx/dialog.h>
#include <map>
#include "ActivityLog.h"

class DialogAddDay : public wxDialog {
public:
    explicit DialogAddDay(const wxString& title, std::map<std::string, std::vector<ActivityLog> >& days);
private:
    void OnAddButtonClicked(wxCommandEvent& event);
    void OnCloseButtonClicked(wxCommandEvent& event);

    std::map<std::string, std::vector<ActivityLog> >* days;
    wxStaticText* text;
    wxTextCtrl* textCtrl;
};


#endif //ELABORATO_PROGRAMMAZIONE_DIALOGADDDAY_H
