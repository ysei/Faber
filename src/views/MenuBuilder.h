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

#ifndef _MENUBUILDER_H_
#define _MENUBUILDER_H_

#include <Menu.h>
#include <MenuBar.h>
#include <PopUpMenu.h>

#include "DefaultKeymap.h"
#include "FaberDefs.h"


class MenuBuilder
{
public:
							MenuBuilder();
	virtual					~MenuBuilder();

	static MenuBuilder*		Get();

	BMenuBar*				BuildMainMenuBar();

	BMenu*					BuildFileMenu();
	BMenu*					BuildRecentMenu();
	BMenu*					BuildEditMenu();
	BMenu*					BuildTracksMenu();
	BMenu*					BuildEffectsMenu();
	BMenu*					BuildGenerateMenu();
	BMenu*					BuildEngineMenu();
	BMenu*					BuildProjectMenu();
	BMenu*					BuildHelpMenu();

	BPopUpMenu*				BuildTrackContextualMenu(BView* target);

	//BMenu*					BuildLiveNodesMenu(node_type type);

	static void				UpdateMenu();

private:
	BMenu*					_BuildMenu(KeyBind* bind);

	BPopUpMenu*				_BuildPopUpMenu(KeyBind* bind,
								BView* target = NULL);

	BMenuItem*				_BuildMenuItem(uint32 message, const char* label);

	static MenuBuilder*		fInstance;
	FaberShortcut*			fKeyBind;
};

#endif	// _MenuBuilder_H_
