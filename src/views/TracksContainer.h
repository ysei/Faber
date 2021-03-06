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

#ifndef _TRACKS_CONTAINER
#define _TRACKS_CONTAINER

#include <GroupLayout.h>
#include <GroupView.h>
#include <ScrollBar.h>

#include "TrackView.h"


class TracksContainer : public BGroupView
{
public:
						TracksContainer();
	virtual 			~TracksContainer();

	void				MessageReceived(BMessage* message);

	void				SetFrames(int64 duration);

	bigtime_t			Duration() const;
	int64				Frames() const;

	void				SetStart(int64 frame);
	void				SetEnd(int64 frame);

	int32 				CountTracks() const;
	TrackView*			TrackAt(int32 index) const;
	TrackView*			TrackByID(uint32 id);

	uint32				IndexToID(int32 index);
	int32				IDToIndex(uint32 id);

	status_t 			AddTrack(TrackView* track, int32 index = 0);
	status_t			AddTrack(Track* track);

	status_t			RemoveTrack(int32 index);
	status_t			RemoveTrack(TrackView* track = NULL);

	void				SelectAll();
	void				UnselectAll();

	void				MoveUp(int32 id);
	void				MoveDown(int32 id);

	TrackView*			CurrentFocus();
	TrackViewList&		SelectedTracks();

	bool 				HasChanged();

	void	 			MuteAllTracks(bool mute);
	void				ReorderTracks(int reorder);

	void				CopyAndSilence();
	void				Copy();
	void				Cut();
	void				Paste();
	void				Clear();

	void				ZoomIn();
	void				ZoomOut();
	void				ZoomFull();
	void				ZoomSelection();

	int32				CalcZoomLevel() const;

	// NOTE this will not update the scroll bar
	// don't use it, use the following method instead.
	void				UpdateTracksScroll(float newValue);

	/*void				SetHorizontalScroll(float newValue);
	void				SetVerticalScroll(float newValue);*/

private:

	BGroupView*			fView;
	BGroupLayout*		fLayout;
	TrackViewList		fTrackViews;

	BScrollBar*			fVerticalScroll;
	BScrollBar*			fHorizontalScroll;

	int64				fStart;
	int64				fEnd;
	int64				fDuration;
};

#endif
