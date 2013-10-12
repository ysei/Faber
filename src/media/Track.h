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

#ifndef _TRACK_H
#define _TRACK_H

#include <MediaDefs.h>
#include <String.h>


class Track {
public:
							Track();

	virtual bool			IsAudio() const = 0;
			//bool			IsMIDI() const;

	virtual const BString&	Name() const;
	virtual void 			SetName(const char* name);

	virtual float			Volume() const;
	virtual void			SetVolume(float volume);

	virtual void			SetBalance(float balance);
	virtual float			Balance() const;

	virtual bool			IsPlaying() const;
	virtual void			SetPlaying(bool playing);

	virtual void			SetRecording(bool solo);
	virtual bool			IsRecording() const;

	virtual void	 		MuteTrack(bool mute);
	virtual bool 			IsMute() const;

	virtual void			SetSolo(bool solo);
	virtual bool			IsSolo() const;

			void 			SetFormat(media_format format);
			media_format 	Format() const;

protected:
			media_format	fFormat;

private:

			bool			fMuted;
			bool			fSolo;
			bool			fRecording;
			bool			fPlaying;
			BString			fName;
			float			fVolume;
			float			fBalance;
};

#endif