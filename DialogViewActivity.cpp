//
// Created by Dardan Matias Berisha on 08/07/23.
//

#include "DialogViewActivity.h"

DialogViewActivity::DialogViewActivity(wxString title, MainFrame *mainFrame, struct activity activity, wxString day):
    wxDialog(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(300, 150)),
    mainFrame(mainFrame),
    activity(activity),
    day(day){
    wxPanel* panel = new wxPanel(this);
    wxStaticText* descriptionText = new wxStaticText(panel, wxID_ANY, "Description: " + activity.description, wxPoint(10, 10));
    wxStaticText* startText = new wxStaticText(panel, wxID_ANY, "Start time: " + activity.start.toString(), wxPoint(10, 10 + descriptionText->GetSize().y + 10));
    wxStaticText* endText = new wxStaticText(panel, wxID_ANY,   "End time:   " + activity.end.toString(), wxPoint(10, startText->GetPosition().y + startText->GetSize().y + 10));
    wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", wxPoint(10, 10 + endText->GetPosition().y + endText->GetSize().y), wxSize(100, 30));
    wxButton* deleteButton = new wxButton(panel, wxID_ANY, "Delete", wxPoint(closeButton->GetPosition().x + closeButton->GetSize().x + 10, closeButton->GetPosition().y), wxSize(100, 30));

    deleteButton->Bind(wxEVT_BUTTON, &DialogViewActivity::OnDeleteButtonClicked, this);
    closeButton->Bind(wxEVT_BUTTON, &DialogViewActivity::OnCloseButtonClicked, this);
}

void DialogViewActivity::OnCloseButtonClicked(wxCommandEvent &event) {
    Close();
}

void DialogViewActivity::OnDeleteButtonClicked(wxCommandEvent &event) {
    mainFrame->removeActivityFromDay(day.ToStdString(), activity.title);
    Close();
}
