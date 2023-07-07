//
// Created by Dardan Matias Berisha on 05/07/23.
//

#include "MainFrame.h"
#include "DialogAddDay.h"

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title), lastSelectedDay("") {
    wxPanel* panel = new wxPanel(this);
    sideListBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(-1, 600 - 20), 0, nullptr, wxLB_SORT);
    wxButton* dayButton = new wxButton(panel, wxID_ANY, "Add new day", wxPoint(sideListBox->GetPosition().x + sideListBox->GetSize().x + 10, 10), wxSize(100, 30));
    wxButton* activityButton = new wxButton(panel, wxID_ANY, "Add new activity", wxPoint(dayButton->GetPosition().x + dayButton->GetSize().x + 10, 10), wxSize(-1, 30));

    dayButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClick, this);
    activityButton->Bind(wxEVT_BUTTON, &MainFrame::OnActivityButtonClick, this);
    mainListBox = new wxListBox(panel, wxID_ANY, wxPoint(sideListBox->GetPosition().x + sideListBox->GetSize().x + 10, 10 + dayButton->GetSize().y + 10), wxSize(320, 540), 0, nullptr, wxLB_SORT);
    sideListBox->Bind(wxEVT_LISTBOX, &MainFrame::OnSideListBoxClicked, this);
}



void MainFrame::OnAddButtonClick(wxCommandEvent &event) {
    DialogAddDay* dialog = new DialogAddDay("Add Day", this);
    dialog->Center();
    dialog->Show(true);
}

bool MainFrame::addDay(const std::string day) {
    if(days.find(day) == days.end()) {
        ActivityLog logs;
        days[day] = logs;
        sideListBox->AppendString(day);
        return true;
    }else{
        return false;
    }
}

void MainFrame::OnSideListBoxClicked(wxCommandEvent &event) {
    mainListBox->Clear();
    auto str = event.GetString();
    lastSelectedDay = str;
    auto log = days[str.ToStdString()];
    for(auto &i : log.getActivities()){
        mainListBox->AppendString(i.title + " " + i.description);
    }

}

void MainFrame::OnActivityButtonClick(wxCommandEvent &event) {
    if(!lastSelectedDay.empty()){
        //TODO: Add dialog to add activity
    } else
        wxMessageBox("You must select a day first");

}
