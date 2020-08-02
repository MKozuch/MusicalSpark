#pragma once

#include "notes.h"

template <typename T> char sgn(T val){
    return (T(0) < val) - (val < T(0));
}

class ScaleGenerator{
public:
	enum Mode {Ionian, Dorian, Phrygian, Lydian, Mixolydian, Aeolian, Locrian};
	static constexpr auto Major = Ionian;
	static constexpr auto Minor = Aeolian;
	static constexpr byte intervals[] {  2, 2, 1, 2, 2, 2, 1};
	
	static constexpr Note::NoteName generateStep(Note::NoteName tonic, Mode mode, char step){
		int note = tonic;
		for(char i = 0; i<abs(step); ++i){
			byte kek = (7 + ((sgn(step) * i)%7) + byte(mode)) % 7;
			note += int(sgn(step)) * intervals[kek];
		}
		return Note::NoteName(note);
	} 	
};

