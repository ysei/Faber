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

#include "CommandsServer.h"

#include <Application.h>
#include <Roster.h>

#include "EffectWindow.h"
#include "FaberDefs.h"

CommandsServer* CommandsServer::fInstance = NULL;


CommandsServer*
CommandsServer::Get()
{
	if (fInstance == NULL)
		fInstance = new CommandsServer();

	return fInstance;	
}


CommandsServer::CommandsServer()
	:
	BMessageFilter(B_ANY_DELIVERY, B_ANY_SOURCE)
{
}


filter_result
CommandsServer::Filter(BMessage* message, BHandler **target)
{
	filter_result result = B_DISPATCH_MESSAGE;
	bool skip = false;

	//message->PrintToStream();
	switch (message->what)
	{
		
		case FABER_ABOUT:
			WindowsManager::ShowAbout();
			skip = true;
		break;

		case FABER_OPEN_HOMEPAGE:
		{
			const char* homepage = FABER_HELP_HOMEPAGE;
			be_roster->Launch("text/html", 1,
				const_cast<char**>(&homepage));

			skip = true;
			break;
		}

		case FABER_SETTINGS:
			WindowsManager::Get()->ShowSettings();

			skip = true;
		break;

		case FABER_FILE_OPEN:
		{
			WindowsManager::GetOpenPanel()->Show();

			skip = true;
			break;
		}

		case FABER_EXPORT_PROJECT:
		{
			WindowsManager::GetExportPanel()->Show();

			skip = true;
			break;
		}

		case FABER_NEW_PROJECT:
		{
			app_info info;
			be_app->GetAppInfo(&info);
			be_roster->Launch(info.signature);

			skip = true;
			break;
		}

		case FABER_SAVE_PROJECT:
		{
			WindowsManager::GetSavePanel()->Show();

			skip = true;
			break;
		}

		case FABER_SAVE_AS_PROJECT:
		{
			WindowsManager::GetSavePanel()->Show();

			skip = true;
			break;
		}

		case FABER_UNDO:
		{

			break;
		}

		case FABER_REDO:
		{

			break;
		}

		case FABER_EFFECT_CALL:
		{
			FaberEffect* effect;
			message->FindPointer("effect", (void**)&effect);
			EffectWindow* win = new EffectWindow(effect);
			win->Show();

			skip = true;
			break;
		}

		case FABER_EFFECT_EXECUTE:
		{

			skip = true;		
			break;
		}

		case FABER_EFFECT_ABORT:
		{

			skip = true;
			break;
		}

	}

	if (skip == true)
		result = B_SKIP_MESSAGE;

	return result;
}



