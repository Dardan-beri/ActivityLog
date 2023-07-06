//
// Created by Dardan Matias Berisha on 05/07/23.
//

#include "MainFrame.h"
#include "DialogAddDay.h"

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);
    sideListBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(-1, 600 - 20), 0, nullptr, wxLB_SORT);

    wxButton* button = new wxButton(panel, wxID_ANY, "Add new day", wxPoint(sideListBox->GetPosition().x + sideListBox->GetSize().x + 10, 10), wxSize(100, 30));
    button->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClick, this);
}



void MainFrame::OnAddButtonClick(wxCommandEvent &event) {
    DialogAddDay* dialog = new DialogAddDay("Add Day", this);
    dialog->Center();
    dialog->Show(true);
}

bool MainFrame::addDay(std::string day) {
    if(days.find(day) == days.end()) {
        std::vector<ActivityLog> logs;
        days[day] = logs;
        sideListBox->AppendString(day);
        return true;
    }else{
        return false;
    }
}
