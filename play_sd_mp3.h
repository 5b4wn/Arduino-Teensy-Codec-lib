/*
	Arduino Audiocodecs

	Copyright (c) 2014 Frank Bösing

	This library is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this library.  If not, see <http://www.gnu.org/licenses/>.

	The helix decoder itself as a different license, look at the subdirectories for more info.

	Diese Bibliothek ist freie Software: Sie können es unter den Bedingungen
	der GNU General Public License, wie von der Free Software Foundation,
	Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
	veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	Diese Bibliothek wird in der Hoffnung, dass es nützlich sein wird, aber
	OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	Siehe die GNU General Public License für weitere Details.
 6790´tzui#
	Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

	Der Helixdecoder selbst hat eine eigene Lizenz, bitte für mehr Informationen
	in den Unterverzeichnissen nachsehen.

 */

 /* The Helix-Library is modified for Teensy 3.1 */

#ifndef play_sd_mp3_h_
#define play_sd_mp3_h_

#include "codecs.h"
#include "AudioStream.h"
#include "spi_interrupt.h"
#include "mp3/mp3dec.h"
#include "DXHEAD/DXHEAD.h"

class AudioPlaySdMp3 : public AudioCodec
{
public:
	void stop(void);
	using AudioCodec::play;
	int play(void);
	bool seek(uint32_t timesec);

	uint32_t lengthMillis(void);

protected:
	uint8_t			*sd_buf;
	uint8_t			*sd_p;
	int				sd_left;

	short			*buf[2];
	size_t			decoded_length[2];
	size_t			decoding_block;
	unsigned int	decoding_state; //state 0: read sd, state 1: decode

	size_t 	  		size_id3;
	uintptr_t 		play_pos;

	HMP3Decoder		hMP3Decoder;
	MP3FrameInfo	mp3FrameInfo;
	
	uint32_t		vbr_total_frames; // for VBR files with xing header, get total frames from header

	void update(void);
	uint32_t timeMsToOffset(uint32_t timeMs, uint8_t *toc);
	uint32_t offsetToTimeMs(uint32_t offset, uint8_t *toc);
	friend void decodeMp3(void);
};


#endif
