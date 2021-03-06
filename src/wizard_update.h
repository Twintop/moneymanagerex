/*******************************************************
 Copyright (C) 2014 Gabriele-V

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/
#pragma once

#include <wx/wizard.h>
#include <wx/frame.h>
#include "rapidjson/document.h"
#include "option.h"

using namespace rapidjson;

class mmUpdate
{
public:
    static void checkUpdates(bool bSilent, wxFrame *frame);

};

class mmUpdateWizard : public wxWizard
{
public:
    mmUpdateWizard(wxFrame *frame, const Document& json_releases, wxArrayInt new_releases);
    void RunIt(bool modal);

private:
    wxWizardPageSimple* page1;
    void LinkClicked(wxHtmlLinkEvent& WXUNUSED(event));
    void setControlEnable(int id);

    wxDECLARE_EVENT_TABLE();
};
//----------------------------------------------------------------------------

inline void mmUpdateWizard::setControlEnable(int id)
{
    wxWindow *win = wxWindow::FindWindowById(id);
    if (win) win->Hide();
}