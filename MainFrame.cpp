//
// Created by Dardan Matias Berisha on 05/07/23.
//

#include "MainFrame.h"
#include "DialogAddDay.h"

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this);
    listBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(-1, 600-20));

    wxButton* button = new wxButton(panel, wxID_ANY, "Add", wxPoint(listBox->GetPosition().x + listBox->GetSize().x + 10, 10), wxSize(100, 30));
    button->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClick, this);
}

void MainFrame::OnAddButtonClick(wxCommandEvent &event) {
    DialogAddDay* dialog = new DialogAddDay("Add Day", days);
    dialog->Center();
    dialog->ShowModal();
    listBox->AppendString("Hello");
}
