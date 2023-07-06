//
// Created by Dardan Matias Berisha on 06/07/23.
//

#include "DialogAddDay.h"

DialogAddDay::DialogAddDay(const wxString &title, std::map<std::string, std::vector<ActivityLog> > &days):
    wxDialog(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200)), days(&days) {

    wxPanel* panel = new wxPanel(this);
    text = new wxStaticText(panel, wxID_ANY, "Insert the date you want to keep track of", wxPoint(10, 10));
    textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 10 + text->GetSize().y + 10), wxSize(200, -1));
    wxButton* addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(10, 137), wxSize(100, 30));
    wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", wxPoint(10 + addButton->GetSize().x + 10, 137), wxSize(100, 30));

}

void DialogAddDay::OnAddButtonClicked(wxCommandEvent &event) {
    auto str = text->GetLabel();

}

void DialogAddDay::OnCloseButtonClicked(wxCommandEvent &event) {
    Close();
}
