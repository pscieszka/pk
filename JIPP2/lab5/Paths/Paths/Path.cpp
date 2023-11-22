
while (( $# != 0));do
if [ -f $1 ];then
    if [ -r "$1" ] && [ -w "$1" ] && [ -x "$1" ];;then
    echo "plik zwykly. prawa rwx"
    else
    echo "plik zwykly bez praw rwx"
    fi
elif [ -d $1 ];then
        if [ -r "$1" ] && [ -w "$1" ] && [ -x "$1" ];;then
    echo "katalog. prawa rwx"
    else
    echo "katalog bez praw rwx"
    fi
else
    echo "plik/katalog nie istnieje"
fi
shift
done