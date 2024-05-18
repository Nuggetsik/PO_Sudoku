/***************************************************************
 * Name:      SudokuMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2024-05-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SudokuMain.h"
#include <wx/msgdlg.h>

#include <wx/log.h>

//(*InternalHeaders(SudokuFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


//(*IdInit(SudokuFrame)
const long SudokuFrame::ID_BUTTON1 = wxNewId();
const long SudokuFrame::ID_BUTTON2 = wxNewId();
const long SudokuFrame::ID_BUTTON3 = wxNewId();
const long SudokuFrame::ID_BUTTON4 = wxNewId();
const long SudokuFrame::ID_BUTTON5 = wxNewId();
const long SudokuFrame::ID_BUTTON6 = wxNewId();
const long SudokuFrame::ID_BUTTON7 = wxNewId();
const long SudokuFrame::ID_BUTTON8 = wxNewId();
const long SudokuFrame::ID_BUTTON9 = wxNewId();

const long SudokuFrame::ID_BUTTONS[9] = { ID_BUTTON1, ID_BUTTON2, ID_BUTTON3, ID_BUTTON4, ID_BUTTON5, ID_BUTTON6, ID_BUTTON7, ID_BUTTON8, ID_BUTTON9 };
//*)

BEGIN_EVENT_TABLE(SudokuFrame,wxFrame)
    //(*EventTable(SudokuFrame)
    //*)
END_EVENT_TABLE()

SudokuFrame::SudokuFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SudokuFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION | wxCLOSE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(720,720));
    SetMinSize(wxSize(720,720));
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            wxTextCtrl* textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(40 + col * 50, 40 + row * 50), wxSize(50, 50), 0, wxDefaultValidator, wxTextCtrlNameStr);
            textCtrls.push_back(textCtrl);
        }
    }
    wxButton* buttonsArray[] = {
        new wxButton(this, ID_BUTTON1, _("1"), wxPoint(80,552), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON1")),
        new wxButton(this, ID_BUTTON2, _("2"), wxPoint(160,552), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON2")),
        new wxButton(this, ID_BUTTON3, _("3"), wxPoint(240,552), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON3")),
        new wxButton(this, ID_BUTTON4, _("4"), wxPoint(320,552), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON4")),
        new wxButton(this, ID_BUTTON5, _("5"), wxPoint(400,552), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON5")),
        new wxButton(this, ID_BUTTON6, _("6"), wxPoint(120,624), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON6")),
        new wxButton(this, ID_BUTTON7, _("7"), wxPoint(200,624), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON7")),
        new wxButton(this, ID_BUTTON8, _("8"), wxPoint(280,624), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON8")),
        new wxButton(this, ID_BUTTON9, _("9"), wxPoint(360,624), wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON9"))
    };

    for (auto button : buttonsArray) {
        Buttons.push_back(button);
    }

    for(std::vector<wxTextCtrl*>::iterator iter = textCtrls.begin(); iter != textCtrls.end(); iter++)
        (*iter)->Connect(wxID_ANY, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(SudokuFrame::OnTextCtrl));

    for(std::vector<wxButton*>::iterator iter = Buttons.begin(); iter != Buttons.end(); iter++)
        (*iter)->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SudokuFrame::OnButtonClicked));


    //*)
}

SudokuFrame::~SudokuFrame()
{
    //(*Destroy(SudokuFrame)
    //*)
}

void SudokuFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SudokuFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void SudokuFrame::OnButtonClicked(wxCommandEvent& event)
{
    wxLogMessage("Button clicked"); // Добавляем сообщение для отладки
    int buttonId = event.GetId();

    for (size_t i = 0; i < Buttons.size(); ++i) {
        if (buttonId == ID_BUTTONS[i]) {
            // Индекс кнопки найден, добавляем значение к соответствующему wxTextCtrl
            num = wxString::Format("%d", static_cast<int>(i + 1));

            break;
        }
    }
}


void SudokuFrame::OnTextCtrl(wxCommandEvent& event)
{
   // Изменяем текст только если значение num не пусто
    if (!num.IsEmpty()) {
        // Устанавливаем значение в текущий wxTextCtrl
        wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(event.GetEventObject());
        if (textCtrl) {
            textCtrl->SetValue(num);
        }
    }
}
