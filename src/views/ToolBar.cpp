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

#include "ToolBar.h"

#include <LayoutBuilder.h>
#include <StringView.h>

#include "DurationView.h"
#include "FaberDefs.h"
#include "IconButton.h"


ToolBar::ToolBar()
	:
	BView("ToolBar", B_HORIZONTAL)
{
	fOutputPeakView = new PeakView("OutputPeakView", true, false);
	fOutputPeakView->SetExplicitMaxSize(BSize(150, 20));

	DurationView* durationView = new DurationView();

	fOutputPeakView->SetExplicitSize(BSize(150, 13));


	fTransportWidget = new TransportWidget();
	fToolsWidget = new ToolsWidget();

	BLayoutBuilder::Group<>(this, B_HORIZONTAL, 0)
			.AddGlue()
			.Add(fTransportWidget)
			.AddStrut(15.0f)

			.AddGroup(B_VERTICAL, 0.5f)
				.Add(fOutputPeakView)
				.Add(durationView)
			.End()

			.AddGlue()

			.Add(fToolsWidget)
			.AddStrut(2.0f)
		.End();

}


ToolBar::~ToolBar()
{
}


void
ToolBar::Update()
{
}
