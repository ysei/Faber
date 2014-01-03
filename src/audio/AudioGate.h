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

#ifndef _AUDIO_GATE_H
#define _AUDIO_GATE_H

#include <MediaDefs.h>
#include <MediaRoster.h>
#include <ObjectList.h>

#include "AudioEngine.h"
#include "MediaEndPoint.h"
#include "MediaGate.h"


class FilterHook {
public:
	void	(*hook)(float*, size_t, void*);
	void*	cookie;
};

class AudioGate : public MediaGate {
public:
									AudioGate();
			virtual					~AudioGate();

			static AudioGate*		Get();

			// TODO some of those methods should be moved
			// to MediaGate as they are very general.

			status_t 				Start();
			status_t				StartFrom(int64 position);
			status_t 				Stop();
			bool					IsStarted() const;

			void					SetLoop(bool loop);
			bool					Loop() const;

			void					SetPause(bool pause);
			bool					IsPaused() const;

			void 					SetFilterHook(FilterHook* hook);
			void 					RemoveFilterHook(FilterHook* hook);

			//void					RegisterWatchHandler(BHandler* handler);

			void					SetFramerate(float framerate);

			void 					SetFormat(media_format format);
			media_format 			Format() const;

protected:
			friend class			AudioEngine;

			// TODO should be them thread safe?
			const MediaEndPointMap&	GetInputs();
			const MediaEndPointMap&	GetOutputs();

			friend class			TracksManager;

			status_t				RegisterEndPoint(MediaEndPoint* point);
			status_t				UnregisterEndPoint(MediaEndPoint* point);

private:
			status_t				_InitNode();

			static AudioGate*		fInstance;
			media_format			fFormat;

			BObjectList<FilterHook> fHooksList;
			bool					fLoop;

			BMediaRoster*			fRoster;

			AudioEngine*			fAudioEngine;

			MediaEndPointMap*		fInputs;
			MediaEndPointMap*		fOutputs;
};

#endif
