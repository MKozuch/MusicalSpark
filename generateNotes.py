notes = {
    -9: 'C',
    -8: 'Cs',
    -7: 'D',
    -6: 'Ds',
    -5: 'E',
    -4: 'F',
    -3: 'Fs',
    -2: 'G',
    -1: 'Gs',
     0: 'A',
     1: 'As',
     2: 'B'
}
aliases = {
     1: 'Bb',
    -8: 'Db',
    -6: 'Eb',
    -3: 'Gb',
    -1: 'Ab'    
}

startOctave = 2;
endOctave = 10;
tuneFreq = 440;
tuneOctave = 4;

print("#pragma once")
print()
print("namespace Note {")

noteDict = dict()

for octave in range(startOctave, endOctave):
    AFreq = tuneFreq * 2**(octave-tuneOctave)
    for j in notes:
        freq = AFreq * (196/185)**j
        noteDict["{}{}".format(notes[j], str(octave))] = int(freq)

print("enum NoteName{{{}}};".format(", ".join(["{}={}".format(key, i) for i, key in enumerate(noteDict)])))
print("int noteValues[] = {{{}}};".format(", ".join([str(value) for key, value in noteDict.items()])))

for octave in range(startOctave, endOctave):
    for j in aliases:
        print("constexpr auto {0}{2} = {1}{2};".format(aliases[j], notes[j], octave))

baseOctave = 7
if(startOctave <= baseOctave):
    for j in notes:
        print("constexpr auto {0} = {0}{1};".format(notes[j], baseOctave))
    for j in aliases:
        print("constexpr auto {0} = {0}{1};".format(aliases[j], baseOctave))
print("}")

