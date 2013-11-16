/*
    Copyright 2013 Dario Casalinuovo. All rights reserved.

    This file is part of Faber.

    Faber is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Faber is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Faber.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "SettingsView.h"

#include <GroupLayoutBuilder.h>
#include <TabView.h>

#include "FaberDefs.h"
#include "Keymap.h"


SettingsView::SettingsView()
	:
	BGroupView(B_HORIZONTAL, B_FOLLOW_LEFT)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	BTabView* tabView = new BTabView("");

	BTab* tab = new BTab();

	tabView->AddTab(new KeymapView(), tab);
	tab->SetLabel(B_TRANSLATE("Color layout"));

	BGroupLayoutBuilder(this)
		.Add(tabView)
	.End();

}


SettingsView::~SettingsView()
{

}


void
SettingsView::MessageReceived(BMessage* message)
{
	switch(message->what)
	{
		default:
			BView::MessageReceived(message);
	}
}
