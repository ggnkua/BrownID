#for i in `find ./sndh_lf/ -name "* *.sndh"`; do echo "$i"; ../sc68-code/sc68/sc68 "$i" -q --rate 44100 --wav -o lolol.wav; ./fpcalc -length 50000 -text -plain lolol.wav>"$i.id"; done

find . -type f -name '*.sndh' -print0 | while IFS= read -r -d '' i; do echo "$i"; ../sc68-code/sc68/sc68 "$i" -q --rate 44100 --wav -o lolol.wav; ./fpcalc -length 50000 -text -plain lolol.wav>"$i.id"; done

#  -h --help           Print this message and exit (incremental)
#  -v --version        Print sc68 version x.y.z and #licence and exit
#  -D --debug-list     Print debug categories and exit
#  -C --config         Open configuration dialog and exit
#  -I --info           Open file info dialog and exit
#  -v --verbose        Print more info
#  -q --quiet          Do not display music info
#  -r --rate=<val>     Sampling rate (in hz)
#  -t --track=<val>    Choose track to play ["all"|"def"|"sel"|#]
#  -l --loop=<val>     Track loop ["def"|"inf"|loop-#]
#  -o --output=<URI>   Set output
#  -c --stdout         Output raw to stdout (--output=stdout://)
#  -n --null           No output (--output=null://)
#  -w --wav            Riff Wav output. Use in combination with -o.
#  -m --memory=<val>   68k memory to allocate (2^<val> bytes)
#

#  -format NAME   Set the input format name
#  -rate NUM      Set the sample rate of the input audio
#  -channels NUM  Set the number of channels in the input audio
#  -length SECS   Restrict the duration of the processed input audio (default 120)
#  -chunk SECS    Split the input audio into chunks of this duration
#  -algorithm NUM Set the algorigthm method (default 2)
#  -overlap       Overlap the chunks slightly to make sure audio on the edges is fingerprinted
#  -ts            Output UNIX timestamps for chunked results, useful when fingerprinting real-time audio stream
#  -raw           Output fingerprints in the uncompressed format
#  -json          Print the output in JSON format
#  -text          Print the output in text format
#  -plain         Print the just the fingerprint in text format
#  -version       Print version information
