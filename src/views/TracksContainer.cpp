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

#include "TracksContainer.h"

#include "TrackView.h"
#include "AudioTrackView.h"


TracksContainer::TracksContainer()
	:
	BGroupView(B_VERTICAL, 0),
	fTrackViews(false)
{
	//GroupLayout()->SetInsets(10, 10, 10, 10);
}


TracksContainer::~TracksContainer()
{
}


void
TracksContainer::Invalidate()
{
	for (int i = 0; i < CountTracks(); i++)
		TrackAt(i)->Invalidate();

	BView::Invalidate();
}


void
TracksContainer::Pulse()
{
	for (int i = 0; i < CountTracks(); i++)
		TrackAt(i)->Pulse();
}


status_t
TracksContainer::AddTrack(TrackView* track, int32 index)
{
	GroupLayout()->AddView(track);
	return fTrackViews.AddItem(track, index);
}


status_t
TracksContainer::AddTrack(Track* track)
{
	if (track->IsAudio()) {
		AudioTrackView* trackView = new AudioTrackView("AudioTrack",
			(AudioTrack*) track);
		return AddTrack(trackView);
	}
	return B_ERROR;
}


status_t
TracksContainer::RemoveTrack(TrackView* track)
{
	GroupLayout()->RemoveView(track);
	return fTrackViews.RemoveItem(track);
}


TrackView*
TracksContainer::TrackAt(int32 index) const
{
	return fTrackViews.ItemAt(index);
}


int32
TracksContainer::CountTracks() const
{
	return fTrackViews.CountItems();
}


TrackView*
TracksContainer::CurrentTrack()
{
	
}


bool
TracksContainer::IsSelected()
{
	
}


bool
TracksContainer::HasChanged()
{
	return false;
}


void
TracksContainer::SelectAll()
{
	
}


void
TracksContainer::DeSelectAll()
{
	
}


void
TracksContainer::ZoomIn()
{
	
}


void
TracksContainer::ZoomOut()
{
	
}


void
TracksContainer::ZoomFull()
{
	
}


void
TracksContainer::ZoomSelection()
{
	
}


void
TracksContainer::SetDirty(bool dirty)
{
	for (int i = 0; i < CountTracks(); i++) {
		AudioTrackView* track = (AudioTrackView*) TrackAt(i);
		track->SetDirty(dirty);
	}
}
