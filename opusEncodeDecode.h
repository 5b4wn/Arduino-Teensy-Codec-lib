/*
  Arduino Audiocodecs
  Copyright (c) 2020 jcj83429
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
  Diese Bibliothek ist freie Software: Sie können es unter den Bedingungen
  der GNU General Public License, wie von der Free Software Foundation,
  Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
  veröffentlichten Version, weiterverbreiten und/oder modifizieren.
  Diese Bibliothek wird in der Hoffnung, dass es nützlich sein wird, aber
  OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
  Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
  Siehe die GNU General Public License für weitere Details.
  Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
  Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#ifndef opusEncodeDecode.h

//	The #define statement defines this file as the myFirstLibrary
//	Header File so that it can be included within the source file.                                           
#define opusEncodeDecode.h

#include "Arduino.h"
#include "codecs.h"
#include "opus/include/opus.h"

class opus
{
      public:
        void encoderInit(void);
        void decoderInit(void);
        void encodeOpus (void);
        void decodeOpus(void);
    

      protected:

	       OpusDecoder     *opusDecoder = NULL;
         OpusEncoder     *opusEncoder = NULL;

}


#endif


