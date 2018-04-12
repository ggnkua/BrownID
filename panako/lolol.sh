#### Chromaprint

#for i in `find ./sndh_lf/ -name "* *.sndh"`; do echo "$i"; ../sc68-code/sc68/sc68 "$i" -q --rate 44100 --wav -o lolol.wav; ./fpcalc -length 50000 -text -plain lolol.wav>"$i.id"; done

#find . -type f -name '*.sndh' -print0 | while IFS= read -r -d '' i; do echo "$i"; ../sc68-code/sc68/sc68 "$i" -q --rate 44100 --wav -o lolol.wav; ./fpcalc -length 50000 -raw -plain lolol.wav>"$i.id"; sed -i -e "s/,/\r\n/gI" "$i.id"; done

#rm lolol.wav

#### Panako

#find . -type f -name '*.sndh' -print0 | while IFS= read -r -d '' i; do echo "$i"; ../sc68-code/sc68/sc68 "$i" -q --rate 44100 --wav -o $i.wav; java -jar /opt/panako/panako.jar store $i.wav; rm $i.wav; done

set -e

#find . -type f -name '*.sndh' -print0 | while IFS= read -r -d '' i; do
find . -type f -name '*.sndh' -print0 | while IFS= read -r -d '' i; do
    echo -------- "$i"
    outfname=`echo "$i.wav" | tr / _`
    ../sc68-code/sc68/sc68 "$i" --memory 22 --quiet --rate 44100 --wav -o "$outfname"
    FILESIZE=$(stat --printf="%s" "$outfname")
    echo "$outfname size $FILESIZE"
    if [ "$FILESIZE" -lt 1323000 ]; then
        echo "$outfname is smaller than 30 seconds - skipping"
    else
        java -jar /opt/panako/panako.jar store "$outfname"
    fi
    rm "$outfname"
done

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

